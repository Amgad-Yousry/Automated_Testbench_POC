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

/* Including needed modules to compile this module/procedure */
#include "Cpu.h"
#include "pin_mux.h"
#include "adConv1.h"
#include "pdly1.h"
#include "clockMan1.h"

volatile int exit_code = 0;
/* User includes (#include below this line is not maintained by Processor Expert) */

#include <stdint.h>
#include <stdbool.h>

#define TIMEOUT		1000UL	/* 1 second interval */

/* This example is setup to work by default with EVB. To use it with other boards
   please comment the following line
*/

#define EVB

#ifdef EVB
	#define LED_PIN 	7U		/* LED pin on PTD15 for the EVB Board */
	#define LED_GPIO	PTD
	#define ADC_INSTANCE 	0UL
	#define ADC_CHN			0U
	#define ADC_VREFH  		3.3f
	#define ADC_VREFL  		0.0f
	#define PDB_INSTANCE	0UL
#else
	#define LED_PIN		0U		/* LED pin PTC0 */
	#define LED_GPIO	PTC
#endif

#include "helper_functions.h"

/* Flag used to store if an ADC IRQ was executed */
volatile bool adcConvDone;
/* Variable to store value from ADC conversion */
volatile uint16_t adcRawValue;

uint16_t counter = 0U;

volatile bool flag = false;

bool cocoflag;

uint16_t assertion_flag;

uint16_t pdbIntValue;


/* brief: PDB instance ISR
 * This handler will toggle the led when
 * the PDB generates an IRQ
 */
void PDB_IRQHandler(void)
{
	cocoflag = ADC_DRV_GetConvCompleteFlag (ADC_INSTANCE, ADC_CHN);
	/* Get channel result from ADC channel */
	ADC_DRV_GetChanResult(ADC_INSTANCE, 0U, (uint16_t *)&adcRawValue);


	PINS_DRV_WritePin(LED_GPIO,LED_PIN, cocoflag);
	PINS_DRV_WritePin(PTE, 01,flag);
	//PINS_DRV_WritePin(PTE, 01,(bool) PDB_DRV_GetAdcPreTriggerFlags(INST_PDLY1, ADC_CHN, ADC_CHN));

//	assertion_flag = PDB_DRV_GetAdcPreTriggerFlags(INST_PDLY1, ADC_CHN, ADC_CHN);


	/* Clear PDB instance Interrupt flag */
	//PDB_DRV_ClearTimerIntFlag(INST_PDLY1);
	//PDB_DRV_ClearAdcPreTriggerFlags(INST_PDLY1, ADC_CHN, 0U);

	counter++;

	/* Toggle the LED */


	flag = !flag;



	 /* Software trigger the counter */
	PDB_DRV_SoftTriggerCmd(INST_PDLY1);

	cocoflag = ADC_DRV_GetConvCompleteFlag (ADC_INSTANCE, ADC_CHN);
	PINS_DRV_WritePin(LED_GPIO,LED_PIN, cocoflag);

}

/* Assign the PDB ISR to the instance used */
#if PDLY1 < 1
void PDB0_IRQHandler(void)
  {
	PDB_IRQHandler();
  }
#else
void PDB1_IRQHandler(void)
  {
	PDB_IRQHandler();
  }
#endif


/*!
  \brief The main function for the project.
  \details The startup initialization sequence is the following:
 * - startup asm routine
 * - main()
*/
int main(void)
{
  /* Write your local variable definition here */

	/* Write your local variable definition here */
		uint16_t delayValue = 0;

		/* Variables in which we store data from ADC */
		uint16_t adcMax;
		float adcValue;


  /*** Processor Expert internal initialization. DON'T REMOVE THIS CODE!!! ***/
  #ifdef PEX_RTOS_INIT
    PEX_RTOS_INIT();                   /* Initialization of the selected RTOS. Macro is defined by the RTOS component. */
  #endif
  /*** End of Processor Expert internal initialization.                    ***/

    /* Initialize and configure clocks
	 * 	-	see clock manager component for details
	 */
    CLOCK_SYS_Init(g_clockManConfigsArr, CLOCK_MANAGER_CONFIG_CNT, g_clockManCallbacksArr, CLOCK_MANAGER_CALLBACK_CNT);
    CLOCK_SYS_UpdateConfiguration(0U, CLOCK_MANAGER_POLICY_AGREEMENT);

	/* Initialize pins
	 *	-	See PinSettings component for more info
	 */
    PINS_DRV_Init(NUM_OF_CONFIGURED_PINS, g_pin_mux_InitConfigArr);


    /* Get ADC max value from the resolution */
    	if (adConv1_ConvConfig0.resolution == ADC_RESOLUTION_8BIT)
    		adcMax = (uint16_t) (1 << 8);
    	else if (adConv1_ConvConfig0.resolution == ADC_RESOLUTION_10BIT)
    		adcMax = (uint16_t) (1 << 10);
    	else
    		adcMax = (uint16_t) (1 << 12);


    	/* Configure the ADC converter
    	 * 	-	See ADC component for the configuration details
    	 */

    	adConv1_ChnConfig0.channel = ADC_CHN;

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

    		INT_SYS_InstallHandler(adcIRQ, &PDB_IRQHandler, (isr_t*) 0);


    /* Calculate the value needed for PDB instance
     * to generate an interrupt at a specified timeout.
     * If the value can not be reached, stop the application flow
     */
    if(!calculateIntValue(&pdly1_InitConfig0, TIMEOUT, &pdbIntValue))
    {
    	/* Stop the application flow */
    	while(1);
    }

    /* Initialize PDB instance with the configuration structure
     *  -	See PEx component for more details
     */
    PDB_DRV_Init(INST_PDLY1, &pdly1_InitConfig0);

	PINS_DRV_Init(NUM_OF_CONFIGURED_PINS, g_pin_mux_InitConfigArr);

    /* Set direction for GPIO */
    PINS_DRV_SetPinDirection(LED_GPIO, LED_PIN, 1);
    /* Clear output logic on selected pin */
   // PINS_DRV_ClearPins(LED_GPIO, (uint32_t) (1 << LED_PIN));

    /* Set the calculated values to PDB interrupt and modulus registers */
    PDB_DRV_SetTimerModulusValue(INST_PDLY1, pdbIntValue);
    PDB_DRV_SetValueForTimerInterrupt(INST_PDLY1, pdbIntValue);

    PDB_DRV_ConfigAdcPreTrigger(INST_PDLY1, 0UL, &pdly1_AdcTrigInitConfig0);

    PDB_DRV_SetAdcPreTriggerDelayValue(INST_PDLY1, 0UL, 0UL, 10u);


    /* Command the PDB instance to load the fresh values */
    PDB_DRV_LoadValuesCmd(INST_PDLY1);
    /* Software trigger the counter */
    PDB_DRV_SoftTriggerCmd(INST_PDLY1);


    /* Enable ADC 1 interrupt */
    	INT_SYS_EnableIRQ(adcIRQ);


    /* Infinite loop
     * Do nothing, when the timeout is reached it generates an
     * interrupt which toggles a led.
     */
    while(1)
    {
 //   	assertion_flag = PDB_DRV_GetAdcPreTriggerFlags(INST_PDLY1, ADC_CHN, ADC_CHN);
   	__asm("nop");

    //	PINS_DRV_WritePin(PTE, 01,(bool) PDB_DRV_GetAdcPreTriggerFlags(INST_PDLY1, ADC_CHN, ADC_CHN));
        /* Software trigger the counter */
       // PDB_DRV_SoftTriggerCmd(INST_PDLY1);
    	/* Toggle the LED */
 //   		PINS_DRV_WritePin(LED_GPIO,LED_PIN, PDB_DRV_GetTimerIntFlag (INST_PDLY1));
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
