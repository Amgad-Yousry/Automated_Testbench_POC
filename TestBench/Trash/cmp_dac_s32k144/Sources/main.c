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
**     Project     : cmp_dac_s32k144
**     Processor   : S32K144_100
**     Version     : Driver 01.00
**     Compiler    : GNU C Compiler
**     Date/Time   : 2016-03-21, 14:05, # CodeGen: 0
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
#include "comparator1.h"
#if CPU_INIT_CONFIG
  #include "Init_Config.h"
#endif

volatile int exit_code = 0;
/* User includes (#include below this line is not maintained by Processor Expert) */

#include <stdint.h>
#include <stdbool.h>

/* To use with other board than EVB please comment the following line */

#define EVB

#ifdef EVB
    #define LED0            15U
    #define LED1            16U
    #define LED_GPIO        PTD
#else
    #define LED0             0U
    #define LED1             1U
    #define LED_GPIO        PTC
#endif


/*! brief Comparator Interrupt Service routine
 * It will read the output flags and based on the result will light the
 * required LED:
 *  -   Green if Vin is greater than DAC voltage
 *  -   Red if Vin is lower than DAC voltage
 *  -   Both LEDs if both edges are detected
 */
void ComparatorISR(void)
{
    /* Variable used to store comparator output flags */
    cmp_output_trigger_t cmpOutputFlags;
    /* Get output flags */
    CMP_DRV_GetOutputFlags(INST_COMPARATOR1, &cmpOutputFlags);

    switch(cmpOutputFlags)
    {
    /* Vin is greater than DAC voltage */
    case CMP_FALLING_EDGE:
        /* Light the RED led */
        PINS_DRV_ClearPins(LED_GPIO, (1 << LED0));
        /* Close the GREEN led */
        PINS_DRV_SetPins(LED_GPIO, (1 << LED1));
        break;
    /* Vin is lower than DAC voltage */
    case CMP_RISING_EDGE:
        /* Light the GREEN led */
        PINS_DRV_ClearPins(LED_GPIO, (1 << LED1));
        /* Close the RED led */
        PINS_DRV_SetPins(LED_GPIO, (1 << LED0));
        break;
    /* Case is unknown or special (both edges detected) */
    default:
        /* Light both LEDs */
        PINS_DRV_ClearPins(LED_GPIO, (1 << LED0) | (1 << LED1));
        break;
    }

    /* Clear output flags */
    CMP_DRV_ClearOutputFlags(INST_COMPARATOR1);
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

  /*** Processor Expert internal initialization. DON'T REMOVE THIS CODE!!! ***/
  #ifdef PEX_RTOS_INIT
    PEX_RTOS_INIT();                 /* Initialization of the selected RTOS. Macro is defined by the RTOS component. */
  #endif
  /*** End of Processor Expert internal initialization.                    ***/

    /* Initialize and configure clocks
     *  -   Setup system clocks
     *  -   Enable clock feed for Ports and Comparator
     *  -   See Clock Manager component for more info
     */
    CLOCK_SYS_Init(g_clockManConfigsArr, CLOCK_MANAGER_CONFIG_CNT,
                        g_clockManCallbacksArr, CLOCK_MANAGER_CALLBACK_CNT);
    CLOCK_SYS_UpdateConfiguration(0U, CLOCK_MANAGER_POLICY_AGREEMENT);


    /* Initialize pins
     *  -   Setup input pins for Comparator
     *  -   Setup output pins for LEDs
     *  -   See PinSettings component for more info
     */
    PINS_DRV_Init(NUM_OF_CONFIGURED_PINS, g_pin_mux_InitConfigArr);

    /* Setup GPIO pins
     *  -   LED0 and LED1 as output
     */
    PINS_DRV_SetPinsDirection(LED_GPIO, (1 << LED0)|(1 << LED1));

    /* Turn off both LEDs */
    PINS_DRV_SetPins(LED_GPIO, (1 << LED0)|(1 << LED1));

    /* Initialize Comparator
     *  -   Positive source from AIN0
     *  -   Negative source from internal DAC with half the reference voltage
     *  5V/2 = 2.5V(For EVB). For other boards please contact the boards reference
     *  manual.
     *  -   Output interrupt enabled for both edges
     */
    CMP_DRV_Init(INST_COMPARATOR1, &cmp_general_config);

    /* Install Comparator interrupt handler */
    INT_SYS_InstallHandler(CMP0_IRQn, &ComparatorISR, (isr_t *)0);

    /* Enable Comparator interrupt */
    INT_SYS_EnableIRQ(CMP0_IRQn);

    /* Initialization ends here. The rest of the example is based on the
     * Comparator Interrupt (ComparatorISR function).
     */

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
