/* ###################################################################
**     This component module is generated by Processor Expert. Do not modify it.
**     Filename    : flexio_uart_RX.h
**     Project     : flexio_uart_s32k144
**     Processor   : S32K144_100
**     Component   : flexio_uart
**     Version     : Component SDK_S32K14x_07, Driver 01.00, CPU db: 3.00.000
**     Repository  : SDK_S32K14x_07
**     Compiler    : GNU C Compiler
**     Date/Time   : 2023-06-09, 11:58, # CodeGen: 0
**     Contents    :
**         FLEXIO_DRV_InitDevice               - status_t FLEXIO_DRV_InitDevice(uint32_t instance,flexio_device_state_t *...
**         FLEXIO_DRV_DeinitDevice             - status_t FLEXIO_DRV_DeinitDevice(uint32_t instance);
**         FLEXIO_DRV_Reset                    - status_t FLEXIO_DRV_Reset(uint32_t instance);
**         FLEXIO_UART_DRV_Init                - status_t FLEXIO_UART_DRV_Init(uint32_t instance,const...
**         FLEXIO_UART_DRV_Deinit              - status_t FLEXIO_UART_DRV_Deinit(flexio_uart_state_t * state);
**         FLEXIO_UART_DRV_SetConfig           - status_t FLEXIO_UART_DRV_SetConfig(flexio_uart_state_t * state,uint32_t...
**         FLEXIO_UART_DRV_GetBaudRate         - status_t FLEXIO_UART_DRV_GetBaudRate(flexio_uart_state_t * state,uint32_t *...
**         FLEXIO_UART_DRV_SendDataBlocking    - status_t FLEXIO_UART_DRV_SendDataBlocking(flexio_uart_state_t * state,const...
**         FLEXIO_UART_DRV_SendData            - status_t FLEXIO_UART_DRV_SendData(flexio_uart_state_t * state,const uint8_t *...
**         FLEXIO_UART_DRV_ReceiveDataBlocking - status_t FLEXIO_UART_DRV_ReceiveDataBlocking(flexio_uart_state_t *...
**         FLEXIO_UART_DRV_ReceiveData         - status_t FLEXIO_UART_DRV_ReceiveData(flexio_uart_state_t * state,uint8_t *...
**         FLEXIO_UART_DRV_GetStatus           - status_t FLEXIO_UART_DRV_GetStatus(flexio_uart_state_t * state,uint32_t *...
**         FLEXIO_UART_DRV_TransferAbort       - status_t FLEXIO_UART_DRV_TransferAbort(flexio_uart_state_t * state);
**         FLEXIO_UART_DRV_SetRxBuffer         - status_t FLEXIO_UART_DRV_SetRxBuffer(flexio_uart_state_t * state,uint8_t *...
**         FLEXIO_UART_DRV_SetTxBuffer         - status_t FLEXIO_UART_DRV_SetTxBuffer(flexio_uart_state_t * state,const...
**
**     Copyright 1997 - 2015 Freescale Semiconductor, Inc.
**     Copyright 2016-2017 NXP
**     All Rights Reserved.
**     
**     THIS SOFTWARE IS PROVIDED BY NXP "AS IS" AND ANY EXPRESSED OR
**     IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
**     OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
**     IN NO EVENT SHALL NXP OR ITS CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
**     INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
**     (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
**     SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
**     HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
**     STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING
**     IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
**     THE POSSIBILITY OF SUCH DAMAGE.
** ###################################################################*/
/*!
** @file flexio_uart_RX.h
** @version 01.00
*/
/*!
**  @addtogroup flexio_uart_RX_module flexio_uart_RX module documentation
**  @{
*/
#ifndef flexio_uart_RX_H
#define flexio_uart_RX_H

/* MODULE flexio_uart_RX
 *
 * @page misra_violations MISRA-C:2012 violations
 *
 * @section [global]
 * Violates MISRA 2012 Advisory Rule 2.5, Global macro not referenced.
 * The macros are defined to be used by application code.
 */

/* Include inherited beans */
#include "clockMan1.h"
#include "osif1.h"
#include "dmaController1.h"
#include "Cpu.h"
#include "flexio_uart_driver.h"

/*! @brief Device instance number */
#define INST_FLEXIO_UART_RX 0

/*! @brief UART configuration declaration */
extern const flexio_uart_user_config_t flexio_uart_RX_Config0;


/*! @brief User callback external declaration */
extern void flexio_uart_RX_Callback0(void *driverState, uart_event_t event, void *userData);

#endif
/* ifndef flexio_uart_RX_H */
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
