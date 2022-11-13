/*
 * interrupts.c
 *
 * Created: 2022-11-08 10:24:18
 *  Author: willi
 */ 
#include "header.h"

/*********************************************************************

ISR(INT0_vet):	Vid intrykcning av resetknapen (pin2) s� sker ett avbrot 
				och funtionen led_reset �ndrar diodernas l�ge till off.

**********************************************************************/
ISR(INT0_vect){
	led_reset();
}

/**************************************************************************

ISR(INT0_vet): Vid intrykcning av knappen till pin 3 s� hoppar diodernas l�ge bak 2 steg  

***************************************************************************/
ISR(INT1_vect){
	leds_set_state();	
}


/****************************************************************************
ISR(PCINT0_vect): Vid intrykcning av knappen till pin 11-13 s� sker ett avbrot.
				funtionen leds_set_state anropas d�r det diodernas l�ge �ndras.
*****************************************************************************/

ISR(PCINT0_vect){
	if(FORWARD_1_STEPP_BUTTON_IS_PRESSED||BACK_1_STEPP_BUTTON_IS_PRESSED||FORWARD_2_STEPP_BUTTON_IS_PRESSED){
	leds_set_state();
	}
}
