/*
 * Copyright (c) 2015 - 2016 , Freescale Semiconductor, Inc.
 * Copyright 2016-2017 NXP
 * All rights reserved.
 *
 * THIS SOFTWARE IS PROVIDED BY NXP "AS IS" AND ANY EXPRESSED OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL NXP OR ITS CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
 * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING
 * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
 * THE POSSIBILITY OF SUCH DAMAGE.
 */
/* ###################################################################
**     Filename    : main.c
**     Project     : freemaster_s32k144
**     Processor   : S32K144_100
**     Version     : Driver 01.00
**     Compiler    : GNU C Compiler
**     Date/Time   : 2016-08-09, 17:16, # CodeGen: 0
**     Abstract    :
**         Main module.
**         This module contains user's application code.
**     Settings    :
**     Contents    :
**         No public methods
**
** ###################################################################*/
/*!
** @file main.c
** @version 01.00
** @brief
**         Main module.
**         This module contains user's application code.
*/
/*!
**  @addtogroup main_module main module documentation
**  @{
*/
/* MODULE main */


/* Including needed modules to compile this module/procedure */
#include "Cpu.h"
#include "pin_mux.h"
#include "clockMan1.h"
#include "lpuart1.h"
#include "dmaController1.h"
#include "osif1.h"
#include "adConv1.h"
#include "lpTmr1.h"

  volatile int exit_code = 0;
/* User includes (#include below this line is not maintained by Processor Expert) */
#include "freemaster.h"

#define ADC_INSTANCE        0UL
#define ADC_CHN             12U
#define ADC_NR_SAMPLES      72

/* Variable used to count the number of ADC conversions */
volatile uint32_t   adcConvCnt;

/* Global variables used by FreeMASTER */
/* Variable to store value from ADC conversion */
volatile uint16_t   adcRawValue;
/* Variable to store number of ADC conversions per 10 ms */
volatile uint32_t   adcConvs;
/* Variable to store mean value of ADC_NR_SAMPLES conversions */
uint32_t            adcMeanValue;

/* @brief: ADC Interrupt Service Routine.
 *        Read the conversion result, store it
 *        into a variable and increment a counter.
 */
void ADC_IRQHandler(void)
{
    /* Get channel result from ADC channel */
    ADC_DRV_GetChanResult(ADC_INSTANCE, 0U, (uint16_t *)&adcRawValue);
    /* Increment the counter */
    adcConvCnt++;
}

/* @brief: LPTMR Interrupt Service Routine.
 *        Clear the compare flag, store the
 *        number of ADC conversions into a variable,
 *        reset the ADC conversions counter
 *        and set a specified flag.
 */
void LPTMR_IRQHandler(void)
{
    /* Clear compare flag */
    LPTMR_DRV_ClearCompareFlag(INST_LPTMR1);

    /* Store the number of ADC conversions */
    adcConvs = adcConvCnt;
    /* Reset the ADC conversions counter */
    adcConvCnt = 0;
}

/*!
  \brief The main function for the project.
  \details The startup initialization sequence is the following:
 * - startup asm routine
 * - main()
*/
int main(void)
{
  /* Write your local variable definition here */
    /* Variables used for computing ADC mean value */
    uint16_t cnt;
    uint32_t adcSum;

    /* Variables used for processing FreeMASATER application commands */
    static FMSTR_APPCMD_CODE cmd;
    static FMSTR_APPCMD_PDATA cmdDataP;
    static FMSTR_SIZE cmdSize;

  /*** Processor Expert internal initialization. DON'T REMOVE THIS CODE!!! ***/
  #ifdef PEX_RTOS_INIT
    PEX_RTOS_INIT();                   /* Initialization of the selected RTOS. Macro is defined by the RTOS component. */
  #endif
  /*** End of Processor Expert internal initialization.                    ***/

  /* Write your code here */
    /* Initialize counters and flags */
    adcConvCnt = 0;
    adcConvs = 0;

    /* Initialize and configure clocks
     *  -   see clock manager component for details
     */
    CLOCK_SYS_Init(g_clockManConfigsArr, CLOCK_MANAGER_CONFIG_CNT,
                 g_clockManCallbacksArr, CLOCK_MANAGER_CALLBACK_CNT);
    CLOCK_SYS_UpdateConfiguration(0U, CLOCK_MANAGER_POLICY_AGREEMENT);
    /* Initialize pins
     *  -   See PinSettings component for more info
     */
    PINS_DRV_Init(NUM_OF_CONFIGURED_PINS, g_pin_mux_InitConfigArr);
    /* Initialize LPUART instance */
    LPUART_DRV_Init(INST_LPUART1, &lpuart1_State, &lpuart1_InitConfig0);

    INT_SYS_InstallHandler(LPUART1_RxTx_IRQn, FMSTR_Isr, NULL);

    /* Configure the ADC converter
     *  -   See ADC component for the configuration details
     */
    adConv1_ChnConfig0.channel = ADC_CHN;
    adConv1_HwAvgConfig0.hwAvgEnable = 0;

    ADC_DRV_ConfigConverter(ADC_INSTANCE, &adConv1_ConvConfig0);
    ADC_DRV_ConfigChan(ADC_INSTANCE, 0UL, &adConv1_ChnConfig0);

    IRQn_Type adcIRQ;

    switch(ADC_INSTANCE)
    {
    case 0UL:
        adcIRQ = ADC0_IRQn;
        break;
    case 1UL:
        adcIRQ = ADC1_IRQn;
        break;
    default:
        adcIRQ = ADC1_IRQn;
        break;
    }
    /* Install IRQ handler for ADC interrupt */
    INT_SYS_InstallHandler(adcIRQ, &ADC_IRQHandler, (isr_t*) 0);

    /* Init LPTMR as timer
     *  -   interrupt after 1 second
     *  -   FIRC as clock source
     */
    LPTMR_DRV_Init(INST_LPTMR1, &lpTmr1_GeneralConfig0, false);
    /* Install IRQ handler for LPTMR interrupt */
    INT_SYS_InstallHandler(LPTMR0_IRQn, &LPTMR_IRQHandler, (isr_t *)0);
    /* Enable IRQ for LPTMR */
    INT_SYS_EnableIRQ(LPTMR0_IRQn);
    /* Start LPTMR counter */
    LPTMR_DRV_StartCounter(INST_LPTMR1);

    /* Enable ADC interrupt */
    INT_SYS_EnableIRQ(adcIRQ);

    /* Initialize FreeMASTER driver */
    FMSTR_Init();

    while(1)
    {
        /* Compute mean value of ADC conversions */
        cnt = 0;
        adcSum = 0;

        while(cnt < ADC_NR_SAMPLES) {
            adcSum += adcRawValue;
            cnt++;
        }
        adcMeanValue = adcSum / ADC_NR_SAMPLES;

        /* Process FreeMASTER application commands */
        cmd = FMSTR_GetAppCmd();
        if (cmd != FMSTR_APPCMDRESULT_NOCMD) {
            cmdDataP = FMSTR_GetAppCmdData(&cmdSize);
            switch(cmd) {
            /* set_ADC_resolution command */
            case 0:
                adConv1_ConvConfig0.resolution = *cmdDataP;

                ADC_DRV_ConfigConverter(ADC_INSTANCE, &adConv1_ConvConfig0);
                ADC_DRV_ConfigChan(ADC_INSTANCE, 0UL, &adConv1_ChnConfig0);

                /* Acknowledge the command */
                FMSTR_AppCmdAck(0);
                break;
            /* set_ADC_sampleTime command */
            case 1:
                adConv1_ConvConfig0.sampleTime = *cmdDataP;

                ADC_DRV_ConfigConverter(ADC_INSTANCE, &adConv1_ConvConfig0);
                ADC_DRV_ConfigChan(ADC_INSTANCE, 0UL, &adConv1_ChnConfig0);

                /* Acknowledge the command */
                FMSTR_AppCmdAck(0);
                break;
            /* set_ADC_hwAvgEnable command */
            case 2:
                adConv1_HwAvgConfig0.hwAvgEnable = *cmdDataP;

                ADC_DRV_ConfigConverter(ADC_INSTANCE, &adConv1_ConvConfig0);
                ADC_DRV_ConfigChan(ADC_INSTANCE, 0UL, &adConv1_ChnConfig0);

                /* Acknowledge the command */
                FMSTR_AppCmdAck(0);
                break;
            /* set_ADC_hwAverage command */
            case 3:
                adConv1_HwAvgConfig0.hwAverage = *cmdDataP;

                ADC_DRV_ConfigConverter(ADC_INSTANCE, &adConv1_ConvConfig0);
                ADC_DRV_ConfigChan(ADC_INSTANCE, 0UL, &adConv1_ChnConfig0);

                /* Acknowledge the command */
                FMSTR_AppCmdAck(0);
                break;
            default:
                /* Acknowledge the command with failure */
                FMSTR_AppCmdAck(1);
                break;
            }
        }

        /* Handle the protocol decoding and execution */
        FMSTR_Poll();
    }

  /*** Don't write any code pass this line, or it will be deleted during code generation. ***/
  /*** RTOS startup code. Macro PEX_RTOS_START is defined by the RTOS component. DON'T MODIFY THIS CODE!!! ***/
  #ifdef PEX_RTOS_START
    PEX_RTOS_START();                  /* Startup of the selected RTOS. Macro is defined by the RTOS component. */
  #endif
  /*** End of RTOS startup code.  ***/
  /*** Processor Expert end of main routine. DON'T MODIFY THIS CODE!!! ***/
  for(;;) {
    if(exit_code != 0) {
      break;
    }
  }
  return exit_code;
  /*** Processor Expert end of main routine. DON'T WRITE CODE BELOW!!! ***/
} /*** End of main routine. DO NOT MODIFY THIS TEXT!!! ***/

/* END main */
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
