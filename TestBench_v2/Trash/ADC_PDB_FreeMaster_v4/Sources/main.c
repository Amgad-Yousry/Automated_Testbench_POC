
/*
 * This program reads an ADC channel that is connected to the current signal of the power supply,
 * and convert it to the actual current measurement.
 * The ADC readings are (pre) triggered using the PDB (Programmable Delay Block).
 */

/* MODULE main */

/* Including needed modules to compile this module/procedure */
#include "Cpu.h"
#include "pin_mux.h"
#include "osif1.h"
#include "dmaController1.h"
//#include "dmaController1.h"
#include "adConv1.h"
#include "lpuart1.h"
#include "pdly1.h"
#include "clockMan1.h"

volatile int exit_code = 0;
/* User includes (#include below this line is not maintained by Processor Expert) */
#include "helper_functions.h"
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

/* Timeout for PDB in microseconds */
#define PDLY_TIMEOUT 	5UL

#define RMS_BUFFER_SIZE 500// 0.2 sec 20kHz

#define OUTPUT_DIR 1


/* This example is setup to work by default with EVB. To use it with other boards
   please comment the following line
*/

#define EVB

#ifdef EVB
	#define ADC_INSTANCE 	0UL
	#define ADC_CHN			0U /* PTA0 */
	#define ADC_VREFH  		3.3f
	#define ADC_VREFL  		0.0f
	#define PDB_INSTANCE	0UL
	#define ADC_COCO_IO		PTD
	#define ADC_COCO_PIN	7
	#define RMS_COCO_IO		PTE
	#define RMS_COCO_PIN	1
#else
	#define ADC_INSTANCE 	1UL
	#define ADC_CHN			10U
	#define ADC_VREFH  		1.2f
	#define ADC_VREFL  		0.0f
	#define PDB_INSTANCE	1UL
#endif


/* Variable to store the raw value from ADC conversion */
volatile uint16_t gu16CurrentRawValue;

/* Variable to store the converted current value */
volatile float gfCurrentValue;

/* Variable to store the current RMS value */
volatile float gfRMSCurrent;


/* Variable to count the number of conversions done and included on the RMS calculation */
volatile uint16_t gu16NrConvDone = 0U;

/* Variable to count and index the RMS calculation that is used to verify the
 * reliability of the data in FreeMaster */
uint16_t gu16RMSIdx = 0U;

/* Number total of conversions used to compute one RMS value */
uint16_t gu16RMSBuffer= RMS_BUFFER_SIZE;


/* Flag used to store if an ADC IRQ was executed */
volatile bool gbADCConvDone = false;

/* Flag used to toggle the pin when the program enters the ADC interrupt routine */
volatile bool gbCocoFlag = false;

/* Flag used to toggle the pin when the program finishes the RMS calculation */
volatile bool gbRMSCoCo = false;



/* @brief: ADC Interrupt Service Routine.
 * 		  Toggle a pin, read the conversion result, store it
 * 		  into a variable and set a specified flag.
 */
void ADC_IRQHandler(void)
{
	/* Toggle the pin PTD7 each time it enters this routine */
	gbCocoFlag = !gbCocoFlag;
	PINS_DRV_WritePin(ADC_COCO_IO,ADC_COCO_PIN, gbCocoFlag);

	/* Get channel result from ADC channel */
	ADC_DRV_GetChanResult(ADC_INSTANCE, 0U, (uint16_t *)&gu16CurrentRawValue);

	/* Set ADC conversion complete flag */
	gbADCConvDone = true;

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

	/* Time between the pre-trigger and the ADC reading */
	uint16_t u16PreTriggerDelay = 0U;

	/* Polynomial parameters from data fit to convert the raw ADC value to the actual current in Amperes*/
	const float fCurrentPol[2] = {0.00169404924302870, -0.0138943629841409};
	//const float fVoltagePol[2] = {0.00880332914534114, -0.273383180824596};

	/* Sum of the squared values of the current */
	float RMSCurrentAux = 0;


	/*** Processor Expert internal initialization. DON'T REMOVE THIS CODE!!! ***/
#ifdef PEX_RTOS_INIT
	PEX_RTOS_INIT(); /* Initialization of the selected RTOS. Macro is defined by the RTOS component. */
#endif
	/*** End of Processor Expert internal initialization.                    ***/

	/* Initialize and configure clocks
	 * 	-	see clock manager component for details
	 */
	CLOCK_SYS_Init(g_clockManConfigsArr, CLOCK_MANAGER_CONFIG_CNT,
			g_clockManCallbacksArr, CLOCK_MANAGER_CALLBACK_CNT);
	CLOCK_SYS_UpdateConfiguration(0U, CLOCK_MANAGER_POLICY_AGREEMENT);


	/* Initialize pins
	 *	-	See PinSettings component for more info
	 */
	PINS_DRV_Init(NUM_OF_CONFIGURED_PINS, g_pin_mux_InitConfigArr);



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

	/* The interrupt trigger is the ADC Coco flag, thus it enters the IRQ when the conversion is done*/
	INT_SYS_InstallHandler(adcIRQ, &ADC_IRQHandler, (isr_t*) 0);

	 /* Calculate the value needed for PDB instance
     * to generate an interrupt at a specified timeout.
     * If the value can not be reached, stop the application flow
     */
    if(!calculateIntValue(&pdly1_InitConfig0, PDLY_TIMEOUT, &u16PreTriggerDelay))
    {
    	/* Stop the application flow */
    	while(1);
    }


	/* Setup PDB instance
	 *	-	See PDB component for details
	 *	Note: Pre multiplier and Prescaler values come from
	 *		  calculateIntValue function.
	 */
	PDB_DRV_Init(PDB_INSTANCE, &pdly1_InitConfig0);
	PDB_DRV_ConfigAdcPreTrigger(PDB_INSTANCE, ADC_CHN, &pdly1_AdcTrigInitConfig0);
	PDB_DRV_SetTimerModulusValue(PDB_INSTANCE, (uint32_t) u16PreTriggerDelay);
	PDB_DRV_SetAdcPreTriggerDelayValue(PDB_INSTANCE, ADC_CHN, ADC_CHN, (uint32_t) u16PreTriggerDelay);
	PDB_DRV_LoadValuesCmd(PDB_INSTANCE);
	PDB_DRV_SoftTriggerCmd(PDB_INSTANCE);

	/* Enable ADC 1 interrupt */
	INT_SYS_EnableIRQ(adcIRQ);


	/* Set the pins to be toggled as output */
	PINS_DRV_SetPinDirection(ADC_COCO_IO, ADC_COCO_PIN, OUTPUT_DIR);
	PINS_DRV_SetPinDirection(RMS_COCO_IO, RMS_COCO_PIN, OUTPUT_DIR);


	/* Infinite loop
	 * 	-	Wait for ADC conversion complete interrupt,
	 * 		then:
	 * 			 compute the actual current value,
	 * 			 calculate the RMS value after an predetermined number of measurements,
	 * 			 toggle the pin referent to a new RMS conversion,
	 * 			 trigger the PDB timer.
	 */

	while (1)
	{
		/* Finished the ADC conversion routine */
		if (gbADCConvDone == true)
		{
			/* Trigger PDB timer */
			PDB_DRV_SoftTriggerCmd(PDB_INSTANCE);

			/* Update the counter of the number of conversions done */
			gu16NrConvDone++;

			/* Process the readings to get the value in Amperes */
			gfCurrentValue = ((float) gu16CurrentRawValue)*fCurrentPol[0] + fCurrentPol[1];

			/* Compute the sum of the squared values of current needed to the RMS computation */
			RMSCurrentAux += gfCurrentValue*gfCurrentValue;

			/* After a predefined number of readings, compute the RMS */
			if (gu16NrConvDone == gu16RMSBuffer)
			{
				/* Compute the current RMS value */
				gfRMSCurrent = sqrt(RMSCurrentAux/gu16NrConvDone);

				/*Update the RMS index */
				gu16RMSIdx ++;

				/* Toggle the pin to indicate the RMS computation was done */
				gbRMSCoCo = !gbRMSCoCo;
				PINS_DRV_WritePin(RMS_COCO_IO, RMS_COCO_PIN, gbRMSCoCo);

				/* Clear the squared sum buffer */
				RMSCurrentAux = 0;

				/* Clear the counter of the RMS */
				gu16NrConvDone = 0;
			}


			/* Clear conversion done interrupt flag */
			gbADCConvDone = false;

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
