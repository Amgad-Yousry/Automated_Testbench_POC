/* ###################################################################
**     This component module is generated by Processor Expert. Do not modify it.
**     Filename    : lpTmr1.c
**     Project     : freemaster_s32k144
**     Processor   : S32K144_100
**     Component   : lptmr
**     Version     : Component SDK_S32K14x_07, Driver 01.00, CPU db: 3.00.000
**     Repository  : SDK_S32K14x_07
**     Compiler    : GNU C Compiler
**     Date/Time   : 2023-06-09, 11:25, # CodeGen: 0
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
** @file lpTmr1.c
** @version 01.00
*/
/*!
**  @addtogroup lpTmr1_module lpTmr1 module documentation
**  @{
*/

/* MODULE lpTmr1. */

/**
 * @page misra_violations MISRA-C:2012 violations
 *
 * @section [global]
 * Violates MISRA 2012 Advisory Rule 8.7, External variable could be made static.
 * The external variables will be used in other source files, with the same initialized values.
 */

#include "lpTmr1.h"


/*! lpTmr1 configuration structure */


const lptmr_config_t lpTmr1_GeneralConfig0 = {
  .workMode = LPTMR_WORKMODE_TIMER,
  .dmaRequest = false,
  .interruptEnable = false,
  .freeRun = false,
  .compareValue = 1000000U,
  .counterUnits = LPTMR_COUNTER_UNITS_MICROSECONDS,
  .clockSelect = LPTMR_CLOCKSOURCE_SIRCDIV2,
  .prescaler = LPTMR_PRESCALE_2,
  .bypassPrescaler = false,
  .pinSelect = LPTMR_PINSELECT_TRGMUX,
  .pinPolarity = LPTMR_PINPOLARITY_RISING,
};


/* END lpTmr1. */
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

