/*
 * Init.c
 *
 *  Created on: Jun 2, 2023
 *      Author: kamil
 */

#include "../../ADC_PDB_FreeMaster_v7/Sources/Init.h"

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

/* ADC */
#define ADC_INSTANCE 	0UL
#define ADC_CHN			0U /* PTA0 */
#define ADC_VREFH  		3.3f
#define ADC_VREFL  		0.0f
#define PDB_INSTANCE	0UL
#define ADC_COCO_IO		PTD
#define ADC_COCO_PIN	7
#define RMS_COCO_IO		PTE
#define RMS_COCO_PIN	1

/* LPIT channel used */
#define LPIT_CHANNEL_HDI	    0UL
#define LPIT_CHANNEL_GAS	    1UL



#define OUTPUT_DIR 1

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
	    LPIT_DRV_Init(INST_LPIT1, &lpit1_InitConfig);
	    /* Initialize LPIT channel 0 and configure it as a periodic counter
	     * which is used to generate an interrupt every second.
	     */
	    LPIT_DRV_InitChannel(INST_LPIT1, LPIT_CHANNEL_HDI, &lpit1_ChnConfig_HDI);
	    LPIT_DRV_InitChannel(INST_LPIT1, LPIT_CHANNEL_GAS, &lpit1_ChnConfig_Gasboard);


}



/* Initialize LPI2C peripheral*/
void Init_LPI2C(void)
{

}
