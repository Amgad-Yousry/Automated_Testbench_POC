/* ###################################################################
**     Filename    : main.c
**     Processor   : S32K14x
**     Abstract    :
**         Main module.
**         This module contains user's application code.
**     Settings    :
**     Contents    :
**         No public methods
**
** ###################################################################*/
/*!
** @file main.c
** @version 01.00
** @brief
**         Main module.
**         This module contains user's application code.
*/
/*!
**  @addtogroup main_module main module documentation
**  @{
*/
/* MODULE main */


/* Including necessary module. Cpu.h contains other modules needed for compiling.*/
#include "Cpu.h"
#include "clockMan1.h"
#include "pin_mux.h"
#include <stdint.h>
#include <stdbool.h>

#define EVB
	#define panel 	    PORTA
	#define GPIO_PORT	PTA
	#define PCC_CLOCK	PCC_PORTA_CLOCK
	#define ONOFF		3U
	#define PLUS		2U
    #define MINUS		9U
    #define BELL		8U
  long del=0;
  long del1=0;
void delay(volatile int cycles)
{
    /* Delay function - do nothing for a number of cycles */
    while(cycles--);
}

void autopulse()
{
PINS_DRV_WritePin(GPIO_PORT,BELL,1);
 delay(10000000);
PINS_DRV_WritePin(GPIO_PORT,BELL,0);
PINS_DRV_WritePin(GPIO_PORT,MINUS,1);
	 delay(2000000);
PINS_DRV_WritePin(GPIO_PORT,MINUS,0);
PINS_DRV_WritePin(GPIO_PORT,MINUS,1);
	 delay(2000000);
PINS_DRV_WritePin(GPIO_PORT,MINUS,0);
PINS_DRV_WritePin(GPIO_PORT,BELL,1);
delay(5000000);
PINS_DRV_WritePin(GPIO_PORT,BELL,0);
PINS_DRV_WritePin(GPIO_PORT,BELL,1);
delay(5000000);
PINS_DRV_WritePin(GPIO_PORT,BELL,0);
	}
  volatile int exit_code = 0;
  unsigned char  bells =0;
  unsigned char  power =0;
  unsigned char  plus =0;
  unsigned char  minus =0;
  unsigned char increments=0;
  unsigned char automate=0;
  volatile int keeppress;

/* User includes (#include below this line is not maintained by Processor Expert) */
/*!
  \brief The main function for the project.
  \details The startup initialization sequence is the following:
 * - startup asm routine
 * - main()
*/
int main(void)
{
  /* Write your local variable definition here */

  /*** Processor Expert internal initialization. DON'T REMOVE THIS CODE!!! ***/
  #ifdef PEX_RTOS_INIT
    PEX_RTOS_INIT();                   /* Initialization of the selected RTOS. Macro is defined by the RTOS component. */
  #endif
  /*** End of Processor Expert internal initialization.                    ***/

  /* initialization */

CLOCK_SYS_Init(g_clockManConfigsArr, CLOCK_MANAGER_CONFIG_CNT,
      						g_clockManCallbacksArr, CLOCK_MANAGER_CALLBACK_CNT);
    CLOCK_SYS_UpdateConfiguration(0U, CLOCK_MANAGER_POLICY_AGREEMENT);
    /* pins initialization */
    PINS_DRV_Init(NUM_OF_CONFIGURED_PINS, g_pin_mux_InitConfigArr);
    /*PINS_DRV_SetPinsDirection(GPIO_PORT, ( (1 << ONOFF) | (1 << PLUS)| (1 << MINUS)| (1 << BELL)));*/
   PINS_DRV_SetPinDirection(GPIO_PORT,ONOFF,1);
   PINS_DRV_SetPinDirection(GPIO_PORT,PLUS,1);
   PINS_DRV_SetPinDirection(GPIO_PORT,MINUS,1);
   PINS_DRV_SetPinDirection(GPIO_PORT,BELL,1);
   PINS_DRV_WritePin(GPIO_PORT,ONOFF,1);
   PINS_DRV_WritePin(GPIO_PORT,BELL,1);
   PINS_DRV_WritePin(GPIO_PORT,PLUS,1);
   PINS_DRV_WritePin(GPIO_PORT,MINUS,1);
for(;;) {
	if(power==1)
		      	  	  	  	  	  {
		      	  		  	PINS_DRV_WritePin(GPIO_PORT,ONOFF,0);
		      	  		delay(6000000);
		      	  	if(keeppress==1)
		      	  		 	      	{
		      	  		 	      		delay(18000000);
		      	  		 	      		keeppress = 0;
		      	  		 	      	}
		      	  	PINS_DRV_WritePin(GPIO_PORT,ONOFF,1);
		      	  			power=0;
		      	  	  	  	  	  }
	if(plus==1)

			 	      	  	  	  	  	  {
			 	      	 PINS_DRV_WritePin(GPIO_PORT,PLUS,0);
			 	      	 delay(900000);
			 	      	if(keeppress==1)
			 	      		 	      	{
			 	      		 	      		delay(18000000);
			 	      		 	      		keeppress = 0;
			 	      		 	      	}
			 	      	 PINS_DRV_WritePin(GPIO_PORT,PLUS,1);
			 	      	  		plus=0;
			 	      	  	  	  	  	  }

	 if(minus==1)
		 		 	      	  	  	  	  	  {
		 		 	      	  	PINS_DRV_WritePin(GPIO_PORT,MINUS,0);
		 		 	      	  	delay(800000);
		 		 	      	if(keeppress==1)
		 		 	      			 	  {
		 		 	      			 	    delay(del);
		 		 	      			 	     keeppress = 0;
		 		 	      			 	      		 	      	}
		 		 	      	  	PINS_DRV_WritePin(GPIO_PORT,MINUS,1);
		 		 	      	  			minus=0;
		 		 	      	  	  	  	  	  }
	 if(bells==1)
	 	      	  	  	  	  {
	 	      	  	PINS_DRV_WritePin(GPIO_PORT,BELL,0);
	 	      	  	delay(6000000);
	 	      	if(keeppress==1)
	 	      	{
	 	      		delay(18000000);
	 	      		keeppress = 0;
	 	      	}
	 	      	  	PINS_DRV_WritePin(GPIO_PORT,BELL,1);
	 	      	  			bells=0;
	 	      	  	  	  	  }
	 if(automate==1)
	                                    {
		                        autopulse();
		                        automate=0;
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
