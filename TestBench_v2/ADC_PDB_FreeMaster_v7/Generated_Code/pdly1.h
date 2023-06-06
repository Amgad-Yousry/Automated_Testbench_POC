/* ###################################################################
**     This component module is generated by Processor Expert. Do not modify it.
**     Filename    : pdly1.h
**     Project     : ADC_PDB_FreeMaster_v7
**     Processor   : S32K144_100
**     Component   : pdb
**     Version     : Component SDK_S32K14x_07, Driver 01.00, CPU db: 3.00.000
**     Repository  : SDK_S32K14x_07
**     Compiler    : GNU C Compiler
**     Date/Time   : 2023-06-02, 17:27, # CodeGen: 1
**     Contents    :
**         PDB_DRV_Init                          - void PDB_DRV_Init(const uint32_t instance, const pdb_timer_config_t *...
**         PDB_DRV_Deinit                        - void PDB_DRV_Deinit(const uint32_t instance);
**         PDB_DRV_SoftTriggerCmd                - void PDB_DRV_SoftTriggerCmd(const uint32_t instance);
**         PDB_DRV_GetTimerValue                 - uint32_t PDB_DRV_GetTimerValue(const uint32_t instance);
**         PDB_DRV_GetTimerIntFlag               - bool PDB_DRV_GetTimerIntFlag(const uint32_t instance);
**         PDB_DRV_ClearTimerIntFlag             - void PDB_DRV_ClearTimerIntFlag(const uint32_t instance);
**         PDB_DRV_LoadValuesCmd                 - void PDB_DRV_LoadValuesCmd(const uint32_t instance);
**         PDB_DRV_SetTimerModulusValue          - void PDB_DRV_SetTimerModulusValue(const uint32_t instance, const uint32_t...
**         PDB_DRV_SetValueForTimerInterrupt     - void PDB_DRV_SetValueForTimerInterrupt(const uint32_t instance, const...
**         PDB_DRV_ConfigAdcPreTrigger           - void PDB_DRV_ConfigAdcPreTrigger(const uint32_t instance, const uint32_t chn,...
**         PDB_DRV_GetAdcPreTriggerFlags         - uint32_t PDB_DRV_GetAdcPreTriggerFlags(const uint32_t instance, const...
**         PDB_DRV_ClearAdcPreTriggerFlags       - void PDB_DRV_ClearAdcPreTriggerFlags(const uint32_t instance, const uint32_t...
**         PDB_DRV_GetAdcPreTriggerSeqErrFlags   - uint32_t PDB_DRV_GetAdcPreTriggerSeqErrFlags(const uint32_t instance, const...
**         PDB_DRV_ClearAdcPreTriggerSeqErrFlags - void PDB_DRV_ClearAdcPreTriggerSeqErrFlags(const uint32_t instance, const...
**         PDB_DRV_SetAdcPreTriggerDelayValue    - void PDB_DRV_SetAdcPreTriggerDelayValue(const uint32_t instance, const...
**         PDB_DRV_SetCmpPulseOutEnable          - void PDB_DRV_SetCmpPulseOutEnable(const uint32_t instance, const uint32_t...
**         PDB_DRV_SetCmpPulseOutDelayForHigh    - void PDB_DRV_SetCmpPulseOutDelayForHigh(const uint32_t instance, const...
**         PDB_DRV_SetCmpPulseOutDelayForLow     - void PDB_DRV_SetCmpPulseOutDelayForLow(const uint32_t instance, const...
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
** @file pdly1.h
** @version 01.00
*/
/*!
**  @addtogroup pdly1_module pdly1 module documentation
**  @{
*/
#ifndef pdly1_H
#define pdly1_H
/* MODULE pdly1. */

/**
 * @page misra_violations MISRA-C:2012 violations
 *
 * @section [global]
 * Violates MISRA 2012 Advisory Rule 2.5, global macro not referenced
 * There are global macros defined to be used by the integrator and another one used as include guard.
 */

/* Include inherited beans */
#include "Cpu.h"

/*! @brief Device instance number */
#define INST_PDLY1 (0U)

/*! @brief ADC pre-trigger configuration declaration */
extern const pdb_adc_pretrigger_config_t pdly1_AdcTrigInitConfig0;

/*! @brief PDB timer init config declaration */
extern const pdb_timer_config_t pdly1_InitConfig0;


#endif
/* ifndef pdly1_H */
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
