/* ###################################################################
**     This component module is generated by Processor Expert. Do not modify it.
**     Filename    : flexio_uart_TX.c
**     Project     : flexio_uart_s32k144
**     Processor   : S32K144_100
**     Component   : flexio_uart
**     Version     : Component SDK_S32K14x_07, Driver 01.00, CPU db: 3.00.000
**     Repository  : SDK_S32K14x_07
**     Compiler    : GNU C Compiler
**     Date/Time   : 2023-06-09, 11:58, # CodeGen: 0
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
** @file flexio_uart_TX.c
** @version 01.00
*/
/*!
**  @addtogroup flexio_uart_TX_module flexio_uart_TX module documentation
**  @{
*/

/* MODULE flexio_uart_TX.
 *
 * @page misra_violations MISRA-C:2012 violations
 *
 * @section [global]
 * Violates MISRA 2012 Advisory Rule 8.7, External variable could be made static.
 * The external variables will be used in other source files in application code.
 */

#include "flexio_uart_TX.h"


const flexio_uart_user_config_t flexio_uart_TX_Config0 = {
  .driverType = FLEXIO_DRIVER_TYPE_INTERRUPTS,
  .direction = FLEXIO_UART_DIRECTION_TX,
  .baudRate = 115200U,
  .bitCount = 8U,
  .dataPin = 2U,
  .callback = NULL,
  .callbackParam = NULL,
  .dmaChannel = 255,
};


/* END flexio_uart_TX. */

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
