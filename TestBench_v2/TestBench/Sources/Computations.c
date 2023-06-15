/*
 * Computations.c
 *
 *  Created on: Jun 5, 2023
 *      Author: kamil
 */

#include "Cpu.h"
#include "Computations.h"

 /* Parameters to compute the actual pressure based on the number of counts of the HDI sensor */
 /*Pressure range */
 const uint64_t Pmax = 2000; //mbar
 const uint64_t Pmin = 0;

 /* Digital range */
 const uint64_t Out_max_d = 29490;
 const uint64_t Out_min_d = 3277;

uint64_t SensitivyHDI (void){

	 /* Sensitivity */
	 uint64_t sensitivity;
	 sensitivity = (Out_max_d - Out_min_d)/(Pmax-Pmin);

	 return sensitivity;
}


/* Compute the pressure based on the number of counts read */
uint64_t PressureHDI (uint8_t*  u8I2CBufferHDI, uint64_t sensitivity){
	/* Number of counts read by the sensor */
	uint16_t u16CountsHDI;
	uint16_t gu16PressureHDI;

	u16CountsHDI = (u8I2CBufferHDI[0]<<8)|u8I2CBufferHDI[1];
	gu16PressureHDI = (u16CountsHDI - Out_min_d)/sensitivity + Pmin;

	return gu16PressureHDI;
}
