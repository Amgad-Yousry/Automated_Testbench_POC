/*
 * Computations.h
 *
 *  Created on: Jun 5, 2023
 *      Author: kamil
 */

#ifndef SOURCES_COMPUTATIONS_H_
#define SOURCES_COMPUTATIONS_H_

#include "Cpu.h"




/* Compute the Sensitivity of the HDI sensor */
uint64_t SensitivyHDI (void);

/* Compute the pressure from the HDI sensor */
uint64_t PressureHDI (uint8_t*  u8I2CBufferHDI, uint64_t sensitivity);

#endif /* SOURCES_COMPUTATIONS_H_ */
