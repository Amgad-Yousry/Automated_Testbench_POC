/*
 * Init.h
 *
 *  Created on: Jun 2, 2023
 *      Author: kamil
 */

#ifndef SOURCES_INIT_H_
#define SOURCES_INIT_H_

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

/* Initialize pins */
void Init_pins(void);

/* Initialize ADC peripheral*/
IRQn_Type Init_ADC(void);

/* Initialize PBD peripheral*/
void Init_PDB(void);

/* Initialize LPIT peripheral*/
void Init_LPIT(void);

/* Initialize LPI2C peripheral*/
void Init_LPI2C(void);




#endif /* SOURCES_INIT_H_ */
