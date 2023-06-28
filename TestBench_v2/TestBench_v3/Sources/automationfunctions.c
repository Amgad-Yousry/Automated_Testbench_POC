/*
 * automationfunctions.c
 *
 *  Created on: Jun 28, 2023
 *      Author: kamil
 */

#include "Cpu.h"

#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include"automationdefinit.h"
#include"automationfunctions.h"

void Init_varAuto (void)
{
 onoff_state = BUTTON_STATE_IDLE;
  onoff_counter = 0;
 onoff_release_delay=200;

 bell_state = BUTTON_STATE_IDLE;
 bell_counter = 0;
 bell_release_delay = 300; /* Default press duration */

 plus_state = BUTTON_STATE_IDLE;
 plustime_state = TIME_STATE_IDLE;
 plus_counter = 0;
 plus_release_delay=15;

 minus_state = BUTTON_STATE_IDLE;
 minustime_state = TIME_STATE_IDLE;
 minus_counter = 0;
minus_release_delay=15;
/************************auto increment or decrement**********************/
 autotime_press_counter=900;
 autotime_counter = 0;

//*************** settings increment decrement ISR***************************//
 count_pm_init= COUNTER_STATE_IDLE; // initialization of counter for settings increment and decrement
 setting_counter = 1;
 const uint8_t MAX_SETTING_COUNTER = 20U;
 const uint8_t MIN_SETTING_COUNTER = 1U;

 strncpy(checkCommand,CHECK_COMMAND,8);
		speed_value = 20;
		  uart_state = UART_STATE_IDLE;

		  consigne =0;
		   bolusPerMinute=0;
		   tauxOxygen=0;
		   temperature=0 ;
		   vitesseCompresseur=0;
}

/*
char P5S[8]; // this should be outside so it can be modified by the function
int current;
int pressure;

void Init_varAuto (void)
{
	P5S = STATUSOK; // this should be outside so it can be modified by the function
	current = 0;
	pressure = 0;
}


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
*/
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



void timing_pal_AUTO_callBack(void * userData)
{
	(void)userData;


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
