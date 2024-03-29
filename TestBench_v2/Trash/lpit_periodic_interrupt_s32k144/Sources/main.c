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

/* ###################################################################
**     Filename    : main.c
**     Project     : lpit_periodic_interrupt_s32k144
**     Processor   : S32K144_100
**     Version     : Driver 01.00
**     Compiler    : GNU C Compiler
**     Date/Time   : 2015-07-03, 14:05, # CodeGen: 0
**     Abstract    :
**         Main module.
**         This module contains user's application code.
**     Settings    :
**     Contents    :
**         No public methods
**
** ###################################################################*/
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
#include "lpit1.h"
#include "lpi2c1.h"
#include "osif1.h"
#include "dmaController1.h"
#if CPU_INIT_CONFIG
  #include "Init_Config.h"
#endif

volatile int exit_code = 0;
/* User includes (#include below this line is not maintained by Processor Expert) */

#include <stdint.h>
#include <stdbool.h>

/* This define configures led pin and port for use with EVB, to make it run on
 * FVB you need to comment the following line.
 */
#define EVB

#ifdef EVB
	#define LED0_PIN_INDEX  15U
	#define LED_GPIO_PORT	PTD
#else
	#define LED0_PIN_INDEX	0U
	#define LED_GPIO_PORT	PTC
#endif

/* LPIT channel used */
#define LPIT_CHANNEL	    0UL
#define LPIT_Channel_IRQn   LPIT0_Ch0_IRQn


/* Definition of the data transfer size */
#define TRANSFER_SIZE 2u


void delay(volatile int cycles)
{
    /* Delay function - do nothing for a number of cycles */
    while(cycles--);
}

// Pressure measured by the HDIB002AUY8P5 sensor through I2C communication in milibars.
	uint16_t pressure_hdi_i2c;

/* Declaration of the LPI2C transfer buffer */
   uint8_t buffer[TRANSFER_SIZE];

volatile bool gbI2CDone = false;

/*!
 * @brief: LPIT interrupt handler.
 * 	       When an interrupt occurs clear channel flag and toggle LED0
 */
void LPIT_ISR(void)
{
	/* Clear LPIT channel flag */
	LPIT_DRV_ClearInterruptFlagTimerChannels(INST_LPIT1, (1 << LPIT_CHANNEL));




	gbI2CDone = true;

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
	// Number of counts read by the sensor
		uint16_t counts_hdi; // Would it be better to send a float?


	    /* Allocate memory for the LPI2C driver state structure */
	    lpi2c_master_state_t lpi2c1MasterState;


	    /* Variable used for the loop that initializes the data buffer */
	    uint16_t i;


  /*** Processor Expert internal initialization. DON'T REMOVE THIS CODE!!! ***/
  #ifdef PEX_RTOS_INIT
    PEX_RTOS_INIT();                 /* Initialization of the selected RTOS. Macro is defined by the RTOS component. */
  #endif
  /*** End of Processor Expert internal initialization.                    ***/

    /* Initialize and configure clocks
	 * 	-	configure source clocks, PCC for LED port and LPIT instance
	 */
    CLOCK_SYS_Init(g_clockManConfigsArr,   CLOCK_MANAGER_CONFIG_CNT,
                   g_clockManCallbacksArr, CLOCK_MANAGER_CALLBACK_CNT);
    CLOCK_SYS_UpdateConfiguration(0U, CLOCK_MANAGER_POLICY_AGREEMENT);

	/* Initialize pins
	 *	-	Setup pin used for LED(used as GPIO)
	 */
    PINS_DRV_Init(NUM_OF_CONFIGURED_PINS, g_pin_mux_InitConfigArr);

	/* Initialize LPIT instance 0
	 *	-	Reset and enable peripheral
	 */
    LPIT_DRV_Init(INST_LPIT1, &lpit1_InitConfig);
    /* Initialize LPIT channel 0 and configure it as a periodic counter
     * which is used to generate an interrupt every second.
     */
    LPIT_DRV_InitChannel(INST_LPIT1, LPIT_CHANNEL, &lpit1_ChnConfig0);

    /* Install LPIT_ISR as LPIT interrupt handler */
    INT_SYS_InstallHandler(LPIT_Channel_IRQn, &LPIT_ISR, (isr_t *)0);

    /* Set LED pin direction as output */
    PINS_DRV_SetPinsDirection(LED_GPIO_PORT, (1 << LED0_PIN_INDEX));

    /* Turn off LED0 */
    PINS_DRV_SetPins(LED_GPIO_PORT, (1 << LED0_PIN_INDEX));

    /* Start LPIT0 channel 0 counter */
    LPIT_DRV_StartTimerChannels(INST_LPIT1, (1 << LPIT_CHANNEL));

    /* Peripherals Initialization is complete, now the program will wait for
     * LPIT interrupt.
     */


    /* Initialize LPI2C Master configuration
         *  - Slave address 0x01
         *  - Fast operating mode, 400 KHz SCL frequency
         *  -   See LPI2C components for configuration details
         */
        LPI2C_DRV_MasterInit(INST_LPI2C1, &lpi2c1_MasterConfig0, &lpi2c1MasterState);

       //I2C address of the sensor (0x78)
       const uint16_t address_ = 120;
       LPI2C_DRV_MasterSetSlaveAddr(INST_LPI2C1, address_, false);

       // Parameters to compute the actual pressure based on the number of counts
          //Pressure range
          const uint64_t Pmax = 2000; //mbar
          const uint64_t Pmin = 0;

          //Digital range
          const uint64_t Out_max_d = 29490;
          const uint64_t Out_min_d = 3277;

          // Check on the datasheet the technical name of this variable
          uint64_t S;

          S = (Out_max_d - Out_min_d)/(Pmax-Pmin);

          	// Main Loop
         while(1)
           {
   			/* Toggle LED0 */


        	 if(gbI2CDone){
        	 /* Clear the buffer to prepare it for the next operation */


        			/* Request data from the bus slave */
        		    LPI2C_DRV_MasterReceiveDataBlocking(INST_LPI2C1, buffer, TRANSFER_SIZE, true, 1u);


        	    // Compute the pressure based on the number of counts read
        	    counts_hdi = (buffer[0]<<8)|buffer[1];
        	    pressure_hdi_i2c = (counts_hdi - Out_min_d)/S + Pmin;
        	    gbI2CDone = false;

        	    for (i = 0u; i < TRANSFER_SIZE; i++)
        	           	    {
        	           	        buffer[i] = 0u;
        	           	    }

        	 }
         }


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
