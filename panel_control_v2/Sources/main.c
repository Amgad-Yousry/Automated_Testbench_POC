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
#include "lpuart1.h"
#include "clockMan1.h"
#include "pin_mux.h"
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include"automationdefinit.h"
#include"automationfunctions.h"
#if CPU_INIT_CONFIG
  #include "Init_Config.h"
#endif
/* User includes (#include below this line is not maintained by Processor Expert) */

/* User includes (#include below this line is not maintained by Processor Expert) */
/* Global variables for each button's state and counter */


void LPIT0_Ch0_IRQHandler(void)
{
    /* Clear interrupt flag.*/
    LPIT_DRV_ClearInterruptFlagTimerChannels(INST_LPIT1, (1U << LPIT0_CHANNEL));
    update_button_state(&onoff_state, &onoff_counter, ONOFF, &onoff_release_delay);
    update_button_state(&bell_state, &bell_counter, BELL, &bell_release_delay);
    update_button_state(&plus_state, &plus_counter, PLUS, &plus_release_delay );
    update_button_state(&minus_state, &minus_counter, MINUS, &minus_release_delay);
    autotimecounter(&minustime_state, &minus_state, &plustime_state);
    autotimecounter(&plustime_state, &plus_state, &minustime_state);
    updatecounter(&count_pm_init);
    p5handshake(&uart_state);
    updatespeedvalue();
    /*if(){   //essential condition that system doesn't shutdown before the start of the test
    	safety_power();
    }
*/

}

int main(void)
{

  /* Write your local variable definition here */
 consigne =0;
 bolusPerMinute=0;
 tauxOxygen=0;
 temperature=0 ;
 vitesseCompresseur=0;

  /*** Processor Expert internal initialization. DON'T REMOVE THIS CODE!!! ***/
  #ifdef PEX_RTOS_INIT
    PEX_RTOS_INIT();                   /* Initialization of the selected RTOS. Macro is defined by the RTOS component. */
  #endif
  /*** End of Processor Expert internal initialization.                    ***/

  /* Write your code here */

    CLOCK_SYS_Init(g_clockManConfigsArr, CLOCK_MANAGER_CONFIG_CNT,
            						g_clockManCallbacksArr, CLOCK_MANAGER_CALLBACK_CNT);
      CLOCK_SYS_UpdateConfiguration(0U, CLOCK_MANAGER_POLICY_AGREEMENT);

    /* Initialize LPIT */
    lpit_user_config_t lpitConfig;
    lpitConfig.enableRunInDebug = false;
    lpitConfig.enableRunInDoze = true;
    LPIT_DRV_Init(INST_LPIT1, &lpitConfig);
    /* Initialize LPIT channel */
    lpit_user_channel_config_t chConfig;
    chConfig.timerMode = LPIT_PERIODIC_COUNTER;
    chConfig.periodUnits = LPIT_PERIOD_UNITS_MICROSECONDS;
    chConfig.period =10000; // update every 1000 microseconds
    chConfig.triggerSource = LPIT_TRIGGER_SOURCE_EXTERNAL;
    chConfig.triggerSelect = 0U;
    chConfig.enableReloadOnTrigger = false;
    chConfig.enableStopOnInterrupt = false;
    chConfig.enableStartOnTrigger = false;
    chConfig.chainChannel = false;
    chConfig.isInterruptEnabled = true;

    LPIT_DRV_InitChannel(INST_LPIT1, 0U, &chConfig); // 0U is the channel number
    INT_SYS_InstallHandler(LPIT0_Ch0_IRQn, LPIT0_Ch0_IRQHandler, (isr_t *)0);

    PINS_DRV_Init(NUM_OF_CONFIGURED_PINS, g_pin_mux_InitConfigArr);
    PINS_DRV_SetPinDirection(GPIO_PORT1,ONOFF,1);
    PINS_DRV_SetPinDirection(GPIO_PORT1,PLUS,1);
    PINS_DRV_SetPinDirection(GPIO_PORT1,MINUS,1);
    PINS_DRV_SetPinDirection(GPIO_PORT1,BELL,1);
LPIT_DRV_StartTimerChannels(INST_LPIT1,(1U << LPIT0_CHANNEL));
LPUART_DRV_Init(INST_LPUART1, &lpuart1_State, &lpuart1_InitConfig0);



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
