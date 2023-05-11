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
#include "lpit1.h"
#include "clockMan1.h"
#include "pin_mux.h"
#include <stdint.h>
#include <stdbool.h>
  volatile int exit_code = 0;
#if CPU_INIT_CONFIG
  #include "Init_Config.h"
#endif
/* User includes (#include below this line is not maintained by Processor Expert) */
#define EVB
#define LED0_PIN_INDEX  0U
#define LED_GPIO_PORT	PTD
#define panel 	    PORTA
#define GPIO_PORT	PTA
#define PCC_CLOCK	PCC_PORTA_CLOCK
#define ONOFF		3U
#define PLUS		2U
#define MINUS		9U
#define BELL		8U

unsigned char  bells =0;
unsigned char  power =0;
unsigned char  plus =0;
unsigned char  minus =0;
unsigned char increments=0;
unsigned char automate=0;
volatile int keeppress;
#define LPIT_CHANNEL	    0UL
#define LPIT_Channel_IRQn   LPIT0_Ch0_IRQn

/********************* Interrupt service routine ISR functions declarations*******************************/
/* first ISR from example, toggling LEDS*/
void LPIT_ISR(void)
{
	/* Clear LPIT channel flag */
	LPIT_DRV_ClearInterruptFlagTimerChannels(INST_LPIT1, (1 << LPIT_CHANNEL));
	/* Toggle LED0 */
	PINS_DRV_TogglePins(LED_GPIO_PORT, (1 << LED0_PIN_INDEX));
}
/* the transparent sensor isr*/
void FLOWSMF_ISR(void)
{
	/* Clear LPIT channel flag */
	LPIT_DRV_ClearInterruptFlagTimerChannels(INST_LPIT1, (1 << LPIT_CHANNEL));

}
/*plus button*/
void PLUS_ISR(void)
{
	PINS_DRV_WritePin(GPIO_PORT,PLUS,0);

    PINS_DRV_WritePin(GPIO_PORT,PLUS,1);
	plus=0;
	/* Clear LPIT channel flag */
	LPIT_DRV_ClearInterruptFlagTimerChannels(INST_LPIT1, (1 << LPIT_CHANNEL));

}
/* minus button*/
void MINUS_ISR(void)
{
	PINS_DRV_WritePin(GPIO_PORT,MINUS,0);

	PINS_DRV_WritePin(GPIO_PORT,MINUS,1);
	minus=0;
	/* Clear LPIT channel flag */
	LPIT_DRV_ClearInterruptFlagTimerChannels(INST_LPIT1, (1 << LPIT_CHANNEL));

}
/* bell button*/
void BELL_ISR(void)
{
	PINS_DRV_WritePin(GPIO_PORT,BELL,0);
		 	      	  	PINS_DRV_WritePin(GPIO_PORT,BELL,1);
		 	      	  			bells=0;
	/* Clear LPIT channel flag */
	LPIT_DRV_ClearInterruptFlagTimerChannels(INST_LPIT1, (1 << LPIT_CHANNEL));

}
/* power button*/
void POWER_ISR(void)
{
	PINS_DRV_WritePin(GPIO_PORT,ONOFF,0);

	PINS_DRV_WritePin(GPIO_PORT,ONOFF,1);
			      	  			power=0;
	/* Clear LPIT channel flag */
	LPIT_DRV_ClearInterruptFlagTimerChannels(INST_LPIT1, (1 << LPIT_CHANNEL));

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

  /*** Processor Expert internal initialization. DON'T REMOVE THIS CODE!!! ***/
  #ifdef PEX_RTOS_INIT
    PEX_RTOS_INIT();                   /* Initialization of the selected RTOS. Macro is defined by the RTOS component. */
  #endif
  /*** End of Processor Expert internal initialization.                    ***/

  /* initialization */
    CLOCK_SYS_Init(g_clockManConfigsArr,   CLOCK_MANAGER_CONFIG_CNT,
                       g_clockManCallbacksArr, CLOCK_MANAGER_CALLBACK_CNT);
        CLOCK_SYS_UpdateConfiguration(0U, CLOCK_MANAGER_POLICY_AGREEMENT);

    	/* Initialize pins
    	 *	-	Setup pin used for LED(used as GPIO)
    	 */
        PINS_DRV_Init(NUM_OF_CONFIGURED_PINS, g_pin_mux_InitConfigArr);
        /* Set LED pin direction as output */
        PINS_DRV_SetPinsDirection(LED_GPIO_PORT, (1 << LED0_PIN_INDEX));
        /* Turn off LED0 */
         PINS_DRV_SetPins(LED_GPIO_PORT, (1 << LED0_PIN_INDEX));
         PINS_DRV_SetPinDirection(GPIO_PORT,ONOFF,1);
         PINS_DRV_SetPinDirection(GPIO_PORT,PLUS,1);
         PINS_DRV_SetPinDirection(GPIO_PORT,MINUS,1);
         PINS_DRV_SetPinDirection(GPIO_PORT,BELL,1);
         PINS_DRV_WritePin(GPIO_PORT,ONOFF,1);
         PINS_DRV_WritePin(GPIO_PORT,BELL,1);
         PINS_DRV_WritePin(GPIO_PORT,PLUS,1);
         PINS_DRV_WritePin(GPIO_PORT,MINUS,1);


         /***********************************************initializations provided in LPIT example*******************************************************/
         /* Initialize LPIT instance 0
         	 *	-	Reset and enable peripheral
         	 */
         LPIT_DRV_Init(INST_LPIT1, &lpit1_InitConfig);
             /* Initialize LPIT channel 0 and configure it as a periodic counter
              * which is used to generate an interrupt every second.
              */
         LPIT_DRV_InitChannel(INST_LPIT1, LPIT_CHANNEL, &lpit1_ChnConfig0);

             /* Install LPIT_ISR as LPIT interrupt handler */
  //INT_SYS_InstallHandler(LPIT_Channel_IRQn, &LPIT_ISR, (isr_t *)0);
             /* Start LPIT0 channel 0 counter */
         LPIT_DRV_StartTimerChannels(INST_LPIT1, (1 << LPIT_CHANNEL));
             /* Peripherals Initialization is complete, now the program will wait for
              * LPIT interrupt.
              */
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
