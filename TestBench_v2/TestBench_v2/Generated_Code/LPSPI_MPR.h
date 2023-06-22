/* ###################################################################
**     This component module is generated by Processor Expert. Do not modify it.
**     Filename    : LPSPI_MPR.h
**     Project     : TestBench_v2
**     Processor   : S32K144_100
**     Component   : lpspi
**     Version     : Component 1.0.0, Driver 01.00, CPU db: 3.00.000
**     Repository  : SDK_S32K14x_09
**     Compiler    : GNU C Compiler
**     Date/Time   : 2023-06-21, 17:27, # CodeGen: 68
**     Contents    :
**         LPSPI_DRV_MasterInit              - status_t LPSPI_DRV_MasterInit(uint32_t instance,lpspi_state_t *...
**         LPSPI_DRV_MasterDeinit            - status_t LPSPI_DRV_MasterDeinit(uint32_t instance);
**         LPSPI_DRV_MasterSetDelay          - status_t LPSPI_DRV_MasterSetDelay(uint32_t instance,uint32_t...
**         LPSPI_DRV_MasterConfigureBus      - status_t LPSPI_DRV_MasterConfigureBus(uint32_t instance,const...
**         LPSPI_DRV_MasterTransferBlocking  - status_t LPSPI_DRV_MasterTransferBlocking(uint32_t instance,const uint8_t *...
**         LPSPI_DRV_MasterTransfer          - status_t LPSPI_DRV_MasterTransfer(uint32_t instance,const uint8_t *...
**         LPSPI_DRV_MasterGetTransferStatus - status_t LPSPI_DRV_MasterGetTransferStatus(uint32_t instance,uint32_t *...
**         LPSPI_DRV_MasterAbortTransfer     - status_t LPSPI_DRV_MasterAbortTransfer(uint32_t instance);
**         LPSPI_DRV_SlaveInit               - status_t LPSPI_DRV_SlaveInit(uint32_t instance,lpspi_state_t *...
**         LPSPI_DRV_SlaveDeinit             - status_t LPSPI_DRV_SlaveDeinit(uint32_t instance);
**         LPSPI_DRV_SlaveTransferBlocking   - status_t LPSPI_DRV_SlaveTransferBlocking(uint32_t instance,const uint8_t *...
**         LPSPI_DRV_SlaveTransfer           - status_t LPSPI_DRV_SlaveTransfer(uint32_t instance,const uint8_t *...
**         LPSPI_DRV_SlaveAbortTransfer      - status_t LPSPI_DRV_SlaveAbortTransfer(uint32_t instance);
**         LPSPI_DRV_SlaveGetTransferStatus  - status_t LPSPI_DRV_SlaveGetTransferStatus(uint32_t instance,uint32_t *...
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
** @file LPSPI_MPR.h
** @version 01.00
*/
/*!
**  @addtogroup LPSPI_MPR_module LPSPI_MPR module documentation
**  @{
*/
#ifndef LPSPI_MPR_H
#define LPSPI_MPR_H
/* MODULE LPSPI_MPR. */

/* MODULE LPSPI_MPR.
 *
 * @page misra_violations MISRA-C:2012 violations
 *
 * @section [global]
 * Violates MISRA 2012 Advisory Rule 8.7, External variable could be made static.
 * The external variable will be used in other source file that user initialize
 * to use this module.
 *
 * @section [global]
 * Violates MISRA 2012 Advisory Rule 2.5, Global macro not referenced.
 * The global macro will be used in function call of the module.
 */

/* Include inherited beans */
#include "clockMan1.h"
#include "dmaController1.h"
#include "Cpu.h"


/*! @brief Device instance number */
#define LPSPI_MPR (0U)
/*! @brief State structure for LPSPI0 */
extern lpspi_state_t LPSPI_MPRState;

/*! @brief Define external callbacks for master devices */
/*! @brief Master configuration declaration */
extern const lpspi_master_config_t LPSPI_MPR_MasterConfig;


#endif
/* ifndef __LPSPI_MPR_H */
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
