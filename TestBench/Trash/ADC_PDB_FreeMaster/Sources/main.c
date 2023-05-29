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

/* MODULE main */

/* Including needed modules to compile this module/procedure */
#include "Cpu.h"
#include "pin_mux.h"
#include "osif1.h"
#include "dmaController1.h"
#include "adConv1.h"
#include "lpTmr1.h"
#include "pdly1.h"
#include "pdly1.h"
#include "lpuart1.h"
#include "clockMan1.h"

volatile int exit_code = 0;
/* User includes (#include below this line is not maintained by Processor Expert) */
#include "helper_functions.h"
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

#include "freemaster.h"


/* Timeout for PDB in microseconds */
#define PDLY_TIMEOUT 	1000000UL // 20kHz 50 micro


#define RMS_BUFFER_SIZE 4000// 0.2 sec 20kHz

/* This example is setup to work by default with EVB. To use it with other boards
   please comment the following line
*/

#define EVB

#ifdef EVB
	#define ADC_INSTANCE 	0UL
	#define ADC_CHN			0U
	#define ADC_VREFH  		3.3f
	#define ADC_VREFL  		0.0f
	#define PDB_INSTANCE	0UL
	#define ADC_COCO		7U
    #define COCO_GPIO       PTD
#else
	#define ADC_INSTANCE 	1UL
	#define ADC_CHN			10U
	#define ADC_VREFH  		1.2f
	#define ADC_VREFL  		0.0f
	#define PDB_INSTANCE	1UL
#endif



/* Flag used to store if an ADC IRQ was executed */
volatile bool adcCoCo;
/* Variable to store value from ADC conversion */
volatile uint16_t gu16CurrentRawValue;


volatile uint16_t gu16CurrentRawValue;
volatile float gfCurrentValue;
volatile float gfRMSCurrent;

volatile bool gbRMSCoCo;

uint16_t counter = 0U;

//uint16_t gu16CurrentVector [BUFFER_SIZE];






/* @brief: ADC Interrupt Service Routine.
 * 		  Read the conversion result, store it
 * 		  into a variable and set a specified flag.
 */
void ADC_IRQHandler(void)
{
	/* Get channel result from ADC channel */
	ADC_DRV_GetChanResult(ADC_INSTANCE, 0U, (uint16_t *)&gu16CurrentRawValue);
	/* Set ADC conversion complete flag */
	adcCoCo = true;
	PINS_DRV_WritePin(COCO_GPIO,ADC_COCO, PDB_DRV_GetTimerIntFlag (INST_PDLY1));
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
	uint16_t delayValue = 0;

//	uint16_t u16CurrentVector [BUFFER_SIZE];


	/* Variables in which we store data from ADC */
//	uint16_t adcMax;
//	float adcValue;

	float RMSCurrentAux = 0;

	gbRMSCoCo = false;

	/* Polynomial parameters from data fit */
//	const float fVoltagePol[2] = {0.00880332914534114, -0.273383180824596};
	const float fCurrentPol[2] = {0.00169404924302870, -0.0138943629841409};




	adcCoCo = false;

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

	INT_SYS_InstallHandler(adcIRQ, &ADC_IRQHandler, (isr_t*) 0);

	 /* Calculate the value needed for PDB instance
     * to generate an interrupt at a specified timeout.
     * If the value can not be reached, stop the application flow
     */
    if(!calculateIntValue(&pdly1_InitConfig0, PDLY_TIMEOUT, &delayValue))
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
	PDB_DRV_ConfigAdcPreTrigger(PDB_INSTANCE, 0UL, &pdly1_AdcTrigInitConfig0);
	PDB_DRV_SetTimerModulusValue(PDB_INSTANCE, (uint32_t) delayValue);
	PDB_DRV_SetAdcPreTriggerDelayValue(PDB_INSTANCE, 0UL, 0UL,
			(uint32_t) delayValue);
	PDB_DRV_LoadValuesCmd(PDB_INSTANCE);
	PDB_DRV_SoftTriggerCmd(PDB_INSTANCE);

	/* Enable ADC 1 interrupt */
	INT_SYS_EnableIRQ(adcIRQ);

    /* Initialize LPUART instance */
    LPUART_DRV_Init(INST_LPUART1, &lpuart1_State, &lpuart1_InitConfig0);

    INT_SYS_InstallHandler(LPUART1_RxTx_IRQn, FMSTR_Isr, NULL);
    /* Initialize FreeMASTER driver */
   //k FMSTR_Init();

   // FMSTR_InitRec();
   // FMSTR_TriggerRec();

	/* Infinite loop
	 * 	-	Wait for ADC conversion complete interrupt,
	 * 		then process and send the result to user.
	 */

	while (1)
	{

		if (adcCoCo == true)
		{
			counter++;
			/* Process the readings to get the value in Amperes */
			gfCurrentValue = ((float) gu16CurrentRawValue)*fCurrentPol[0] + fCurrentPol[1];
		//	u16CurrentVector[counter] = (uint16_t) (gfCurrentValue*1000);

			/* Clear conversion done interrupt flag */
			adcCoCo = false;
			/* Trigger PDB timer */
			PDB_DRV_SoftTriggerCmd(PDB_INSTANCE);

			/* RMS */
			RMSCurrentAux += gfCurrentValue*gfCurrentValue;

			gbRMSCoCo = false;

			if (counter == RMS_BUFFER_SIZE){
				gbRMSCoCo = true;
				gfRMSCurrent = sqrt(RMSCurrentAux/counter);
				RMSCurrentAux = 0;
				counter = 0;
			}

		//k	FMSTR_Recorder();
			 /* Acknowledge the command */
			//                FMSTR_AppCmdAck(0);
	        /* Handle the protocol decoding and execution */
	     //k   FMSTR_Poll();


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
