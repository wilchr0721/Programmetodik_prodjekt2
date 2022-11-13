/*
 * Leds_blink.c
 *
 * Created: 2022-11-08 10:46:16
 *  Author: willi
 */ 

#include "header.h"

static void delay(volatile uint16_t* time_delay);

/**************************************************************************

 -leds_blink: funtionen körs då dioderna skall blinka.
			  dioderna tänds i ordning från LED1 till LED3 
			  och väntar sedan i med värdet av blink speed antal ms.
			  
	-blink_speed: är en pekare som anger antal milisekunder melan varje blinkning. 
 
***************************************************************************/

void leds_blink(uint16_t* blink_speed){
	LEDS_OFF;
	LED1_ON;
	delay(blink_speed);
	LED1_OFF;
	LED2_ON;
	delay(blink_speed);
	LED2_OFF;
	LED3_ON;
	delay(blink_speed);
	LEDS_OFF;
	return;
	
}

/**************************************************************************

 -delay: funtionen kör en delay på time_delays värde i milisekunder.
		värdet på time_delay kan nolstälas eller ändras vid avbrot.
			  
	-blink_speed: är en pekare som anger antal milisekunder melan varje blinkning. 
 
***************************************************************************/
static void delay(volatile uint16_t* time_delay){
	
	for(uint16_t i = 0; i < *time_delay; i++){
		_delay_ms(1);
	}
	return;
	
}