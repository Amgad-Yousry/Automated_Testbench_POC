/*
 * Init.h
 *
 *  Created on: Jun 2, 2023
 *      Author: kamil
 */

#ifndef SOURCES_INIT_H_
#define SOURCES_INIT_H_


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
