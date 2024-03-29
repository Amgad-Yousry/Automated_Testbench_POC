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
#include "LPSPI_MPR.h"


#include "dmaController1.h"
#if CPU_INIT_CONFIG
  #include "Init_Config.h"
#endif
#define BUFFER_SIZE 2U
#define TIMEOUT 50U
#define PTC15  15 // Sensor power supply
volatile int exit_code = 0;
/* User includes (#include below this line is not maintained by Processor Expert) */

#include <stdint.h>
#include <stdbool.h>

// Pressure measured by the HDIB002AUY8P5 sensor through SPI communication in milibars.
float gfPressMPR;
float gfTempMPR;

uint8_t masterDataReceive [7u];

// Number of counts read by the sensor
uint64_t countsPressMPR;
uint64_t countsTempMPR;
uint16_t countsPressMPR_aux;

double pressure = 0; // pressure reading [bar, psi, kPa, etc.]

double percentage = 0; // holds percentage of full scale dat


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
    lpspi_state_t masterState;

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



  /* Initialize LPSPI0 */
  LPSPI_DRV_MasterInit(LPSPI_MPR, &masterState, &LPSPI_MPR_MasterConfig0);


  // Delays between the clock and the chip enable
  LPSPI_DRV_MasterSetDelay(0U, 100U, 100U, 100U);

  // Initialize data buffers

      uint8_t masterDataSend[3] = {0xAA, 0x00, 0x00};
      uint8_t masterDataDiscard[3] = {0x00, 0x00, 0x00};
     uint8_t TX_Buffer_MPR[7] = {0xF0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

    //  uint8_t TX_Buffer_MPR[4] = {0xF0, 0x00, 0x00, 0x00};

   //   LPSPI_DRV_MasterTransferBlocking(0U, &masterDataSend, &masterDataDiscard, 3u, TIMEOUT);


     double press_counts = 0; // digital pressure reading [counts]
     double temp_counts = 0; // digital temperature reading [counts]

     double temperature = 0; // temperature reading in deg C
     double outputmax = 15099494; // output at maximum pressure [counts]
     double outputmin = 1677722; // output at minimum pressure [counts]
     double pmax = 2.5; // maximum value of pressure range [bar, psi, kPa, etc.]
     double pmin = 0; // minimum value of pressure range [bar, psi, kPa, etc.]

     PINS_DRV_SetPinDirection(PTE, 4U, 1U);

     PINS_DRV_WritePin(PTE, 4U, true);
     delay(100000);


     PINS_DRV_WritePin(PTE, 4U, 0);
     delay(100000000);


     PINS_DRV_WritePin(PTE, 4U, true);




      //delay(30000);

  // Main loop
  while(1)
  {

	//
	  LPSPI_DRV_MasterTransferBlocking(0U, &masterDataSend, &masterDataDiscard, 3u, TIMEOUT);
	      	  delay(10000000);



     /* Store the channel result into a local variable slaveDataSend*/
     sts=  LPSPI_DRV_MasterTransferBlocking(0U, &TX_Buffer_MPR, &masterDataReceive, 7U, TIMEOUT);

     delay(100000);

     // Compute the pressure based on the number of counts read
	  countsPressMPR = masterDataReceive[3] + masterDataReceive[2]*256 + masterDataReceive[1]*65536;
	  countsTempMPR = masterDataReceive[6] + masterDataReceive[5]*256 + masterDataReceive[4]*65536;

	 // countsPressMPR_aux = (countsPressMPR & 0x7FFF); // Remove the most significant bit

	  // Transform the counts in actual pressure
	  gfPressMPR = ((float)countsPressMPR / 16777215) * 100;
	  gfTempMPR = ((float)countsTempMPR * 200 / 16777215) - 50;

	  pressure = ((countsPressMPR - outputmin) * (pmax - pmin)) / (outputmax - outputmin) + pmin;

	  delay(30000);

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
