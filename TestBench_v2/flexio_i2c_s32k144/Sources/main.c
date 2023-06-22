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
**     Project     : flexio_i2c_s32k144
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
#include "flexio_i2c.h"
#include "lpi2c1.h"
#include "dmaController1.h"
#include "osif1.h"
#if CPU_INIT_CONFIG
  #include "Init_Config.h"
#endif

volatile int exit_code = 0;
/* User includes (#include below this line is not maintained by Processor Expert) */

#include <stdint.h>
#include <stdbool.h>

/* Declare transfer size */
#define TRANSFER_SIZE 8U

/* Define master and slave buffers */
uint8_t slaveBuffer[TRANSFER_SIZE];
uint8_t masterBuffer[TRANSFER_SIZE];

/*!
 *  @brief LPI2C Slave Callback
 *
 *  @param [in] instance   LPI2C instance number
 *  @param [in] slaveEvent Event received on the I2C bus
 *  @param [in] userData   User defined data that is passed to the callback
 *  @return None
 *
 *  @details This function will be called by LPI2C interrupt handler and it
 *  will assign the buffer for TX or RX events.
 *  If an error event occurs, it will abort the current transfer.
 */
void lpi2c1_SlaveCallback0(uint8_t instance,lpi2c_slave_event_t slaveEvent,void *userData)
{
    /* Casting userData to void in order to avoid warning as the parameter is not used */
    (void)userData;

    /* Depending on the event received, set the buffers or abort the transfer */
    switch(slaveEvent)
    {
        case LPI2C_SLAVE_EVENT_RX_REQ:
            /*
             * If the bus master requests data, then set the destination RX buffer
             * and accepted transfer size
             */
            LPI2C_DRV_SlaveSetRxBuffer(instance, slaveBuffer, TRANSFER_SIZE);
            break;
        case LPI2C_SLAVE_EVENT_TX_REQ:
            /*
             * If the bus master sends data, then set the source TX buffer
             * and accepted transfer size
             */
            LPI2C_DRV_SlaveSetTxBuffer(instance, slaveBuffer, TRANSFER_SIZE);
            break;
        case LPI2C_SLAVE_EVENT_TX_EMPTY:
        case LPI2C_SLAVE_EVENT_RX_FULL:
            /*
             * If the TX buffer is empty or the RX buffer is full, abort the current
             * transfer.
             */
            LPI2C_DRV_SlaveAbortTransferData(instance);
            break;
        case LPI2C_SLAVE_EVENT_STOP:
            /*
             * This case is used when a stop condition is on the bus. Because
             * the example does not handle this case there is no action taken.
             */
            break;
    }
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
    /* Allocate memory for LPI2C driver internal structure */
    lpi2c_slave_state_t lpi2cSlaveState;
    /* Allocate the memory necessary for the FlexIO state structures */
    flexio_i2c_master_state_t i2cMasterState;
    flexio_device_state_t flexIODeviceState;
    /* Variable that is used to initialize the buffers */
    uint8_t cnt;
    volatile bool isTransferOk[2] = {true, true};

  /*** Processor Expert internal initialization. DON'T REMOVE THIS CODE!!! ***/
  #ifdef PEX_RTOS_INIT
    PEX_RTOS_INIT();                 /* Initialization of the selected RTOS. Macro is defined by the RTOS component. */
  #endif
  /*** End of Processor Expert internal initialization.                    ***/

    /* Initialize and configure clocks
     *  -   Setup system clocks, dividers
     *  -   Configure FlexIO clock, LPI2C
     *  -   see clock manager component for more details
     */
    CLOCK_SYS_Init(g_clockManConfigsArr, CLOCK_MANAGER_CONFIG_CNT,
                        g_clockManCallbacksArr, CLOCK_MANAGER_CALLBACK_CNT);
    CLOCK_SYS_UpdateConfiguration(0U, CLOCK_MANAGER_POLICY_AGREEMENT);

    /* Initialize pins
     *  -   Init FlexIO, LPI2C pins
     *  -   See PinSettings component for more info
     */
    PINS_DRV_Init(NUM_OF_CONFIGURED_PINS, g_pin_mux_InitConfigArr);

    /* Initialize LPI2C instance as bus slave */
    LPI2C_DRV_SlaveInit(INST_LPI2C1, &lpi2c1_SlaveConfig0, &lpi2cSlaveState);

    /* Init FlexIO device */
    FLEXIO_DRV_InitDevice(INST_FLEXIO_I2C, &flexIODeviceState);

    /* Initialize FlexIO I2C driver as bus master */
    FLEXIO_I2C_DRV_MasterInit(INST_FLEXIO_I2C, &flexio_i2c_MasterConfig0, &i2cMasterState);

    /* Initialize master and slave buffers for master send sequence */
    for(cnt = 0; cnt < sizeof(masterBuffer); cnt++)
    {
        masterBuffer[cnt] = cnt;
        slaveBuffer[cnt]  = 0U;
    }

    /* Send data to the slave */
    FLEXIO_I2C_DRV_MasterSendDataBlocking(&i2cMasterState, masterBuffer, sizeof(masterBuffer), true, 10UL);

    /* Check if transfer is completed with no errors */
    for (cnt = 0U; cnt < TRANSFER_SIZE; cnt++)
    {
        /* If the values are not equal, break the loop and set isTransferOk to false */
        if((masterBuffer[cnt] != slaveBuffer[cnt]))
        {
            isTransferOk[0] = false;
            break;
        }
    }

    /* Initialize master and slave buffers for master receive sequence */
    for(cnt = 0; cnt < sizeof(masterBuffer); cnt++)
    {
        masterBuffer[cnt] = 0U;
        slaveBuffer[cnt]  = TRANSFER_SIZE - cnt;
    }

    /* Request data from slave */
    FLEXIO_I2C_DRV_MasterReceiveDataBlocking(&i2cMasterState, masterBuffer, sizeof(masterBuffer), true, 10UL);

    /* Check if transfer is completed with no errors */
    for (cnt = 0U; cnt < TRANSFER_SIZE; cnt++)
    {
        /* If the values are not equal, break the loop and set isTransferOk to false */
        if((masterBuffer[cnt] != slaveBuffer[cnt]))
        {
            isTransferOk[1] = false;
            break;
        }
    }

    /* Cast isTransferOk to avoid "set but not used" warnings */
    (void)isTransferOk;

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
