/*
 * Leds_blink.c
 *
 * Created: 2022-11-08 10:46:16
 *  Author: willi
 */ 

#include "header.h"

static void delay(volatile uint16_t* time_delay);

/**************************************************************************

 -leds_blink: funtionen k�rs d� dioderna skall blinka.
			  dioderna t�nds i ordning fr�n LED1 till LED3 
			  och v�ntar sedan i med v�rdet av blink speed antal ms.
			  
	-blink_speed: �r en pekare som anger antal milisekunder melan varje blinkning. 
 
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

 -delay: funtionen k�r en delay p� time_delays v�rde i milisekunder.
		v�rdet p� time_delay kan nolst�las eller �ndras vid avbrot.
			  
	-blink_speed: �r en pekare som anger antal milisekunder melan varje blinkning. 
 
***************************************************************************/
static void delay(volatile uint16_t* time_delay){
	
	for(uint16_t i = 0; i < *time_delay; i++){
		_delay_ms(1);
	}
	return;
	
}