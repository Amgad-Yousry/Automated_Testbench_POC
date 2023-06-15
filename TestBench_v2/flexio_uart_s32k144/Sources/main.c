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
**     Project     : flexio_uart_s32k144
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
#include "flexio_uart_TX.h"
#include "osif1.h"
#include "flexio_uart_RX.h"
#include "dmaController1.h"
#if CPU_INIT_CONFIG
  #include "Init_Config.h"
#endif

volatile int exit_code = 0;
/* User includes (#include below this line is not maintained by Processor Expert) */

#include <stdint.h>
#include <stdbool.h>
#include <string.h>

#define WELCOME_MSG ("Hello World\r\n")

volatile bool g_dataReceived;

uint8_t rxBuffer;
uint8_t txBuffer;
flexio_device_state_t flexIODeviceState;
flexio_uart_state_t   uartStateTX;
flexio_uart_state_t   uartStateRX;

void flexio_uart_RX_Callback0(void *driverState, uart_event_t event, void *userData)
{
    (void)userData;
    (void)driverState;

    if (event == UART_EVENT_RX_FULL)
    {
    	/* Copy data received into the TX buffer */
    	txBuffer = rxBuffer;
        /* Send received data */
        FLEXIO_UART_DRV_SendData(&uartStateTX, &txBuffer, 1U);
        /* Set new RX buffer */
        FLEXIO_UART_DRV_SetRxBuffer(&uartStateRX, &rxBuffer, 1UL);
    }
}

/*!
  \brief The main function for the project.
  \details The startup initialization sequence is the following:
 * - __start (startup asm routine)
 * - main()
*/
int main(void)
{

/*** Processor Expert internal initialization. DON'T REMOVE THIS CODE!!! ***/
#ifdef PEX_RTOS_INIT
    PEX_RTOS_INIT();                 /* Initialization of the selected RTOS. Macro is defined by the RTOS component. */
#endif
/*** End of Processor Expert internal initialization.                    ***/

    /* Initialize and configure clocks
     *  -   Setup system clocks, dividers
     *  -   Configure FlexIO clock
     *  -   see clock manager component for more details
     */
    CLOCK_SYS_Init(g_clockManConfigsArr, CLOCK_MANAGER_CONFIG_CNT,
                   g_clockManCallbacksArr, CLOCK_MANAGER_CALLBACK_CNT);
    CLOCK_SYS_UpdateConfiguration(0U, CLOCK_MANAGER_POLICY_AGREEMENT);

    /* Initialize pins
     *  -   Init FlexIO UART RX and TX pins
     *  -   See PinSettings component for more info
     */
    PINS_DRV_Init(NUM_OF_CONFIGURED_PINS, g_pin_mux_InitConfigArr);

    /* Init the FLEXIO device */
    FLEXIO_DRV_InitDevice(INST_FLEXIO_UART_TX, &flexIODeviceState);

    /* Init the FlexIO UART driver
     *  - 115200 baudrate
     *  - TX only
     *  - 8 bit per frame
     *  - Interrupt based
     */
     FLEXIO_UART_DRV_Init(INST_FLEXIO_UART_TX, &flexio_uart_TX_Config0, &uartStateTX);

    /* Init the FlexIO UART driver
     *  - 115200 baudrate
     *  - RX only
     *  - 8 bit per frame
     *  - Interrupt based
     */
     FLEXIO_UART_DRV_Init(INST_FLEXIO_UART_RX, &flexio_uart_RX_Config0, &uartStateRX);

     FLEXIO_UART_DRV_SendDataBlocking(&uartStateTX, (uint8_t * )WELCOME_MSG, strlen(WELCOME_MSG), 100U);
     FLEXIO_UART_DRV_ReceiveData(&uartStateRX, &rxBuffer, 1U);

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

