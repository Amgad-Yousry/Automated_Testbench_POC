/* ###################################################################
**     This component module is generated by Processor Expert. Do not modify it.
**     Filename    : timing_pal1.c
**     Project     : TestBench_v3
**     Processor   : S32K144_100
**     Component   : timing_pal
**     Version     : Component SDK_S32K14x_09, Driver 01.00, CPU db: 3.00.000
**     Repository  : SDK_S32K14x_09
**     Compiler    : GNU C Compiler
**     Date/Time   : 2023-07-12, 16:02, # CodeGen: 0
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
** @file timing_pal1.c
** @version 01.00
*/
/*!
**  @addtogroup timing_pal1_module timing_pal1 module documentation
**  @{
*/
#include <stddef.h>
#include "timing_pal1.h"

/*! @brief Channel configuration array */
timer_chan_config_t timing_pal1_channelConfigs[4] =
{
    /* Channel configuration 0 */
    {
         .channel        = 0U,
         .chanType       = TIMER_CHAN_TYPE_CONTINUOUS,
         .callback       = timing_pal_GAS_callBack,
         .callbackParam  = NULL
    },
    /* Channel configuration 1 */
    {
         .channel        = 1U,
         .chanType       = TIMER_CHAN_TYPE_CONTINUOUS,
         .callback       = timing_pal_SFM_callBack,
         .callbackParam  = NULL
    },
    /* Channel configuration 2 */
    {
         .channel        = 2U,
         .chanType       = TIMER_CHAN_TYPE_CONTINUOUS,
         .callback       = timing_pal_AUTO_callBack,
         .callbackParam  = NULL
    },
    /* Channel configuration 3 */
    {
         .channel        = 3U,
         .chanType       = TIMER_CHAN_TYPE_CONTINUOUS,
         .callback       = timing_pal_MPR_callBack,
         .callbackParam  = NULL
    }
};
/*! @brief Timer configuration */
timer_config_t timing_pal1_InitConfig =
{
    .chanConfigArray     = timing_pal1_channelConfigs,
    .numChan             = 4U,
    .extension           = NULL
};

/* END timing_pal1. */
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
