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

#define GPIO_PORT	PORTA
#define PCC_CLOCK	PCC_PORTA_CLOCK
#define ONOFF		3U
#define PLUS		2U
#define MINUS		9U
#define BELL		8U

#define LPIT0_CHANNEL	    0UL
#define LPIT_Channel_IRQn   LPIT0_Ch0_IRQn

/* User includes (#include below this line is not maintained by Processor Expert) */
/* Global variables for each button's state and counter */
typedef enum {
    BUTTON_STATE_IDLE,
    BUTTON_STATE_PRESSED,
    BUTTON_STATE_RELEASED,
    BUTTON_STATE_WAIT,
} button_state_t;
volatile button_state_t onoff_state = BUTTON_STATE_IDLE;
volatile uint32_t onoff_counter = 0;

volatile button_state_t bell_state = BUTTON_STATE_IDLE;
volatile uint32_t bell_counter = 0;
volatile uint32_t bell_duration = 6000000; /* Default press duration */

volatile button_state_t plus_state = BUTTON_STATE_IDLE;
volatile uint32_t plus_counter = 0;

volatile button_state_t minus_state = BUTTON_STATE_IDLE;
volatile uint32_t minus_counter = 0;

void update_button_state(volatile button_state_t* state, volatile uint32_t*counter, uint32_t pin, uint32_t release_delay) {
    /* State machine */
    switch (*state) {
        case BUTTON_STATE_IDLE:
            PINS_DRV_WritePin(PTA, pin, 0); /* Begin button press */
            *state = BUTTON_STATE_PRESSED;
             /* Set the press delay */
            break;

        case BUTTON_STATE_PRESSED:
            if (*counter > 0) {
                (*counter)--;
            } else {
                *state = BUTTON_STATE_RELEASED;
                *counter = release_delay; /* Set the release delay */
            }
            break;

        case BUTTON_STATE_RELEASED:
            if (*counter > 0) {
                (*counter)--;
            } else {
                PINS_DRV_WritePin(PTA, pin, 1); /* End button press */
                *state = BUTTON_STATE_IDLE;
            }
            break;

        default:
            break;
    }
}

void LPIT0_Ch0_IRQHandler(void)
{
    /* Clear interrupt flag.*/
    LPIT_DRV_ClearInterruptFlagTimerChannels(INST_LPIT1, (1U << LPIT0_CHANNEL));

    update_button_state(&onoff_state, &onoff_counter, ONOFF, 6000000);
    update_button_state(&bell_state, &bell_counter, BELL, bell_duration);
    update_button_state(&plus_state, &plus_counter, PLUS, 900000);
    update_button_state(&minus_state, &minus_counter, MINUS, 900000);
}

int main(void)
{
  /* Write your local variable definition here */

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
    chConfig.periodUnits = LPIT_PERIOD_UNITS_COUNTS;
    chConfig.period = 48000000; // Adjust this to change the frequency of the interrupt
    chConfig.triggerSource = LPIT_TRIGGER_SOURCE_INTERNAL;
    chConfig.triggerSelect = 0U;
    chConfig.enableReloadOnTrigger = false;
    chConfig.enableStopOnInterrupt = false;
    chConfig.enableStartOnTrigger = false;
    chConfig.chainChannel = false;
    chConfig.isInterruptEnabled = true;
    LPIT_DRV_InitChannel(INST_LPIT1, 0U, &chConfig); // 0U is the channel number
    INT_SYS_InstallHandler(LPIT0_Ch0_IRQn, LPIT0_Ch0_IRQHandler, (isr_t *)0);
    PINS_DRV_Init(NUM_OF_CONFIGURED_PINS, g_pin_mux_InitConfigArr);
    PINS_DRV_SetPinDirection(GPIO_PORT,ONOFF,1);
       PINS_DRV_SetPinDirection(GPIO_PORT,PLUS,1);
       PINS_DRV_SetPinDirection(GPIO_PORT,MINUS,1);
       PINS_DRV_SetPinDirection(GPIO_PORT,BELL,1);
       PINS_DRV_WritePin(GPIO_PORT,ONOFF,1);
       PINS_DRV_WritePin(GPIO_PORT,BELL,1);
       PINS_DRV_WritePin(GPIO_PORT,PLUS,1);
       PINS_DRV_WritePin(GPIO_PORT,MINUS,1);
    for(;;) {
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

