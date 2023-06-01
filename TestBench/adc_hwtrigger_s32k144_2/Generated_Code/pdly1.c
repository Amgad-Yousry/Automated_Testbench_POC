/* ###################################################################
**     This component module is generated by Processor Expert. Do not modify it.
**     Filename    : pdly1.c
**     Project     : adc_hwtrigger_s32k144_2
**     Processor   : S32K144_100
**     Component   : pdb
**     Version     : Component SDK_S32K14x_07, Driver 01.00, CPU db: 3.00.000
**     Repository  : SDK_S32K14x_07
**     Compiler    : GNU C Compiler
**     Date/Time   : 2023-05-31, 13:57, # CodeGen: 0
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
** @file pdly1.c
** @version 01.00
*/
/*!
**  @addtogroup pdly1_module pdly1 module documentation
**  @{
*/

/* MODULE pdly1.
 *
 * @page misra_violations MISRA-C:2012 violations
 *
 * @section [global]
 * Violates MISRA 2012 Advisory Rule 8.7, External variable could be made static.
 * The external variables will be used in other source files that user initialize
 * to use this module.
 */

#include "pdly1.h"

const pdb_adc_pretrigger_config_t pdly1_AdcTrigInitConfig0 = {
  .adcPreTriggerIdx = 0U,
  .preTriggerEnable = true,
  .preTriggerOutputEnable = true,
  .preTriggerBackToBackEnable = false,
};

const pdb_timer_config_t pdly1_InitConfig0 = {
  .loadValueMode = PDB_LOAD_VAL_IMMEDIATELY,
  .seqErrIntEnable = false,
  .clkPreDiv = PDB_CLK_PREDIV_BY_128,
  .clkPreMultFactor = PDB_CLK_PREMULT_FACT_AS_10,
  .triggerInput = PDB_SOFTWARE_TRIGGER,
  .continuousModeEnable = false,
  .dmaEnable = false,
  .intEnable = false,
};


/* END pdly1. */

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

