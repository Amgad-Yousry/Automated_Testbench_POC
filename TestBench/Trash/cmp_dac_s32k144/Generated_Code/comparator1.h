/* ###################################################################
**     This component module is generated by Processor Expert. Do not modify it.
**     Filename    : comparator1.h
**     Project     : cmp_dac_s32k144
**     Processor   : S32K144_100
**     Component   : cmp
**     Version     : Component SDK_S32K14x_07, Driver 01.00, CPU db: 3.00.000
**     Repository  : SDK_S32K14x_07
**     Compiler    : GNU C Compiler
**     Date/Time   : 2023-05-24, 14:53, # CodeGen: 0
**     Contents    :
**         CMP_DRV_Reset                   - status_t CMP_DRV_Reset(const uint32_t instance);
**         CMP_DRV_GetInitConfigAll        - status_t CMP_DRV_GetInitConfigAll(cmp_module_t * config);
**         CMP_DRV_Init                    - status_t CMP_DRV_Init(const uint32_t instance,const cmp_module_t *const config);
**         CMP_DRV_GetConfigAll            - status_t CMP_DRV_GetConfigAll(const uint32_t instance,cmp_module_t *const...
**         CMP_DRV_GetInitConfigDAC        - status_t CMP_DRV_GetInitConfigDAC(cmp_dac_t * config);
**         CMP_DRV_ConfigDAC               - status_t CMP_DRV_ConfigDAC(const uint32_t instance,const cmp_dac_t * config);
**         CMP_DRV_GetDACConfig            - status_t CMP_DRV_GetDACConfig(const uint32_t instance,cmp_dac_t *const config);
**         CMP_DRV_GetInitConfigMUX        - status_t CMP_DRV_GetInitConfigMUX(cmp_anmux_t * config);
**         CMP_DRV_ConfigMUX               - status_t CMP_DRV_ConfigMUX(const uint32_t instance,const cmp_anmux_t * config);
**         CMP_DRV_GetMUXConfig            - status_t CMP_DRV_GetMUXConfig(const uint32_t instance,cmp_anmux_t *const...
**         CMP_DRV_GetInitTriggerMode      - status_t CMP_DRV_GetInitTriggerMode(cmp_trigger_mode_t * config);
**         CMP_DRV_ConfigTriggerMode       - status_t CMP_DRV_ConfigTriggerMode(const uint32_t instance,const...
**         CMP_DRV_GetTriggerModeConfig    - status_t CMP_DRV_GetTriggerModeConfig(const uint32_t...
**         CMP_DRV_GetOutputFlags          - status_t CMP_DRV_GetOutputFlags(const uint32_t instance,cmp_output_trigger_t...
**         CMP_DRV_ClearOutputFlags        - status_t CMP_DRV_ClearOutputFlags(const uint32_t instance);
**         CMP_DRV_GetInputFlags           - status_t CMP_DRV_GetInputFlags(const uint32_t instance,cmp_ch_list_t * flags);
**         CMP_DRV_ClearInputFlags         - status_t CMP_DRV_ClearInputFlags(const uint32_t instance);
**         CMP_DRV_GetInitConfigComparator - status_t CMP_DRV_GetInitConfigComparator(cmp_comparator_t * config);
**         CMP_DRV_ConfigComparator        - status_t CMP_DRV_ConfigComparator(const uint32_t instance,const...
**         CMP_DRV_GetComparatorConfig     - status_t CMP_DRV_GetComparatorConfig(const uint32_t instance,cmp_comparator_t...
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
** @file comparator1.h
** @version 01.00
*/
/*!
**  @addtogroup comparator1_module comparator1 module documentation
**  @{
*/
#ifndef comparator1_H
#define comparator1_H

/* MODULE comparator1.
 *
 * @page misra_violations MISRA-C:2012 violations
 *
 * @section [global]
 * Violates MISRA 2012 Advisory Rule 2.5, Global macro not referenced.
 * The global macro will be used in function call of the module.
 */

/* MODULE comparator1. */
/*! @brief Device instance number */
#define INST_COMPARATOR1 0U
/* Include inherited beans */
#include "Cpu.h"


#endif
/* ifndef __comparator1_H */
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

    extern const cmp_module_t cmp_general_config;
