/*
 * Init.c
 *
 *  Created on: Jun 2, 2023
 *      Author: kamil
 */

#include "Init.h"

#include "Cpu.h"
#include "pin_mux.h"
//#include "osif1.h"
#include "adConv1.h"
#include "lpTmr1.h"
#include "lpuart_gasboard.h"
#include "dmaController1.h"
#include "pdly1.h"
#include "pwrMan1.h"
#include "clockMan1.h"
#include "freemaster.h"
//#include "lpit1.h"
#include "lpi2c1.h"
#include "timing_pal1.h"
#include "LPSPI_MPR.h"

#include "Definition.h"


uint64_t u64LPITResolution;



/* Initialize pins */
void Init_pins(void)
{
	PINS_DRV_Init(NUM_OF_CONFIGURED_PINS, g_pin_mux_InitConfigArr);
	/* Set the pins to be toggled as output */
	PINS_DRV_SetPinDirection(ADC_COCO_IO, ADC_COCO_PIN, OUTPUT_DIR);
	PINS_DRV_SetPinDirection(RMS_COCO_IO, RMS_COCO_PIN, OUTPUT_DIR);

}


/* Initialize ADC peripheral*/
IRQn_Type Init_ADC(void)
{
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

		return adcIRQ;
}


/* Initialize PBD peripheral*/
void Init_PDB(void)
{

	int32_t u32PreTriggerDelay = 466U;
	int32_t u32ModulusValue = u32PreTriggerDelay + 1U;


	PDB_DRV_Init(PDB_INSTANCE, &pdly1_InitConfig0);
	PDB_DRV_ConfigAdcPreTrigger(PDB_INSTANCE, ADC_CHN, &pdly1_AdcTrigInitConfig0);
	PDB_DRV_SetTimerModulusValue(PDB_INSTANCE, u32ModulusValue);
	PDB_DRV_SetAdcPreTriggerDelayValue(PDB_INSTANCE, ADC_CHN, 0U, u32PreTriggerDelay);

	PDB_DRV_LoadValuesCmd(PDB_INSTANCE);

}

/* Initialize LPIT peripheral*/
void Init_LPIT(void)
{
	/* Initialize LPIT instance 0
		 *	-	Reset and enable peripheral
		 */
//	    LPIT_DRV_Init(INST_LPIT1, &lpit1_InitConfig);
	    /* Initialize LPIT channel 0 and configure it as a periodic counter
	     * which is used to generate an interrupt every second.
	     */
//	    LPIT_DRV_InitChannel(INST_LPIT1, LPIT_CHANNEL_HDI, &lpit1_ChnConfig_HDI);
	//    LPIT_DRV_InitChannel(INST_LPIT1, LPIT_CHANNEL_GAS, &lpit1_ChnConfig_Gasboard);


}



/* Initialize LPI2C peripheral*/
void Init_LPI2C(void)
{

}

/* Initialize Timing PAL peripheral */
void Init_PAL(void)
{
	/* Initialize TIMING over LPIT */
	TIMING_Init(INST_TIMING_PAL1, &timing_pal1_InitConfig);
	/* Get tick resolution in nanosecond unit for TIMING over LPIT */
	TIMING_GetResolution(INST_TIMING_PAL1, TIMER_RESOLUTION_TYPE_NANOSECOND, &u64LPITResolution);
}


/* Initialize Gasboard related peripheral */
void Init_GAS(void)
{
	 /*Initialize Gasboard UART Instance*/
	LPUART_DRV_Init(INST_LPUART_GASBOARD, &lpuart_gasboard_State, &lpuart_gasboard_InitConfig0);


	/* Start LPIT channel 0 counting with the period is 0.5 second,
	   the period in tick = the period in nanosecond / LPIT tick resolution in nanosecond */
	TIMING_StartChannel(INST_TIMING_PAL1, LPIT_CHANNEL_GAS, GAS_PERIOD_BY_NS/u64LPITResolution);


}

/* Initialize SFM related peripheral */
void Init_SFM(void)
{

    /* Start LPIT channel 0 counting with the period is 0.5 second,
    	   the period in tick = the period in nanosecond / LPIT tick resolution in nanosecond */
    TIMING_StartChannel(INST_TIMING_PAL1, LPIT_CHANNEL_SFM, SFM_PERIOD_BY_NS/u64LPITResolution);

}

/* Initialize CO2 related peripheral */
void Init_CO2(void)
{



    /* Start LPIT channel 2 counting with the period is 1 second,
    	   the period in tick = the period in nanosecond / LPIT tick resolution in nanosecond */
    TIMING_StartChannel(INST_TIMING_PAL1, LPIT_CHANNEL_CO2, CO2_PERIOD_BY_NS/u64LPITResolution);

}

/* Initialize MPR related peripheral */
void Init_MPR(void)
{

	   /* Start SPI Communication */



	    	/* Delays between the clock and the chip enable */
	    	LPSPI_DRV_MasterSetDelay(LPSPI_MPR, SPI_DELAY, SPI_DELAY, SPI_DELAY);


    /* Start LPIT channel 3 counting with the period is 1 second,
    	   the period in tick = the period in nanosecond / LPIT tick resolution in nanosecond */
    TIMING_StartChannel(INST_TIMING_PAL1, LPIT_CHANNEL_MPR, MPR_PERIOD_BY_NS/u64LPITResolution);

}




