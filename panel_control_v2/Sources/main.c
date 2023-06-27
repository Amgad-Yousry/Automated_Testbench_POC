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
uint16_t i;
/* User includes (#include below this line is not maintained by Processor Expert) */
/* Global variables for each button's state and counter */
typedef enum { // UART STATE MACHINE
	 UART_STATE_IDLE,
	 UART_STATE_SEND,
	 UART_STATE_RECEIVE,
	 UART_STATE_PROCESS,
	 UART_STATE_SPEED,
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
 uint32_t onoff_release_delay=200;

volatile button_state_t bell_state = BUTTON_STATE_IDLE;
volatile uint32_t bell_counter = 0;
uint32_t bell_release_delay = 300; /* Default press duration */

volatile button_state_t plus_state = BUTTON_STATE_IDLE;
volatile timecount_state_t plustime_state = TIME_STATE_IDLE;
volatile uint32_t plus_counter = 0;
 uint32_t plus_release_delay=15;

volatile button_state_t minus_state = BUTTON_STATE_IDLE;
volatile timecount_state_t minustime_state = TIME_STATE_IDLE;
volatile uint32_t minus_counter = 0;
uint32_t minus_release_delay=15;
/************************auto increment or decrement**********************/
volatile uint32_t autotime_press_counter=900;
volatile uint32_t autotime_counter = 0;

//*************** settings increment decrement ISR***************************//
 count_state_t  count_pm_init= COUNTER_STATE_IDLE; // initialization of counter for settings increment and decrement
volatile uint8_t setting_counter = 1;
const uint8_t MAX_SETTING_COUNTER = 20U;
const uint8_t MIN_SETTING_COUNTER = 1U;

/*****************************handshake parameters**************************/
#define CHECK_COMMAND "GET_STATUS\n\r" // The command to send to the device for checking UART connection

//#define SPEED_MINUS "CC -20\n\r"
#define PACKET_SIZE 69 // don't go less than 68
#define UTILISATION_TOTAL_INDEX 1
#define JOUR_MOIS_ANNEE_INDEX 2
#define HEURE_MINUTE_SECONDE_INDEX 3
#define SESSION_TIMER_INDEX 4
#define CONSIGNE_INDEX 5
#define BOLUS_PER_MINUTE_INDEX 6
#define TAUX_OXYGENE_INDEX 7
#define TEMPERATURE_INDEX 8
#define VITESSE_COMPRESSEUR_INDEX 9
#define PRESSION_ATMOSPHERIQUE_INDEX 10
#define PRESSION_COLONNE_ZEOLITE_1_INDEX 11
#define PRESSION_COLONNE_ZEOLITE_2_INDEX 12
#define DETECTION_CHUTE_INDEX 13
#define PRESENCE_CHARGEUR_INDEX 14
#define ETAT_BATTERIE_INDEX 15
#define TENSION_BATTERIE_INDEX 16
#define CHARGE_BATTERIE_RESTANTE_INDEX 17
#define CODE_ALARME_INDEX 18
#define ALARM_SUBCLASS_INDEX 19
#define ETAT_COLONNE_ZEOLITE_INDEX 20
#define VERSION_SOFTWARE_INDEX 21

volatile int consigne;
volatile int bolusPerMinute;
volatile double tauxOxygen;
volatile int temperature ;
volatile int vitesseCompresseur;
/*volatile int PRESSION_ATMOSPHERIQUE =0;
volatile int PRESSION_COLONNE_ZEOLITE_1 =0;
volatile int PRESSION_COLONNE_ZEOLITE_2 =0;
volatile int DETECTION_CHUTE =0;
volatile int PRESENCE_CHARGEUR =0;
volatile int ETAT_BATTERIE =0;
volatile int TENSION_BATTERIE =0;
volatile int CHARGE_BATTERIE =0;
volatile int CODE_ALARME =0;
volatile int ALARM_SUBCLASS =0;
volatile int ETAT_COLONNE =0;
volatile int VERSION_SOFTWARE =0;
volatile int UTILISATION_TOTAL =0;
volatile int JOUR_MOIS_ANNEE =0;
volatile int HEURE_MINUTE_SECONDE =0;
volatile int SESSION_TIMER =0;
*/
uint8_t packet[PACKET_SIZE];
const uint8_t checkCommand[] = CHECK_COMMAND;
status_t status;
 int speed_value = 20;
char speed_minus[20];
volatile uart_state_t uart_state = UART_STATE_IDLE;
/**********************************handshake parameters end******************/


/**********************error safety feature***************/
#define STATUSOK "STATUS_OK"
#define PRESSURE_ERROR "pressure_low_turning_off"
#define CURRENT_HIGH "current_error_turning_off"

char P5S[] = STATUSOK; // this should be outside so it can be modified by the function
int current = 0;
int pressure = 0;


void safety_power() {
    if(current >= 5000) { //CHANGE WITH REQUIRED VALUES
        strcpy(P5S, CURRENT_HIGH); // use strcpy to change the value of the string
        onoff_state = BUTTON_STATE_PRESSED;
    }
    if(pressure <= 5000) {  //CHANGE WITH REQUIRED VALUES
        strcpy(P5S, PRESSURE_ERROR); // use strcpy to change the value of the string
        onoff_state = BUTTON_STATE_PRESSED;
    }
    else
    	strcpy(P5S, STATUSOK);
}
/**********************error safety feature***************/


void updatespeedvalue(){
snprintf(speed_minus, sizeof(speed_minus), "CC -%d\n\r", speed_value);
}
void sendCheckCommand(volatile uart_state_t* uartstate) {
LPUART_DRV_SendData(INST_LPUART1,checkCommand, strlen((const char*)checkCommand));
}
void sendspeedCommand() {
	LPUART_DRV_SendData(INST_LPUART1, (unsigned char*)speed_minus, strlen((const char*)speed_minus));

}
void receiveResponse(volatile uart_state_t* uartstate)
{
    status = LPUART_DRV_ReceiveData(INST_LPUART1, packet, sizeof(packet)-1);

    if(status == STATUS_SUCCESS) {

    	    *uartstate = UART_STATE_PROCESS;

    }

}

void processResponse(volatile uart_state_t* uartstate) {

	int fieldIndex = 0;
	int byteIndex = 0;
	uint8_t fieldBuffer[PACKET_SIZE];
	int fieldBufferIndex = 0;
	int commaCount = 0;  // New counter for commas

	for(byteIndex = 0; byteIndex < PACKET_SIZE; byteIndex++) {
	    if(packet[byteIndex] == 0x2C || packet[byteIndex] == '\0') {
	        commaCount++;  // Increment comma count
	        fieldBuffer[fieldBufferIndex] = '\0';

	        switch (fieldIndex) {
	            // Process all other fields similarly...
	        case BOLUS_PER_MINUTE_INDEX:
	                bolusPerMinute = atoi((char*)fieldBuffer);
	                break;
	            case TAUX_OXYGENE_INDEX:
	                tauxOxygen = atof((char*)fieldBuffer);
	                break;
	            case TEMPERATURE_INDEX:
	            	temperature = atoi((char*)fieldBuffer);
	                break;
	            case  VITESSE_COMPRESSEUR_INDEX:
	                vitesseCompresseur= atoi((char*)fieldBuffer);
	                break;
	        }

	        fieldBufferIndex = 0;
	        fieldIndex++;

	        if(packet[byteIndex] == '\0' || commaCount > 11) {
	            break;  // Break if end of packet or if more than 11 fields have been processed
	        }
	    } else {
	        fieldBuffer[fieldBufferIndex] = packet[byteIndex];
	        fieldBufferIndex++;
	    }
	}

	memset(packet, 0, PACKET_SIZE);
	*uartstate = UART_STATE_IDLE;

}

void p5handshake(volatile uart_state_t* uartstate){
	switch (*uartstate) {
    case UART_STATE_IDLE:
        	break;
    case UART_STATE_SEND:
        sendCheckCommand(uartstate);
        *uartstate= UART_STATE_RECEIVE;
        break;
    case UART_STATE_RECEIVE:
        receiveResponse(uartstate);
        break;
    case UART_STATE_PROCESS:
     processResponse(uartstate);
        break;
    case UART_STATE_SPEED:
    	sendspeedCommand(uartstate);
    	if (setting_counter<=10U)
		        {
		         plus_state = BUTTON_STATE_PRESSED;
		         minus_state= BUTTON_STATE_PRESSED;
		        }
    	  if(setting_counter>=11U) {
    		  minus_state= BUTTON_STATE_PRESSED;
    		  plus_state = BUTTON_STATE_PRESSED;
    	  }

    	*uartstate= UART_STATE_IDLE;


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
