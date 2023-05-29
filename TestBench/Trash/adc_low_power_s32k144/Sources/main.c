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
**     Project     : adc_low_power_s32k144
**     Processor   : S32K144_100
**     Version     : Driver 01.00
**     Compiler    : GNU C Compiler
**     Date/Time   : 2015-07-03, 14:05, # CodeGen: 0
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
#include "clockMan1.h"
#include "pin_mux.h"
#include "lpit1.h"
#include "adConv1.h"
#include "pwrMan1.h"
#include "trgmux1.h"
#include "lpuart1.h"
#include "dmaController1.h"
#include "osif1.h"
#if CPU_INIT_CONFIG
  #include "Init_Config.h"
#endif

volatile int exit_code = 0;
/* User includes (#include below this line is not maintained by Processor Expert) */

#include <stdint.h>
#include <stdbool.h>

/* Defines containing the ADC max value, ADC input channel and LPIT channel */
#define ADC_MAX_VALUE   ((1 << 12) - 1)
/* ADC channel and LPIT channel defines
 * They must be equal and in the range [0:3]
 */
#define ADC_CHANNEL     (0UL)
#define LPIT_CHANNEL    (0UL)

/* Global flag which stores if an ADC conversion is complete */
volatile bool g_adcEvent;
/* Global variable that will be used to save the conversion result */
volatile uint16_t g_conversionResult;

/*
 * @brief Function that will create an array of chars that contain
 * a visual representation of the ADC result in the form of a bargraph.
 *
 * @param value[in]   : value to be represented
 * @param result[out] : pointer to an array of uint8_t where the graph will be saved
 * @param graphLen    : the length of the bar graph
 *
 * @return None
 */
void CreateGraph(uint16_t value, uint8_t * result, uint8_t graphLen)
{
    /* Local counter variable */
    uint8_t i;
    /* Number of the dots used in the graph by the conversion result */
    uint16_t numberOfDots = (uint16_t)((value *  graphLen)/ ADC_MAX_VALUE);

    /* Loop to manipulate the output array */
    for(i = 0; i < graphLen; i++)
    {
        if(i < numberOfDots)
        {
            result[i] = '#';
        }
        else
        {
            result[i] = '-';
        }
    }
}

/*
 * @brief ADC conversion complete interrupt service routine
 *  This function will set a flag to indicate an ADC event and
 *  will get the conversion result.
 *
 * @return None
 */
void adcISR(void)

{
    /* Get the conversion result */
    ADC_DRV_GetChanResult(INST_ADCONV1, ADC_CHANNEL, (uint16_t *)&g_conversionResult);
    /* Set the ADC conversion complete flag */
    g_adcEvent = true;
}

/*
 * @brief Function to initialize the LPIT-TRGMUX-ADC trigger chain.
 *
 * @return None
 */
void InitPeripherals(void)
{
    /* Configure TRGMUX to route the trigger from LPIT to ADC */
    TRGMUX_DRV_Init(INST_TRGMUX1, &trgmux1_InitConfig0);

    /* Initialize LPIT
     *  - Configured to run in Doze and Debug mode in 32 bit counter mode
     *  -   see LPIT component for more details
     */
    LPIT_DRV_Init(INST_LPIT1, &lpit1_InitConfig);

    /* Configure LPIT channel to have a period of 100 ms */
    LPIT_DRV_InitChannel(INST_LPIT1, LPIT_CHANNEL, &lpit1_ChnConfig0);

    /* Configure ADC converter to use hardware trigger and to have
     * a resolution of 12 bits
     */
    ADC_DRV_ConfigConverter(INST_ADCONV1, &adConv1_ConvConfig0);

    /* Configure hardware compare to generate an validate the conversion
     * result only if the value is greater than half of the range
     * (In this case 1/2 of VDD)
     */
    ADC_DRV_ConfigHwCompare(INST_ADCONV1, &adConv1_HwCompConfig0);

    /* Configure the ADC channel and enable the conversion complete
     * interrupt.
     */
    ADC_DRV_ConfigChan(INST_ADCONV1, ADC_CHANNEL, &adConv1_ChnConfig0);

    /* Enable ADC interrupt and install an ISR */
    IRQn_Type adc_irq_id = ADC_DRV_GetInterruptNumber(INST_ADCONV1);
    INT_SYS_InstallHandler(adc_irq_id, &adcISR, (isr_t*) 0);
    INT_SYS_EnableIRQ(adc_irq_id);

    /* Initialize the LPUART instance used to send the ADC conversion data to the host computer */
    LPUART_DRV_Init(INST_LPUART1, &lpuart1_State, &lpuart1_InitConfig0);
}

/*
 * @brief Initialize system drivers and services such as clocks, pins
 * power management and eDMA.
 *
 * @return None
 */
void InitSystem(void)
{
     /* Initialize and configure clocks
     *  - Configure system clocks
     *  - Configure peripheral's clock gating and source
     *  -   see clock manager component for more details
     */
    CLOCK_SYS_Init(g_clockManConfigsArr,   CLOCK_MANAGER_CONFIG_CNT, \
                       g_clockManCallbacksArr, CLOCK_MANAGER_CALLBACK_CNT);

    /* Update the clock configuration */
    CLOCK_SYS_UpdateConfiguration(0U, CLOCK_MANAGER_POLICY_AGREEMENT);

    /* Initialize pins
     *  - Configure pin muxing for LPUART, ADC and GPIO
     *  -   See PinSettings component for more info
     */
    PINS_DRV_Init(NUM_OF_CONFIGURED_PINS, g_pin_mux_InitConfigArr);

    /* Initialize Power Manager
     *  - Configure the Stop scheme for the MCU
     *  -   See Power Manager component for more info
     */
    POWER_SYS_Init(&powerConfigsArr, 1U, &powerStaticCallbacksConfigsArr, 0U);

    /* Initialize the Enhanced DMA to be used for LPUART transfers
     *  - Setup channel allocation
     *  -   See EDMA component for more info
     */
    EDMA_DRV_Init(&dmaController1_State,
    			  &dmaController1_InitConfig0,
				  edmaChnStateArray,
				  edmaChnConfigArray,
				  EDMA_CONFIGURED_CHANNELS_COUNT);
}

/*!
  \brief The main function for the project.
  \details The startup initialization sequence is the following:
 * - __start (startup asm routine)
 * - __init_hardware()
 * - main()
 *   - PE_low_level_init()
 *     - Common_Init()
 *     - Peripherals_Init()
*/
int main(void)
{
    /* Local variable used to store the bar graph */
    uint8_t buff[32] = "0 [####################] Vref\r\n";

  /*** Processor Expert internal initialization. DON'T REMOVE THIS CODE!!! ***/
  #ifdef PEX_RTOS_INIT
    PEX_RTOS_INIT();                 /* Initialization of the selected RTOS. Macro is defined by the RTOS component. */
  #endif
  /*** End of Processor Expert internal initialization.                    ***/

    /* Setup system drivers */
    InitSystem();
    /* Configure LPIT+TRGMUX+ADC chain */
    InitPeripherals();

    /* Clear the ADC Event flag */
    g_adcEvent = false;
    /* Start the LPIT channel corresponding to the ADC channel */
    LPIT_DRV_StartTimerChannels(INST_LPIT1, (1 << LPIT_CHANNEL));

    /* Infinite loop */
    while(1)
    {
        /* If the conversion is complete, read the result and send it via LPUART,
         * then set the CPU in sleep mode
         */
        if(g_adcEvent == true)
        {
            /* Clear the event flag */
            g_adcEvent = false;
            /* Call the function that generates the bar graph from the ADC result */
            CreateGraph(g_conversionResult, (uint8_t *)(&buff[3]), 20);
            /* Send the data to the host PC */
            LPUART_DRV_SendData(INST_LPUART1, buff, (uint32_t)(sizeof(buff)/sizeof(uint8_t)));
            /* Set the power mode to SLEEP */
            POWER_SYS_SetMode(0U, POWER_MANAGER_POLICY_AGREEMENT);
        }
        else
        {
            /* Set the power mode to SLEEP */
            POWER_SYS_SetMode(0U, POWER_MANAGER_POLICY_AGREEMENT);
        }
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
