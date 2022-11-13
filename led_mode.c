/*
 * led_mode.c
 *
 * Created: 2022-11-08 10:41:31
 *  Author: willi
 */ 

#include "header.h"

/**************************************************************************
	  
	-speed: �r en variabel som anger antal milisekunder melan varje blinkning
			som anv�ds d� dioderna �r i ett l�gge d�r dom blinkar. 
			om diodensrnas l�gge �ndras till ett l�gge d�r dom ej blinkar s�tts speed till 0
			s� att blinkfuntionen k�rs igenom utan delay.
 
***************************************************************************/
uint16_t speed=0;

/**************************************************************************
	  
	-led_state: �r en variabel som anger vilket l�gge dioderna befinners sig i.
	
				- vid led_state=leds_off �r dioderna sl�ckta.
				- vid led_state=leds_on �r dioderna t�nda.
				- vid led_state=leds_blink_slow blinkar dioderna med hastigheten 500 ms.
				- vid led_state=leds_blink_medium blinkar dioderna med hastigheten 250 ms.
				- vid led_state=leds_blink_fast blinkar dioderna med hastigheten 50 ms.
***************************************************************************/
led_state_t led_state =leds_off;

/**************************************************************************
	  
	-led_reset: anropas n�r reset knappen p� pin 2 trycks och sl�pps vid fallande flank.
				ledsen sl�cks och l�get f�r dioderna s�tts till off.
 
***************************************************************************/
void led_reset(void){
	LEDS_OFF;
	led_state = leds_off;
	speed = 0;
	return;
}

/**************************************************************************
	  
	-leds_set_outputs: s�tter hur ledsen skall lysa beroende p� v�rdet p� variabeln led_state.
					   vid led_state = leds_off s� h�nder inget.
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
					 led state �ndrar tilst�ndet f�r variabeln led_state beroende p� vilken knapp som trycks in.
					 
					- Om knapp Forward_1_STEPP_BUTTON_IS_PRESSED p� pin 12 trycks hoppar led_state fram�t 1 steg.
					- Om knapp Forward_2_STEPP_BUTTON_IS_PRESSED p� pin 13 trycks hoppar led_state fram�t 2 steg.
					- Om knapp BACKWARDS_2_STEPP_BUTTON_IS_PRESSED p� pin 11 trycks hoppar led_state back�t 1 steg.
					- Om knapp BACKWARDS_1_STEPP_BUTTON_IS_PRESSED p� pin 3 trycks hoppar led_state back�t 2 steg.
					 
					 efter att nya v�rdet s� led_state blivit givet s� s�tts �ven v�rdet p� speed som best�mer delayen vid blinkning.
 
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

