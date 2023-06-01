/* ###################################################################
**     This component module is generated by Processor Expert. Do not modify it.
**     Filename    : lpit1.h
**     Project     : panel_control_v2
**     Processor   : S32K144_100
**     Component   : lpit
**     Version     : Component SDK_S32K14x_09, Driver 01.00, CPU db: 3.00.000
**     Repository  : SDK_S32K14x_09
**     Compiler    : GNU C Compiler
**     Date/Time   : 2023-05-31, 17:27, # CodeGen: 1
**     Contents    :
**         LPIT_DRV_Init                              - void LPIT_DRV_Init(uint32_t instance, const lpit_user_config_t *userConfig);
**         LPIT_DRV_Deinit                            - void LPIT_DRV_Deinit(uint32_t instance);
**         LPIT_DRV_InitChannel                       - status_t LPIT_DRV_InitChannel(uint32_t instance, uint32_t channel, const...
**         LPIT_DRV_StartTimerChannels                - void LPIT_DRV_StartTimerChannels(uint32_t instance, uint32_t mask);
**         LPIT_DRV_StopTimerChannels                 - void LPIT_DRV_StopTimerChannels(uint32_t instance, uint32_t mask);
**         LPIT_DRV_SetTimerPeriodByUs                - status_t LPIT_DRV_SetTimerPeriodByUs(uint32_t instance, uint32_t channel,...
**         LPIT_DRV_SetTimerPeriodInDual16ModeByUs    - status_t LPIT_DRV_SetTimerPeriodInDual16ModeByUs(uint32_t instance, uint32_t...
**         LPIT_DRV_GetTimerPeriodByUs                - uint64_t LPIT_DRV_GetTimerPeriodByUs(uint32_t instance, uint32_t channel);
**         LPIT_DRV_GetCurrentTimerUs                 - uint64_t LPIT_DRV_GetCurrentTimerUs(uint32_t instance, uint32_t channel);
**         LPIT_DRV_SetTimerPeriodByCount             - void LPIT_DRV_SetTimerPeriodByCount(uint32_t instance, uint32_t channel,...
**         LPIT_DRV_SetTimerPeriodInDual16ModeByCount - void LPIT_DRV_SetTimerPeriodInDual16ModeByCount(uint32_t instance, uint32_t...
**         LPIT_DRV_GetTimerPeriodByCount             - uint32_t LPIT_DRV_GetTimerPeriodByCount(uint32_t instance, uint32_t channel);
**         LPIT_DRV_GetCurrentTimerCount              - uint32_t LPIT_DRV_GetCurrentTimerCount(uint32_t instance, uint32_t channel);
**         LPIT_DRV_GetInterruptFlagTimerChannels     - uint32_t LPIT_DRV_GetInterruptFlagTimerChannels(uint32_t instance, uint32_t...
**         LPIT_DRV_ClearInterruptFlagTimerChannels   - void LPIT_DRV_ClearInterruptFlagTimerChannels(uint32_t instance, uint32_t mask);
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
** @file lpit1.h
** @version 01.00
*/
/*!
**  @addtogroup lpit1_module lpit1 module documentation
**  @{
*/
#ifndef lpit1_H
#define lpit1_H

/* MODULE lpit1.
 *
 * @page misra_violations MISRA-C:2012 violations
 *
 * @section [global]
 * Violates MISRA 2012 Advisory Rule 2.5, Global macro not referenced.
 * The global macro will be used in function call of the module.
 */

/* Include inherited beans */
#include "clockMan1.h"
#include "Cpu.h"

/*! Device instance number */
#define INST_LPIT1 (0U)

/*! Global configuration of lpit1 */
extern const lpit_user_config_t  lpit1_InitConfig;
/*! User channel configuration 0 */
extern lpit_user_channel_config_t lpit1_ChnConfig0;

#endif
/* END lpit1 */
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

