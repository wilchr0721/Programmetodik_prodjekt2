/*
 * setup.c
 *
 * Created: 2022-11-08 09:27:53
 *  Author: willi
 */ 
#include "header.h"
static void init_ios(void);
static void init_interupts(void);

/**************************************************************************

 -setup: initierar inputs och outputs och interupts
 
***************************************************************************/
void setup(void){
	
	init_ios();
	init_interupts();
	return;
}


/**************************************************************************

 -init:ios: aktiverar ingågrna på pin 2 och 3 samt 11 -13 och utgågarna på pin 8-10
 
***************************************************************************/
static void init_ios(void){
	
	DDRB = ((1 << LED1)| (1 << LED2)| (1 << LED3));
	PORTD = ((1 << RESET_BUTTON)|(BACK_2_STEPP_BUTTON));
	PORTB =	((1 << FORWARD_2_STEPP_BUTTON)| (1 << BACK_1_STEPP_BUTTON)|(1 << FORWARD_1_STEPP_BUTTON));
	return;
}

/**************************************************************************

 -init_interupts: initierar och bestämmer vilkoren för avbrot.
				  pin2(INT0) aktiveras vid fallande flank.
				  pin3(INT1) aktiveras vid stigande flank.
				  pin 11-13 (PCINT3-5) aktiveras vid nertryckning av knapp,
 
***************************************************************************/

static void init_interupts(void){
	
	asm("SEI");
	EICRA = ((1 << ISC01)|(1 << ISC10)|(1 << ISC11));
	EIMSK = ((1 << INT0)|(1 << INT1));
	PCMSK0 =((1 << PCINT3)|(1 << PCINT4)|(1 << PCINT5));
	PCICR= (1 << PCIE0);
	return;
}
