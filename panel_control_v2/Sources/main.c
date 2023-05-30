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
#define GPIO_PORT1	PTA
#define PCC_CLOCK	PCC_PORTA_CLOCK
#define ONOFF		17U
#define PLUS		11U
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
typedef enum {
    TIME_STATE_IDLE,
    TIME_STATE_PRESSED,
} timecount_state_t;
/********************buttons state machine declarations************************/
volatile button_state_t onoff_state = BUTTON_STATE_IDLE;
volatile uint32_t onoff_counter = 0;
 uint32_t onoff_release_delay=200;

volatile button_state_t bell_state = BUTTON_STATE_IDLE;
volatile uint32_t bell_counter = 0;
uint32_t bell_release_delay = 300; /* Default press duration */

volatile button_state_t plus_state = BUTTON_STATE_IDLE;
volatile timecount_state_t plustime_state = TIME_STATE_IDLE;
volatile uint32_t plus_counter = 0;
 uint32_t plus_release_delay=100;

volatile button_state_t minus_state = BUTTON_STATE_IDLE;
volatile timecount_state_t minustime_state = TIME_STATE_IDLE;
volatile uint32_t minus_counter = 0;
uint32_t minus_release_delay=100;
/************************auto increment or decrement**********************/
uint32_t   autotime_press_init =0; // Controls initialization of the 15-minute plus-minus button press
volatile uint32_t autotime_press_counter=900;
volatile uint32_t autotime_counter = 0;

//*************** settings increment decrement ISR***************************//
uint32_t  count_pm_init=0; // initialization of counter for settings increment and decrement
volatile uint32_t setting_counter = 1;
void autopulse()
{

}
void autotimecounter(volatile timecount_state_t* sstate,volatile button_state_t* timerstate)
{

	switch (*sstate) {
	case TIME_STATE_PRESSED:
	        	(autotime_counter)++;
	        	if (autotime_counter>=autotime_press_counter)
	        	   {*timerstate= BUTTON_STATE_PRESSED;
	        	 autotime_counter = 0;
	        	   }
	            break;
	        default:
	            break;
	    }

}

void update_button_state(volatile button_state_t* state, volatile uint32_t* counter, uint32_t pin, uint32_t* release_delay)
{
    /* State machine */
    switch (*state) {
        case BUTTON_STATE_IDLE:
        	PINS_DRV_WritePin(GPIO_PORT1, pin, 1);
            *counter = *release_delay;
            break;
        case BUTTON_STATE_PRESSED:
        	PINS_DRV_WritePin(GPIO_PORT1, pin, 0);
            if (*counter > 0) {
                (*counter)--;
            } else {
                 /* End button press */
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
    update_button_state(&onoff_state, &onoff_counter, ONOFF, &onoff_release_delay);
    update_button_state(&bell_state, &bell_counter, BELL, &bell_release_delay);
    update_button_state(&plus_state, &plus_counter, PLUS, &plus_release_delay );
    update_button_state(&minus_state, &minus_counter, MINUS, &minus_release_delay);
    autotimecounter(&minustime_state,&minus_state);
    autotimecounter(&plustime_state,&plus_state);

/***************** setting counter handler************************************/
	if(count_pm_init==1)
	{
    if (plus_state == BUTTON_STATE_PRESSED) {
            setting_counter++;
            plus_state = BUTTON_STATE_IDLE;
            if (setting_counter>=20)
            		     {
            		    	 setting_counter = 20;
            		     }// Reset the state
        }

        /* Check if minus button was just pressed */
        if (minus_state == BUTTON_STATE_PRESSED) {
            setting_counter--;
            minus_state = BUTTON_STATE_IDLE;
            if (setting_counter<=0)
            		     {
            		    	 setting_counter = 1;
            		     }// Reset the state
        }
	}
   /***************** setting counter handler ends here************************************/

/**********************autotimecounter handler********************/
	if(minustime_state == TIME_STATE_PRESSED) {
							plustime_state = TIME_STATE_IDLE;
						}
	if(plustime_state == TIME_STATE_PRESSED) {
					minustime_state = TIME_STATE_IDLE;
						}

	/**********************autotimecounter handler ends here********************/
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
    chConfig.periodUnits = LPIT_PERIOD_UNITS_MICROSECONDS;
    chConfig.period =10000; // Adjust this to change the frequency of the interrupt
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
