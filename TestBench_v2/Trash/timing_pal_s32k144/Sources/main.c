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
**     Project     : timing_pal_s32k144
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
#include "timing_pal1.h"
#include "timing_pal2.h"
#include "timing_pal3.h"
#if CPU_INIT_CONFIG
  #include "Init_Config.h"
#endif

volatile int exit_code = 0;
/* User includes (#include below this line is not maintained by Processor Expert) */

#include <stdint.h>
#include <stdbool.h>

/* This define configures led pin and port for use with EVB, to make it run on
 * FVB you need to comment the following line.
 */
#define EVB

#ifdef EVB
	#define LED0_PIN_INDEX  0U
	#define LED1_PIN_INDEX  15U
	#define LED2_PIN_INDEX  16U
	#define LED_GPIO_PORT	PTD
#else
	#define LED0_PIN_INDEX	0U
	#define LED1_PIN_INDEX	1U
	#define LED2_PIN_INDEX	2U
	#define LED_GPIO_PORT	PTC
#endif

/* LPIT channel used */
#define LPIT_CHANNEL	    0UL
/* LPTMR channel used */
#define LPTMR_CHANNEL	    0UL
/* FTM0 channel used */
#define FTM_CHANNEL	   		0UL

/* Period in nanosecond unit */
#define PERIOD_BY_NS	1000000000UL /* The period is 1 second */

/*!
 * @brief: The callback function of timing over LPIT channel 0.
 * 	       The callback function toggles LED0
 */
void timing_pal1_channel_callBack0(void * userData)
{
	(void)userData;
	/* Toggle LED0 */
	PINS_DRV_TogglePins(LED_GPIO_PORT, (1 << LED0_PIN_INDEX));
}

/*!
 * @brief: The callback function of timing over LPTMR channel 0.
 * 	       The callback function toggles LED1
 */
void timing_pal2_channel_callBack0(void * userData)
{
	(void)userData;
	/* Toggle LED1 */
	PINS_DRV_TogglePins(LED_GPIO_PORT, (1 << LED1_PIN_INDEX));
}

/*!
 * @brief: The callback function of timing over FTM0 channel 0.
 * 	       The callback function toggles LED2
 */
void timing_pal3_channel_callBack0(void * userData)
{
	(void)userData;
	/* Toggle LED2 */
	PINS_DRV_TogglePins(LED_GPIO_PORT, (1 << LED2_PIN_INDEX));
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

	uint64_t lpitResolution;
	uint64_t lptmrResolution;
	uint64_t ftmResolution;
  /*** Processor Expert internal initialization. DON'T REMOVE THIS CODE!!! ***/
  #ifdef PEX_RTOS_INIT
    PEX_RTOS_INIT();                 /* Initialization of the selected RTOS. Macro is defined by the RTOS component. */
  #endif
  /*** End of Processor Expert internal initialization.                    ***/

    /* Initialize and configure clocks
	 * 	-	configure source clocks, PCC for LED port and LPIT instance
	 */
    CLOCK_SYS_Init(g_clockManConfigsArr,   CLOCK_MANAGER_CONFIG_CNT,
                   g_clockManCallbacksArr, CLOCK_MANAGER_CALLBACK_CNT);
    CLOCK_SYS_UpdateConfiguration(0U, CLOCK_MANAGER_POLICY_AGREEMENT);

	/* Initialize pins
	 *	-	Setup pin used for LED(used as GPIO)
	 */
    PINS_DRV_Init(NUM_OF_CONFIGURED_PINS, g_pin_mux_InitConfigArr);
    /* Set LED pin direction as output */
	PINS_DRV_SetPinsDirection(LED_GPIO_PORT, (1 << LED0_PIN_INDEX) | (1 << LED1_PIN_INDEX) | (1 << LED2_PIN_INDEX));
	/* Turn off LEDs */
	PINS_DRV_SetPins(LED_GPIO_PORT, (1 << LED0_PIN_INDEX) | (1 << LED1_PIN_INDEX) | (1 << LED2_PIN_INDEX));

	/* Initialize TIMING over LPIT */
    TIMING_Init(INST_TIMING_PAL1, &timing_pal1_InitConfig);
    /* Initialize TIMING over LPTMR */
    TIMING_Init(INST_TIMING_PAL2, &timing_pal2_InitConfig);
    /* Initialize TIMING over FTM0 */
    TIMING_Init(INST_TIMING_PAL3, &timing_pal3_InitConfig);

	/* Get tick resolution in nanosecond unit for TIMING over LPIT */
	TIMING_GetResolution(INST_TIMING_PAL1, TIMER_RESOLUTION_TYPE_NANOSECOND, &lpitResolution);
	/* Get tick resolution in nanosecond unit for TIMING over LPTMR */
	TIMING_GetResolution(INST_TIMING_PAL2, TIMER_RESOLUTION_TYPE_NANOSECOND, &lptmrResolution);
	/* Get tick resolution in nanosecond unit for TIMING over FTM */
	TIMING_GetResolution(INST_TIMING_PAL3, TIMER_RESOLUTION_TYPE_NANOSECOND, &ftmResolution);

    /* Start LPIT channel 0 counting with the period is 1 second,
       the period in tick = the period in nanosecond / LPIT tick resolution in nanosecond */
	TIMING_StartChannel(INST_TIMING_PAL1, LPIT_CHANNEL, PERIOD_BY_NS/lpitResolution);
	/* Start LPTMR channel 0 counting with the period is 1 second,
	   the period in tick = the period in nanosecond / LPTMR tick resolution nanosecond*/
	TIMING_StartChannel(INST_TIMING_PAL2, LPTMR_CHANNEL, PERIOD_BY_NS/lptmrResolution);
	/* Start FTM channel 0 counting with the period is 1 second,
	   the period in tick = the period in nanosecond / FTM tick resolution nanosecond*/
	TIMING_StartChannel(INST_TIMING_PAL3, FTM_CHANNEL, PERIOD_BY_NS/ftmResolution);

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
