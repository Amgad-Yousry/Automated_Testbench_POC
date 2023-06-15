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
**     Project     : lpi2c_master_s32k144
**     Processor   : S32K144_100
**     Version     : Driver 01.00
**     Compiler    : GNU C Compiler
**     Date/Time   : 2016-08-31, 14:05, # CodeGen: 0
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
#include "lpi2c1.h"
#include "dmaController1.h"
#if CPU_INIT_CONFIG
  #include "Init_Config.h"
#endif

volatile int exit_code = 0;
/* User includes (#include below this line is not maintained by Processor Expert) */

#include <stdint.h>
#include <stdbool.h>

/* Definition of the data transfer size */
#define TRANSFER_SIZE 2U
void delay(volatile int cycles)
{
    /* Delay function - do nothing for a number of cycles */
    while(cycles--);
}
//* Declaration of the LPI2C transfer buffer */
uint8_t buffer[TRANSFER_SIZE];
uint8_t send[2] = {0x10, 0X00};
uint16_t counts_SMF;
	uint16_t flow_SMF;
int main(void)
{
	/*necessary datasheet values for flow calculations*/
	const uint64_t SFLOW = 100;
	const uint64_t OFFSET = 32768;
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
     *  - Configure system clocks and dividers
     *  - Configure LPI2C clock gating
     *  -   see clock manager component for details
     */
    CLOCK_SYS_Init(g_clockManConfigsArr, CLOCK_MANAGER_CONFIG_CNT,
                   g_clockManCallbacksArr, CLOCK_MANAGER_CALLBACK_CNT);
    CLOCK_SYS_UpdateConfiguration(0U, CLOCK_MANAGER_POLICY_AGREEMENT);

    /* Initialize pins
     *  - Configure LPI2C pins
     *  -   See PinSettings component for more info
     */
       PINS_DRV_Init(NUM_OF_CONFIGURED_PINS, g_pin_mux_InitConfigArr);

    /* Initialize LPI2C Master configuration
     *  - Slave address 0x40
     *  - Fast operating mode, 400 KHz SCL frequency
     *  - PTA3:SCL , PTA2: SDA
     *  - data request command = 0x1000
     *
     *
     *
     *
     */

       lpi2c_master_user_config_t lpi2c1_MasterConfig0 = {
      			  .slaveAddress = 0x40,
      			  .is10bitAddr = false,
      			  .operatingMode = LPI2C_FAST_MODE,
      			  .baudRate = 200000,
      			  .transferType = LPI2C_USING_INTERRUPTS,
      			  .dmaChannel = NULL,
      			  .masterCallback = NULL,
      			  .callbackParam = NULL,
      	  };






  	    /* Declaration of the LPI2C transfer buffer */
  	    uint8_t buffer[3];
  	    uint8_t SEND[2] = {0x10, 0x00};




    LPI2C_DRV_MasterInit(INST_LPI2C1, &lpi2c1_MasterConfig0, &lpi2c1MasterState);
    LPI2C_DRV_MasterSendDataBlocking(INST_LPI2C1, send,2U, true, OSIF_WAIT_FOREVER);

    while(true)
    {

    for (i = 0u; i < 2U; i++)
    {
        buffer[i] = 0u;
    }
    /* Request data from the bus slave */
    LPI2C_DRV_MasterReceiveDataBlocking(INST_LPI2C1,buffer,3U, false, OSIF_WAIT_FOREVER);
    delay(5000000);
    counts_SMF = (buffer[0]<<8)|buffer[1];
    flow_SMF = (counts_SMF - OFFSET)/SFLOW;
        }
    /* End of the driver example */
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
