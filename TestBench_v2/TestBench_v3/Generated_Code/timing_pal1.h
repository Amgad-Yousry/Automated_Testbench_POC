/* ###################################################################
**     This component module is generated by Processor Expert. Do not modify it.
**     Filename    : timing_pal1.h
**     Project     : TestBench_v3
**     Processor   : S32K144_100
**     Component   : timing_pal
**     Version     : Component SDK_S32K14x_09, Driver 01.00, CPU db: 3.00.000
**     Repository  : SDK_S32K14x_09
**     Compiler    : GNU C Compiler
**     Date/Time   : 2023-07-11, 11:30, # CodeGen: 10
**     Contents    :
**         TIMING_Init                - status_t TIMING_Init(const timer_instance_t instance, const timer_config_t *...
**         TIMING_Deinit              - void TIMING_Deinit(const timer_instance_t instance);
**         TIMING_StartChannel        - void TIMING_StartChannel(const timer_instance_t instance, const uint8_t...
**         TIMING_StopChannel         - void TIMING_StopChannel(const timer_instance_t instance, const uint8_t channel);
**         TIMING_GetElapsed          - uint32_t TIMING_GetElapsed(const timer_instance_t instance, const uint8_t...
**         TIMING_GetRemaining        - uint32_t TIMING_GetRemaining(const timer_instance_t instance, const uint8_t...
**         TIMING_EnableNotification  - void TIMING_EnableNotification(const timer_instance_t instance, const uint8_t...
**         TIMING_DisableNotification - void TIMING_DisableNotification(const timer_instance_t instance, const...
**         TIMING_GetResolution       - status_t TIMING_GetResolution(const timer_instance_t instance, const...
**         TIMING_GetMaxPeriod        - status_t TIMING_GetMaxPeriod(const timer_instance_t instance, const...
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
** @file timing_pal1.h
** @version 01.00
*/
/*!
**  @addtogroup timing_pal1_module timing_pal1 module documentation
**  @{
*/
#ifndef timing_pal1_H
#define timing_pal1_H

/* MODULE timing_pal1. */

/* Include inherited beans */
#include "clockMan1.h"
#include "Cpu.h"

/*! @brief Device instance number */
#define INST_TIMING_PAL1 (0U)

/*! @brief Channel configuration array */
extern timer_chan_config_t timing_pal1_channelConfigs[4];
/*! @brief Timer configuration */
extern timer_config_t timing_pal1_InitConfig;
/*! @brief Callback function of channel configuration 0 */
extern void timing_pal_GAS_callBack(void * userData);
/*! @brief Callback function of channel configuration 1 */
extern void timing_pal_SFM_callBack(void * userData);
/*! @brief Callback function of channel configuration 2 */
extern void timing_pal_AUTO_callBack(void * userData);
/*! @brief Callback function of channel configuration 3 */
extern void timing_pal_MPR_callBack(void * userData);

#endif
/* ifndef __timing_pal1_H */
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

