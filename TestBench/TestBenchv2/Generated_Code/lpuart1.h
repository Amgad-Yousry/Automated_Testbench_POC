/* ###################################################################
**     This component module is generated by Processor Expert. Do not modify it.
**     Filename    : lpuart1.h
**     Project     : TestBenchv2
**     Processor   : S32K144_100
**     Component   : lpuart
**     Version     : Component SDK_S32K14x_07, Driver 01.00, CPU db: 3.00.000
**     Repository  : SDK_S32K14x_07
**     Compiler    : GNU C Compiler
**     Date/Time   : 2023-06-06, 11:42, # CodeGen: 18
**     Abstract    :
**
**     Contents    :
**         LPUART_DRV_Init                - status_t LPUART_DRV_Init(uint32 instance,lpuart_state_t *...
**         LPUART_DRV_Deinit              - status_t LPUART_DRV_Deinit(uint32 instance);
**         LPUART_DRV_InstallRxCallback   - uart_callback_t LPUART_DRV_InstallRxCallback(uint32 instance,uart_callback_t...
**         LPUART_DRV_InstallTxCallback   - uart_callback_t LPUART_DRV_InstallTxCallback(uint32 instance,uart_callback_t...
**         LPUART_DRV_SendDataBlocking    - status_t LPUART_DRV_SendDataBlocking(uint32 instance,const uint8 *...
**         LPUART_DRV_SendDataPolling     - void LPUART_DRV_SendDataPolling(uint32 instance,const uint8 * txBuff,uint32...
**         LPUART_DRV_SendData            - status_t LPUART_DRV_SendData(uint32 instance,const uint8 * txBuff,uint32...
**         LPUART_DRV_GetTransmitStatus   - status_t LPUART_DRV_GetTransmitStatus(uint32 instance,uint32 * bytesRemaining);
**         LPUART_DRV_AbortSendingData    - status_t LPUART_DRV_AbortSendingData(uint32 instance);
**         LPUART_DRV_ReceiveDataBlocking - status_t LPUART_DRV_ReceiveDataBlocking(uint32 instance,uint8 * rxBuff,uint32...
**         LPUART_DRV_ReceiveDataPolling  - status_t LPUART_DRV_ReceiveDataPolling(uint32 instance,uint8 * rxBuff,uint32...
**         LPUART_DRV_ReceiveData         - status_t LPUART_DRV_ReceiveData(uint32 instance,uint8 * rxBuff,uint32 rxSize);
**         LPUART_DRV_GetReceiveStatus    - status_t LPUART_DRV_GetReceiveStatus(uint32 instance,uint32 * bytesRemaining);
**         LPUART_DRV_AbortReceivingData  - status_t LPUART_DRV_AbortReceivingData(uint32 instance);
**         LPUART_DRV_SetBaudRate         - status_t LPUART_DRV_SetBaudRate(uint32_t instance,uint32_t desiredBaudRate);
**         LPUART_DRV_GetBaudRate         - void LPUART_DRV_GetBaudRate(uint32_t instance, uint32_t * configuredBaudRate);
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
** @file lpuart1.h
** @version 01.00
** @brief
**
*/
/*!
**  @addtogroup lpuart1_module lpuart1 module documentation
**  @{
*/

/* MODULE lpuart1
 *
 * @page misra_violations MISRA-C:2012 violations
 *
 * @section [global]
 * Violates MISRA 2012 Advisory Rule 2.5, Global macro not referenced.
 * The macros are defined to be used by application code.
 */

#ifndef lpuart1_H
#define lpuart1_H

/* Include inherited beans */
#include "clockMan1.h"
#include "dmaController1.h"
#include "osif1.h"
#include "Cpu.h"

/*! @brief Device instance number */
#define INST_LPUART1 (1U)

/*! Driver state structure */
extern lpuart_state_t lpuart1_State;

/*! @brief Configuration declaration */
extern const lpuart_user_config_t lpuart1_InitConfig_Gasboard;

#endif  /* ifndef lpuart1_H */
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
