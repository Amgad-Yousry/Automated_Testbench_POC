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
#include "lpi2c1.h"
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
volatile int exit_code = 0;
#if CPU_INIT_CONFIG
  #include "Init_Config.h"
#endif
/* User includes (#include below this line is not maintained by Processor Expert) */
#define EVB
#define LED0_PIN_INDEX  0U
#define GPIO_PORT	PORTA
#define GPIO_PORT1	PTA
#define GPIO_PORT2	PTC
#define PCC_CLOCK	PCC_PORTA_CLOCK
#define ONOFF		17U
#define PLUS		11U
#define MINUS		9U
#define BELL		8U
#define Tx			7U
#define Rx			6U
#define LPIT0_CHANNEL	    0UL
#define LPIT_Channel_IRQn   LPIT0_Ch0_IRQn
#define TRANSFER_SIZE 2U
uint8_t buffer[TRANSFER_SIZE];
uint8_t send[2] = {0x10, 0X00};
uint16_t counts_SMF;
uint16_t flow_SMF;
const uint16_t SFLOW = 100;
const uint16_t OFFSET = 32768;
uint16_t i;
/* User includes (#include below this line is not maintained by Processor Expert) */
/* Global variables for each button's state and counter */
typedef enum { // UART STATE MACHINE
	 UART_STATE_IDLE,
	 UART_STATE_SEND,
	 UART_STATE_RECEIVE,
	 UART_STATE_PROCESS,
} uart_state_t;
typedef enum { // SETTING COUNTER MACHINE
    COUNTER_STATE_IDLE,
    COUNTER_STATE_INIT,
} count_state_t;
typedef enum { // BUTTON STATE MACHINE
    BUTTON_STATE_IDLE,
    BUTTON_STATE_PRESSED,
    BUTTON_STATE_RELEASED,
    BUTTON_STATE_WAIT,
} button_state_t;
typedef enum { // TIMER STATE MACHINE
    TIME_STATE_IDLE,
    TIME_STATE_PRESSED,
} timecount_state_t;

/********************buttons state machine declarations************************/
volatile button_state_t onoff_state = BUTTON_STATE_IDLE;
volatile uint32_t onoff_counter = 0;
 uint32_t onoff_release_delay=20000;

volatile button_state_t bell_state = BUTTON_STATE_IDLE;
volatile uint32_t bell_counter = 0;
uint32_t bell_release_delay = 30000; /* Default press duration */

volatile button_state_t plus_state = BUTTON_STATE_IDLE;
volatile timecount_state_t plustime_state = TIME_STATE_IDLE;
volatile uint32_t plus_counter = 0;
 uint32_t plus_release_delay=10000;

volatile button_state_t minus_state = BUTTON_STATE_IDLE;
volatile timecount_state_t minustime_state = TIME_STATE_IDLE;
volatile uint32_t minus_counter = 0;
uint32_t minus_release_delay=10000;
/************************auto increment or decrement**********************/
volatile uint32_t autotime_press_counter=90000;
volatile uint32_t autotime_counter = 0;

//*************** settings increment decrement ISR***************************//
 count_state_t  count_pm_init= COUNTER_STATE_IDLE; // initialization of counter for settings increment and decrement
volatile uint8_t setting_counter = 1;
const uint8_t MAX_SETTING_COUNTER = 20U;
const uint8_t MIN_SETTING_COUNTER = 1U;

/*****************************handshake parameters**************************/
#define CHECK_COMMAND "GET_STATUS\n\r" // The command to send to the device for checking UART connection
#define EXPECTED_RESPONSE "OK_STATUS\n" // The expected response from the device
#define PACKET_SIZE 67
#define TIME_INDEX 2 // Index of the time field in the packet
#define SESSION_TIMER_INDEX 4 // ...
#define CONSIGNE_INDEX 5 // ...
#define BOLUS_PER_MINUTE_INDEX 6 // ...
#define TAUX_OXYGENE_INDEX 7 // ...
#define TEMPERATURE_INDEX 8 // ...
#define VITESSE_COMPRESSEUR_INDEX 9 // ...
#define PRESSION_ATMOSPHERIQUE_INDEX 10 // ...
#define TIMEOUT_VALUE 1000 // Define a suitable timeout value in milliseconds
 // Define a char array large enough to hold the string
uint8_t statuss =0;
volatile int bolusPerMinute = 0;
volatile int tauxOxygen = 0;
volatile int temperature = 0;
volatile int vitesseCompresseur = 0;

uint8_t packet[PACKET_SIZE];
const uint8_t checkCommand[] = CHECK_COMMAND;
status_t status;

volatile uart_state_t uart_state = UART_STATE_IDLE;
/**********************************handshake parameters end******************/


void sendCheckCommand(volatile uart_state_t* uartstate) {
status=LPUART_DRV_SendData(INST_LPUART1,checkCommand, strlen((const char*)checkCommand));
if(status == STATUS_SUCCESS) {


*uartstate = UART_STATE_IDLE;
}
        // Send successful, now wait for response
}
void receiveResponse(volatile uart_state_t* uartstate)
{
    status = LPUART_DRV_ReceiveData(INST_LPUART1, packet, sizeof(packet)-1);

    if(status == STATUS_SUCCESS) {
        // Null-terminate the received string
        packet[sizeof(packet)-1] = '\0';
        *uartstate = UART_STATE_PROCESS;
    }

}

void processResponse(volatile uart_state_t* uartstate) {
    // Parse the packet
    char* token = strtok((char*)packet, ",");
    int fieldIndex = 0;
    while(token != NULL) {
        if(fieldIndex == BOLUS_PER_MINUTE_INDEX) {
            bolusPerMinute = atoi(token);
        } else if(fieldIndex == TAUX_OXYGENE_INDEX) {
            tauxOxygen = atoi(token);
        } else if(fieldIndex == TEMPERATURE_INDEX) {
            temperature = atoi(token);
        } else if(fieldIndex == VITESSE_COMPRESSEUR_INDEX) {
            vitesseCompresseur = atoi(token);
        }

        // Go to the next field
        token = strtok(NULL, ",");
        fieldIndex++;
    }
    *uartstate = UART_STATE_IDLE;
}
void p5handshake(volatile uart_state_t* uartstate){
	switch (*uartstate) {
    case UART_STATE_IDLE:
        	break;
    case UART_STATE_SEND:
        sendCheckCommand(uartstate);
        break;
    case UART_STATE_RECEIVE:
        receiveResponse(uartstate);
        break;
    case UART_STATE_PROCESS:
        processResponse(uartstate);
        break;

    default:
    break;
    }
}


void autotimecounter(volatile timecount_state_t* sstate,volatile button_state_t* timerstate, volatile timecount_state_t* other_sstate)
{
    // If the other state is active, we should not update this state
    if (*other_sstate == TIME_STATE_PRESSED) {
        return;
    }

    switch (*sstate) {
        case TIME_STATE_PRESSED:
            (autotime_counter)++;
            if (autotime_counter >= autotime_press_counter)
            {
                *timerstate = BUTTON_STATE_PRESSED;
                autotime_counter = 0;
            }
            break;
        case TIME_STATE_IDLE: autotime_counter = 0;
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
void updatecounter(count_state_t* count_state)
{
	static bool plus_previous_state = false;  // Added variables to store the previous state of the buttons
	static bool minus_previous_state = false; // Added variables to store the previous state of the buttons

	switch(*count_state)
	{
	case COUNTER_STATE_INIT:
		    // Check if plus button was just pressed
		    if (plus_state == BUTTON_STATE_PRESSED && plus_previous_state == false)
		    {
		    	setting_counter++;
		    	plus_previous_state = true; // Store the current state of the plus button
		        if (setting_counter>=20U)
		        {
		            setting_counter = 20U;
		        }
		    }
            // If the button is not pressed, reset the previous state
		    else if (plus_state == BUTTON_STATE_IDLE)
		    {
		    	plus_previous_state = false;
		    }

		    // Check if minus button was just pressed
		    if (minus_state == BUTTON_STATE_PRESSED && minus_previous_state == false)
		    {
		        setting_counter--;
		        minus_previous_state = true; // Store the current state of the minus button
		        if (setting_counter<=0U)
		        {
		            setting_counter = 1U;
		        }
		    }
		    // If the button is not pressed, reset the previous state
		    else if (minus_state == BUTTON_STATE_IDLE)
		    {
		    	minus_previous_state = false;
		    }
		    break;
	case COUNTER_STATE_IDLE:
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
    autotimecounter(&minustime_state, &minus_state, &plustime_state);
    autotimecounter(&plustime_state, &plus_state, &minustime_state);
    updatecounter(&count_pm_init);
    p5handshake(&uart_state);
    receiveResponse(&uart_state);
    processResponse(&uart_state);
}

int main(void)
{

  /* Write your local variable definition here */
	const uint64_t SFLOW = 100;
	const uint64_t OFFSET = 32768;
    /* Allocate memory for the LPI2C driver state structure */
	lpi2c_master_state_t lpi2c1MasterState;
	/* Variable used for the loop that initializes the data buffer */
		    uint16_t i;
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
    chConfig.period =100; // update every 100 microseconds
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

/************ transparent flow sensor configurations*********/

LPI2C_DRV_MasterInit(INST_LPI2C1, &lpi2c1_MasterConfig0,&lpi2c1MasterState);
LPI2C_DRV_MasterSendDataBlocking(INST_LPI2C1, send,2U, true,OSIF_WAIT_FOREVER);

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
