
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
#include "adConv1.h"
#include "lpTmr1.h"
#include "lpuart1.h"
#include "dmaController1.h"
#include "pdly1.h"
#include "pwrMan1.h"
#include "clockMan1.h"
#include "freemaster.h"
#include "lpit1.h"
#include "lpi2c1.h"

#include "Init.h"

volatile int exit_code = 0;
/* User includes (#include below this line is not maintained by Processor Expert) */
#include "helper_functions.h"




#include <string.h>
#include <stdint.h>
#include <stdbool.h>



#define RMS_BUFFER_SIZE 500// 0.2 sec 20kHz
#define I2C_BUFFER_SIZE 2U
#define I2C_TIMEOUT 1U

/* This example is setup to work by default with EVB. To use it with other boards
   please comment the following line
*/

#define EVB

#ifdef EVB
	#define ADC_INSTANCE 	0UL
	#define ADC_CHN			0U /* PTB1 */
	#define ADC_VREFH  		3.3f
	#define ADC_VREFL  		0.0f
	#define PDB_INSTANCE	0UL
	#define ADC_COCO_IO		PTD
	#define ADC_COCO_PIN	7
	#define RMS_COCO_IO		PTE
	#define RMS_COCO_PIN	1
	/* LPIT channel used */
	#define LPIT_CHANNEL	    0UL
	#define LPIT_Channel_IRQn   LPIT0_Ch0_IRQn

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


// Pressure measured by the HDIB002AUY8P5 sensor through I2C communication in milibars.
	uint16_t pressure_hdi_i2c;

/* Declaration of the LPI2C transfer buffer */
   uint8_t  buffer[I2C_BUFFER_SIZE];

   volatile bool gbI2CDone = false;



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
 * @brief: LPIT interrupt handler.
 * 	       When an interrupt occurs clear channel flag and toggle LED0
 */
void LPIT_ISR(void)
{
	/* Clear LPIT channel flag */
	LPIT_DRV_ClearInterruptFlagTimerChannels(INST_LPIT1, (1 << LPIT_CHANNEL));

	gbI2CDone = true;

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

	// Number of counts read by the sensor
	uint16_t counts_hdi; // Would it be better to send a float?


	/* Allocate memory for the LPI2C driver state structure */
	lpi2c_master_state_t lpi2c1MasterState;


	/* Variable used for the loop that initializes the data buffer */
	uint16_t i;


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


	/* Initialize pins */
	Init_pins();


	/*Initialize ADC Instance*/
	IRQn_Type adcIRQ = Init_ADC();

	/* The interrupt trigger is the ADC Coco flag, thus it enters the IRQ when the conversion is done*/
	INT_SYS_InstallHandler(adcIRQ, &ADC_IRQHandler, (isr_t*) 0);

	/* Enable ADC 1 interrupt */
	INT_SYS_EnableIRQ(adcIRQ);


	/*Initialize PDB Instance*/
	Init_PDB();


	/* Power mode configuration for RUN mode */
	POWER_SYS_Init(&powerConfigsArr, 0, &powerStaticCallbacksConfigsArr,0);


	Init_LPIT();
    /* Install LPIT_ISR as LPIT interrupt handler */
    INT_SYS_InstallHandler(LPIT_Channel_IRQn, &LPIT_ISR, (isr_t *)0);
    /* Start LPIT0 channel 0 counter */
    LPIT_DRV_StartTimerChannels(INST_LPIT1, (1 << LPIT_CHANNEL));


    /* Initialize LPI2C Master configuration */
    LPI2C_DRV_MasterInit(INST_LPI2C1, &lpi2c1_MasterConfig0, &lpi2c1MasterState);
    //I2C address of the sensor (0x78)
    const uint16_t address_ = 120;
    LPI2C_DRV_MasterSetSlaveAddr(INST_LPI2C1, address_, false);

    // Parameters to compute the actual pressure based on the number of counts
	 //Pressure range
	 const uint64_t Pmax = 2000; //mbar
	 const uint64_t Pmin = 0;

	 //Digital range
	 const uint64_t Out_max_d = 29490;
	 const uint64_t Out_min_d = 3277;

	 // Check on the datasheet the technical name of this variable
	 uint64_t S;

	 S = (Out_max_d - Out_min_d)/(Pmax-Pmin);


	 PDB_DRV_SoftTriggerCmd(PDB_INSTANCE);


	/* Infinite loop
	 * 	-	Wait for ADC conversion complete interrupt,
	 * 		then:
	 * 			 compute the actual current value,
	 * 			 calculate the RMS value after an predetermined number of measurements,
	 * 			 toggle the pin referent to a new RMS conversion,
	 * 			 trigger the PDB timer.
	 */


	while (true)
	{
		/* Finished the ADC conversion routine */
		if (gbADCConvDone == true)
		{

			/* Update the counter of the number of conversions done */
			gu16NrConvDone++;

			/* Process the readings to get the value in Amperes */
			gfCurrentValue = ((float) gu16CurrentRawValue)*fCurrentPol[0] + fCurrentPol[1];

			/* Compute the sum of the squared values of current needed to the RMS computation */
			RMSCurrentAux += gfCurrentValue*gfCurrentValue;

			/* After a predefined number of readings, compute the RMS */
			if (gu16NrConvDone == gu16RMSBuffer)
			{
				/* Toggle the pin to indicate the RMS computation was done */
				gbRMSCoCo = !gbRMSCoCo;
				PINS_DRV_WritePin(RMS_COCO_IO, RMS_COCO_PIN, gbRMSCoCo);

				/* Compute the current RMS value */
				gfRMSCurrent = sqrt(RMSCurrentAux/gu16NrConvDone);

				/*Update the RMS index */
				gu16RMSIdx ++;

				/* Clear the squared sum buffer */
				RMSCurrentAux = 0;

				/* Clear the counter of the RMS */
				gu16NrConvDone = 0;
			}

			/* Clear conversion done interrupt flag */
			gbADCConvDone = false;

		} // if (gbADCConvDone == true)

		 if(gbI2CDone)
		 {
			 /* Request data from the bus slave */
			 LPI2C_DRV_MasterReceiveDataBlocking(INST_LPI2C1, buffer, I2C_BUFFER_SIZE, true, I2C_TIMEOUT);


			// Compute the pressure based on the number of counts read
			counts_hdi = (buffer[0]<<8)|buffer[1];
			pressure_hdi_i2c = (counts_hdi - Out_min_d)/S + Pmin;
			gbI2CDone = false;

			/* Clear the buffer to prepare it for the next operation */
			for (i = 0u; i < I2C_BUFFER_SIZE; i++)
			{
				buffer[i] = 0u;
			}

		  } //  if(gbI2CDone)


	} // while (true)



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
