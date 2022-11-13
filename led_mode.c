/*
 * led_mode.c
 *
 * Created: 2022-11-08 10:41:31
 *  Author: willi
 */ 

#include "header.h"

/**************************************************************************
	  
	-speed: är en variabel som anger antal milisekunder melan varje blinkning
			som anväds då dioderna är i ett lägge där dom blinkar. 
			om diodensrnas lägge ändras till ett lägge där dom ej blinkar sätts speed till 0
			så att blinkfuntionen körs igenom utan delay.
 
***************************************************************************/
uint16_t speed=0;

/**************************************************************************
	  
	-led_state: Är en variabel som anger vilket lägge dioderna befinners sig i.
	
				- vid led_state=leds_off är dioderna släckta.
				- vid led_state=leds_on är dioderna tända.
				- vid led_state=leds_blink_slow blinkar dioderna med hastigheten 500 ms.
				- vid led_state=leds_blink_medium blinkar dioderna med hastigheten 250 ms.
				- vid led_state=leds_blink_fast blinkar dioderna med hastigheten 50 ms.
***************************************************************************/
led_state_t led_state =leds_off;

/**************************************************************************
	  
	-led_reset: anropas när reset knappen på pin 2 trycks och släpps vid fallande flank.
				ledsen släcks och läget för dioderna sätts till off.
 
***************************************************************************/
void led_reset(void){
	LEDS_OFF;
	led_state = leds_off;
	speed = 0;
	return;
}

/**************************************************************************
	  
	-leds_set_outputs: sätter hur ledsen skall lysa beroende på värdet på variabeln led_state.
					   vid led_state = leds_off så händer inget.
					   vid led_state = leds_on lyser alla leds.
					   vid led_state = leds_blink blinkar ledsen med delayen speed.
 
***************************************************************************/
void leds_set_outputs(void){
	if (led_state == leds_on){
		LEDS_ON;
		
	}
	else if((led_state == leds_blink_slow)||(led_state == leds_blink_medium)||(led_state == leds_blink_fast)){
		leds_blink(&speed);
	}
	return;
}

/**************************************************************************
	  
	-leds_set_state: anropas vid avbrott som aktiveras av knapparna anslutna till pin 3 eller pin 11-13.
					 led state ändrar tilståndet för variabeln led_state beroende på vilken knapp som trycks in.
					 
					- Om knapp Forward_1_STEPP_BUTTON_IS_PRESSED på pin 12 trycks hoppar led_state framåt 1 steg.
					- Om knapp Forward_2_STEPP_BUTTON_IS_PRESSED på pin 13 trycks hoppar led_state framåt 2 steg.
					- Om knapp BACKWARDS_2_STEPP_BUTTON_IS_PRESSED på pin 11 trycks hoppar led_state backåt 1 steg.
					- Om knapp BACKWARDS_1_STEPP_BUTTON_IS_PRESSED på pin 3 trycks hoppar led_state backåt 2 steg.
					 
					 efter att nya värdet så led_state blivit givet så sätts även värdet på speed som bestämer delayen vid blinkning.
 
***************************************************************************/

void leds_set_state(void){
	
	switch (led_state){
		
		case (leds_off):{
			if (FORWARD_1_STEPP_BUTTON_IS_PRESSED){
				led_state = leds_on;
				break;
			}
			else if(FORWARD_2_STEPP_BUTTON_IS_PRESSED){
				led_state = leds_blink_slow;
				break;
			}
			else if(BACK_1_STEPP_BUTTON_IS_PRESSED){
				led_state = leds_blink_fast;
				break;
			}
			else if(BACK_2_STEPP_BUTTON_IS_PRESSED){
				led_state = leds_blink_medium;
				break;
			}
		}
		
		case (leds_on):{
			if (FORWARD_1_STEPP_BUTTON_IS_PRESSED){
				led_state = leds_blink_slow;
				break;
			}
			else if(FORWARD_2_STEPP_BUTTON_IS_PRESSED){
				led_state = leds_blink_medium;
				break;
			}
			else if(BACK_1_STEPP_BUTTON_IS_PRESSED){
				led_reset();
				break;
			}
			else if(BACK_2_STEPP_BUTTON_IS_PRESSED){
				led_state = leds_blink_fast;
				break;
			}
		}
		
		case (leds_blink_slow):{
			if (FORWARD_1_STEPP_BUTTON_IS_PRESSED){
				led_state = leds_blink_medium;
				break;
			}
			else if(FORWARD_2_STEPP_BUTTON_IS_PRESSED){
				led_state = leds_blink_fast;
				break;
			}
			else if(BACK_1_STEPP_BUTTON_IS_PRESSED){
				led_state = leds_on;
				break;
			}
			else if(BACK_2_STEPP_BUTTON_IS_PRESSED){
				led_reset();
				break;
			}
		}
		
		case (leds_blink_medium):{
			if (FORWARD_1_STEPP_BUTTON_IS_PRESSED){
				led_state = leds_blink_fast;
				break;
			}
			else if(FORWARD_2_STEPP_BUTTON_IS_PRESSED){
				led_reset();
				break;
			}
			else if(BACK_1_STEPP_BUTTON_IS_PRESSED){
				led_state = leds_blink_slow;
				break;
			}
			else if(BACK_2_STEPP_BUTTON_IS_PRESSED){
				led_state = leds_on;
				break;
			}
		}
		
		case (leds_blink_fast):{
			if (FORWARD_1_STEPP_BUTTON_IS_PRESSED){
				led_reset();
				break;
			}
			else if(FORWARD_2_STEPP_BUTTON_IS_PRESSED){
				led_state = leds_on;
				break;
			}
			else if(BACK_1_STEPP_BUTTON_IS_PRESSED){
				led_state = leds_blink_medium;
				break;
			}
			else if(BACK_2_STEPP_BUTTON_IS_PRESSED){
				led_state = leds_blink_slow;
				break;
			}
		}
		default:{
			led_reset();
		}
	}
	
	
	
	if (led_state == leds_blink_slow){
		speed=500;
	}
	else if(led_state == leds_blink_medium){
		speed=250;
	}
	else if(led_state == leds_blink_fast){
		speed=50;
	}
	else{
		speed=0;
	}
	return;
}

