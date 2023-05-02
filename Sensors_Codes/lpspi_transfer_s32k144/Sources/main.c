/*
 * Copyright (c) 2015 - 2016 , Freescale Semiconductor, Inc.
 * Copyright 2016-2017 NXP
 * All rights reserved.
 *
 * THIS SOFTWARE IS PROVIDED BY NXP "AS IS" AND ANY EXPRESSED OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL NXP OR ITS CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
 * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING
 * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
 * THE POSSIBILITY OF SUCH DAMAGE.
 */
/*!
** @file main.c
** @version 01.00
** @brief
**         Main module.
**         This module contains user's application code.
*/
/*!
**  @addtogroup main_module main module documentation
**  @{
*/
/* MODULE main */


/* Including needed modules to compile this module/procedure */
#include "Cpu.h"
#include "clockMan1.h"
#include "pin_mux.h"
#include "Send.h"
#include "Receive.h"
#include "adConv1.h"
#include "PWM.h"
#include "osif1.h"
#include "dmaController1.h"
#if CPU_INIT_CONFIG
  #include "Init_Config.h"
#endif
#define BUFFER_SIZE 2U
#define TIMEOUT 100U
#define PTC15  15 // Sensor power supply
volatile int exit_code = 0;
/* User includes (#include below this line is not maintained by Processor Expert) */

#include <stdint.h>
#include <stdbool.h>

// Pressure measured by the HDIB002AUY8P5 sensor through SPI communication in milibars.
float pressure_hdtdm_spi;

// Number of counts read by the sensor
uint16_t counts_hdtm;
uint16_t counts_hdtm_aux;

// Is it really necessary?
void WDOG_disable (void){
	WDOG->CNT=0xD928C520;     /*Unlock watchdog*/
	WDOG->TOVAL=0x0000FFFF;   /*Maximum timeout value*/
	WDOG->CS = 0x00002100;    /*Disable watchdog*/
}

// Delay function - do nothing for a number of cycles
void delay(volatile int cycles)
{
    while(cycles--);
}

// Compute the actual pressure based on the number of counts from the sensors
float pressure_calc (volatile int sensor, uint16_t counts)
{
	//Pressure range
	uint64_t Pmax; //mbar
	uint64_t Pmin;

	//Digital range
	uint64_t Out_max_d;
	uint64_t Out_min_d;

	switch (sensor)
	{
	// Parameters to compute the actual pressure based on the number of counts
	case 1: // HDI

	  //Pressure range
	  Pmax = 2000; //mbar
	  Pmin = 0;

	  //Digital range
	  Out_max_d = 29490;
	  Out_min_d = 3277;

	  break;

	case 2: // HTDM
		  //Pressure range
		  Pmax = 100; //mbar
		  Pmin = 0;

		  //Digital range
		  Out_max_d = 29491;
		  Out_min_d = 3277;

	break;

	}
	float S;
	float P;
	S = (Out_max_d - Out_min_d)/(Pmax-Pmin);
	P = (counts - Out_min_d)/S + Pmin;
	return P;
}


/*!
  \brief The main function for the project.
  \details The startup initialization sequence is the following:
 * - __start (startup asm routine)
 * - __init_hardware()
 * - main()
 *   - PE_low_level_init()
 *     - Common_Init()
 *     - Peripherals_Init()
*/
int main(void)
{
  /* Write your local variable definition here */

  /*** Processor Expert internal initialization. DON'T REMOVE THIS CODE!!! ***/
  #ifdef PEX_RTOS_INIT
    PEX_RTOS_INIT();                 /* Initialization of the selected RTOS. Macro is defined by the RTOS component. */
  #endif
  /*** End of Processor Expert internal initialization.                    ***/

    // SPI communication variables
    ftm_state_t ftmStateStruct;
    lpspi_state_t masterState;

    // SPI communication buffers
    uint8_t masterDataSend[BUFFER_SIZE];
    uint8_t masterDataReceive[BUFFER_SIZE];

    // Status of the SPI data trasfer
    status_t sts;

   // Disable watchdog to make the changes on the SPI Master
    WDOG_disable();


    /* Initialize and configure clocks
     *     -   see clock manager component for details
     */
     CLOCK_SYS_Init(g_clockManConfigsArr, CLOCK_MANAGER_CONFIG_CNT,
                           g_clockManCallbacksArr, CLOCK_MANAGER_CALLBACK_CNT);
     CLOCK_SYS_UpdateConfiguration(0U, CLOCK_MANAGER_POLICY_AGREEMENT);


  // Initialize the pins configured on the Routing tab
  PINS_DRV_Init(NUM_OF_CONFIGURED_PINS, g_pin_mux_InitConfigArr);

  // Define the SPI Master Parameters
  lpspi_master_config_t MasterConfigSPI = {
	 .bitsPerSec = 100000U, 				// baudrate
	 .whichPcs = LPSPI_PCS0,				// Instance defined on the Routing tab
	 .pcsPolarity = LPSPI_ACTIVE_LOW, 		// CS enable
	 .isPcsContinuous = true,				// Desactivate CS between the bytes
	 .bitcount = 8U,						// Number of bits -- I tried with 16 to read only once, but it didn't work
	 .lpspiSrcClk = 8000000U,				// Source clock of the LPSPI peripheral
	 .clkPhase = LPSPI_CLOCK_PHASE_1ST_EDGE,// Readings on the raising edge
	 .clkPolarity = LPSPI_SCK_ACTIVE_HIGH,  // The clock stays high when it is not active
	 .lsbFirst = false,						// Bit order
	 .transferType = LPSPI_USING_INTERRUPTS,// I tried with DMA, but it didn't work
  };

  // Power off and on the sensor before starting the loop in order to avoid synchronization problems while pressing the button "rst"
  PINS_DRV_WritePin(PTC,PTC15,0);
  delay(50000);
  PINS_DRV_WritePin(PTC,PTC15,1);

  /* Initialize LPSPI0 */
  LPSPI_DRV_MasterInit(0U, &masterState, &MasterConfigSPI);

  // Delays between the clock and the chip enable
  LPSPI_DRV_MasterSetDelay(0U, 10U, 1U, 1U);

  /* Variable used for the loop that initializes the data buffer */
  uint16_t i;

  // Initialize data buffers
  for (i = 0u; i < BUFFER_SIZE; i++)
  {
	  masterDataSend[i] = 255u; 		// Always send high (datasheet specification)
	  masterDataReceive[i] = 0u;
  }

  // Main loop
  while(1)
  {
     /* Store the channel result into a local variable slaveDataSend*/
     sts=  LPSPI_DRV_MasterTransferBlocking(0U, &masterDataSend, &masterDataReceive, BUFFER_SIZE, TIMEOUT);

     delay(50000);

     // Compute the pressure based on the number of counts read
	  counts_hdtm = (masterDataReceive[1] <<8)|masterDataReceive[0]; // Swipe the bytes
	  counts_hdtm_aux = (counts_hdtm & 0x7FFF); // Remove the most significant bit

	  // Transform the counts in actual pressure
	  pressure_hdtdm_spi = pressure_calc (2, counts_hdtm_aux); // Available in FreeMaster

	  // Clear the buffer
	  for (i = 0u; i < BUFFER_SIZE; i++)
		  {
			  masterDataReceive[i] = 0u;
		  }


  }
  /* Write your code here */
  /* For example: for(;;) { } */

  /*** Don't write any code pass this line, or it will be deleted during code generation. ***/
  /*** RTOS startup code. Macro PEX_RTOS_START is defined by the RTOS component. DON'T MODIFY THIS CODE!!! ***/
  #ifdef PEX_RTOS_START
    PEX_RTOS_START();                  /* Startup of the selected RTOS. Macro is defined by the RTOS component. */
  #endif
  /*** End of RTOS startup code.  ***/
  /*** Processor Expert end of main routine. DON'T MODIFY THIS CODE!!! ***/
  for(;;) {
    if(exit_code != 0) {
      break;
    }
  }
  return exit_code;
  /*** Processor Expert end of main routine. DON'T WRITE CODE BELOW!!! ***/
} /*** End of main routine. DO NOT MODIFY THIS TEXT!!! ***/

/* END main */
/*!
** @}
*/
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.1 [05.21]
**     for the Freescale S32K series of microcontrollers.
**
** ###################################################################
*/
