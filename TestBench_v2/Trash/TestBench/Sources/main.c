
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
#include "lpuart_gasboard.h"

#include "Init.h"
#include "Computations.h"

volatile int exit_code = 0;
/* User includes (#include below this line is not maintained by Processor Expert) */


#include <string.h>
#include <stdint.h>
#include <stdbool.h>




/* ADC Readings */
#define ADC_INSTANCE 	0UL
#define ADC_CHN			0U /* PTA0 */
#define ADC_VREFH  		3.3f
#define ADC_VREFL  		0.0f
#define PDB_INSTANCE	0UL
#define ADC_COCO_IO		PTD
#define ADC_COCO_PIN	7
#define RMS_COCO_IO		PTE
#define RMS_COCO_PIN	1
#define RMS_BUFFER_SIZE 500// 0.2 sec 20kHz

/* LPIT channel used */
#define LPIT_CHANNEL_HDI	    0UL
#define LPIT_CHANNEL_GAS	    1UL
#define LPIT_Channel_IRQn_HDI   LPIT0_Ch0_IRQn
#define LPIT_Channel_IRQn_GAS   LPIT0_Ch1_IRQn

/* I2C Communication */
#define I2C_BUFFER_SIZE 2U
#define I2C_TIMEOUT 1U

/* Gasboard LPUART Communication */
#define TX_BUFFER_SIZE 4U
#define RX_BUFFER_SIZE 12U
#define LPUART_TIMEOUT 100U
#define SD_BUFFER_SIZE 8U




uint8_t prio_gas, prio_adc;

/* -----------------------  ADC  -----------------------  */

/* Variable to store the raw value from ADC conversion. Global to be modified inside the interrupt */
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

/* Number total of conversions used to compute one RMS value. Global to allow the change in FreeMaster */
uint16_t gu16RMSBuffer = RMS_BUFFER_SIZE;

/* Flag used to store if an ADC IRQ was executed */
volatile bool gbADCConvDone = false;

/* Flag used to toggle the pin when the program enters the ADC interrupt routine */
volatile bool gbCocoFlag = false;

/* Flag used to toggle the pin when the program finishes the RMS calculation */
volatile bool gbRMSCoCo = false;



/* -----------------------  I2C  -----------------------  */

/* Pressure measured by the HDIB002AUY8P5 sensor through I2C communication in milibars.*/
uint16_t gu16PressureHDI;

/* Declaration of the LPI2C transfer buffer */
uint8_t  u8I2CBufferHDI[I2C_BUFFER_SIZE];

/* Flag used to store if an I2C ISR was executed*/
volatile bool gbI2CDone = false;


/* ---------------------  Gasboard  ---------------------  */

/* Values measured by the Gasboard 7500H sensor through UART communication. */

/* O2 Concentration in % */
float gfO2concentration;

/* O2 Flow in Liters per minute */
float gfO2flow;

/* O2 Temperature in Celsius */
float gfO2temperature;

/* Declare buffer used to store the received data */
uint8_t	RX_buffer[RX_BUFFER_SIZE];

/* Read O2 concentrations on the extended mode (extended mode = 0% to 100%, default mode = 20.5% to 95.6% ) */
uint8_t	 TX_buffer[TX_BUFFER_SIZE] = {0x11, 0x01, 0x01, 0xED};
// Obs: This must be declared as global, otherwise it changes its value during the cycles

/* Flag used to store if an Gasboard ISR was executed*/
volatile bool gbGASDone = false;

volatile bool gbGASfalg;


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
void LPIT_ISR_HDI(void)
{
	/* Clear LPIT channel flag */
	LPIT_DRV_ClearInterruptFlagTimerChannels(INST_LPIT1, (1 << LPIT_CHANNEL_HDI));

	gbGASfalg = !gbGASfalg;
	 /* Request data from the bus slave */
  //   LPI2C_DRV_MasterReceiveDataBlocking(INST_LPI2C1, u8I2CBufferHDI, I2C_BUFFER_SIZE, true, I2C_TIMEOUT);

	/* Set I2C communication complete flag */
	gbI2CDone = true;

}

void LPIT_ISR_GAS(void)
{
	/* Clear LPIT channel flag */
	LPIT_DRV_ClearInterruptFlagTimerChannels(INST_LPIT1, (1 << LPIT_CHANNEL_GAS));

    /* Request Data from Gasboard */
  //LPUART_DRV_SendData(INST_LPUART_GASBOARD, TX_buffer, TX_BUFFER_SIZE);

	/* Receive Data */
		LPUART_DRV_ReceiveDataBlocking(INST_LPUART_GASBOARD, &RX_buffer, RX_BUFFER_SIZE, 200u);
	//LPUART_DRV_ReceiveData(INST_LPUART_GASBOARD, &RX_buffer, RX_BUFFER_SIZE);
	/* Set Gasboard communication complete flag */
	gbGASDone = true;
	gbGASfalg = !gbGASfalg;

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

	/* -----------------------  ADC  -----------------------  */
	/* Polynomial parameters from data fit to convert the raw ADC value to the actual current in Amperes*/
	const float fCurrentPol[2] = {0.00169404924302870, -0.0138943629841409};
	//const float fVoltagePol[2] = {0.00880332914534114, -0.273383180824596};

	/* Sum of the squared values of the current */
	float RMSCurrentAux = 0;

	/* -----------------------  I2C  -----------------------  */


	/* Allocate memory for the LPI2C driver state structure */
	lpi2c_master_state_t lpi2c1MasterState;


	/* Variable used for the loop that initializes the I2C data buffer */
	uint16_t i;

	/* Sensitivity of the HDI sensor */
	uint64_t HDISensitivity = SensitivyHDI ();

	/* ---------------------  Gasboard  ---------------------  */


	gbGASfalg = false;

	/* Stores only the significant bytes of the read data */
	float fsigData[SD_BUFFER_SIZE];



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

	/*Initialize LPIT Instance*/
	Init_LPIT();

    /* Install LPIT_ISR as LPIT interrupt handler for HDI */
   // INT_SYS_InstallHandler(LPIT_Channel_IRQn_HDI, &LPIT_ISR_HDI, (isr_t *)0);
	/* Enable  interrupt */
	//INT_SYS_EnableIRQ(LPIT_Channel_IRQn_HDI);

    /* Install LPIT_ISR as LPIT interrupt handler for Gasboard */
    INT_SYS_InstallHandler(LPIT_Channel_IRQn_GAS, &LPIT_ISR_GAS, (isr_t *)0);
	/* Enable  interrupt */
	INT_SYS_EnableIRQ(LPIT_Channel_IRQn_GAS);

    /* Initialize LPI2C Master configuration */
    LPI2C_DRV_MasterInit(INST_LPI2C1, &lpi2c1_MasterConfig0, &lpi2c1MasterState);

    /*Initialize Gasboard UART Instance*/
    LPUART_DRV_Init(INST_LPUART_GASBOARD, &lpuart_gasboard_State, &lpuart_gasboard_InitConfig0);

    INT_SYS_SetPriority(adcIRQ,2u);
    INT_SYS_SetPriority(LPIT_Channel_IRQn_GAS, 2u);
 prio_gas = INT_SYS_GetPriority(LPIT_Channel_IRQn_GAS);
 prio_adc = INT_SYS_GetPriority(adcIRQ);



    /* Start counters*/

    /* Trigger PDB counter to perform the ADC conversions */
	PDB_DRV_SoftTriggerCmd(PDB_INSTANCE);

    /* Start LPIT0 channel 0 counter */
  //  LPIT_DRV_StartTimerChannels(INST_LPIT1, (1 << LPIT_CHANNEL_HDI));

    /* Start LPIT0 channel 0 counter */
    LPIT_DRV_StartTimerChannels(INST_LPIT1, (1 << LPIT_CHANNEL_GAS));

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
		/* -----------------------  ADC  -----------------------  */
		/* Finished the ADC conversion routine */
		if (gbADCConvDone)
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
				gfRMSCurrent = (float) sqrt(RMSCurrentAux/gu16NrConvDone);

				/*Update the RMS index */
				gu16RMSIdx ++;

				/* Clear the squared sum u8I2CBufferHDI */
				RMSCurrentAux = 0;

				/* Clear the counter of the RMS */
				gu16NrConvDone = 0;
			}

			/* Clear conversion done interrupt flag */
			gbADCConvDone = false;

		} // if (gbADCConvDone == true)

		/* -----------------------  I2C  -----------------------  */
		 if(gbI2CDone)
		 {

			 /* Convert the counts to pressure in milibars*/
			 gu16PressureHDI = PressureHDI (u8I2CBufferHDI, HDISensitivity);

			 /* Clear conversion done interrupt flag */
			gbI2CDone = false;

			/* Clear the buffer to prepare it for the next operation */
			for (i = 0u; i < I2C_BUFFER_SIZE; i++)
			{
				u8I2CBufferHDI[i] = 0u;
			}

		  } //  if(gbI2CDone)

		  /* ---------------------  Gasboard-----------------------  */
		  if(gbGASDone)
		  {


			  /* Ignore bits without significant data and convert the others to float */
			  				for (uint8_t i = 0; i<SD_BUFFER_SIZE; i++)
			  				{
			  					fsigData[i] = (float)RX_buffer[i+4];
			  				}

			  				/* Compute the characteristics of the flow */
			  				gfO2concentration = (fsigData[0]*256 + fsigData[1])/10; //(Vol %)
			  				gfO2flow          = (fsigData[2]*256 + fsigData[3])/10; //(L/min)
			  				gfO2temperature   = (fsigData[4]*256 + fsigData[5])/10; //(C)



				/* Compute the characteristics of the flow */
			//		gfO2concentration = (RX_buffer[3]*256 + RX_buffer[4])/10; //(Vol %)
			//		gfO2flow          = (RX_buffer[5]*256 + RX_buffer[6])/10; //(L/min)
				//	gfO2temperature   = (RX_buffer[7]*256 + RX_buffer[8])/10; //(C)


				 /* Clear conversion done interrupt flag */
				gbGASDone = false;

		  }// if(gbGASDone)




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
