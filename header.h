/*
 * header.h
 *
 * Created: 2022-11-08 08:45:37
 *  Author: willi
 */ 

/********************************************************************************
* header.h ineh�ller definitioner av leds tryckknappar och macros f�r att styra arduios I/Os.
			
********************************************************************************/
#ifndef HEADER_H_
#define HEADER_H_


#define F_CPU 16000000UL /*definerar klockfrekvensen f�r arduinot */

#include <avr/io.h>			/*ineh�ller i/o portar och register f�r arduinot */
#include <util/delay.h>		/*icluderas f�r anv�ndning av _delay_ms funtionen*/
#include <avr/interrupt.h>	/*includeras f�r anv�nding av interrupts f�r arduinot */

#define LED1 0  /* LED1 ligger p� PortB0 p� eller I/O port 8 p� arduinot */
#define LED2 1	/* LED2 ligger p� PortB1 p� eller I/O port 9 p� arduinot */
#define LED3 2	/* LED3 ligger p� PortB2 p� eller I/O port 10 p� arduinot */

#define RESET_BUTTON 2				/* reset knappen ligger p� PortD2 p� eller I/O port 2 p� arduinot */
#define FORWARD_1_STEPP_BUTTON 4	/* 1 steg fram knappen ligger p� PortB4 p� eller I/O port 12 p� arduinot */
#define FORWARD_2_STEPP_BUTTON 5	/* 2 steg fram knappen ligger p� PortB5 p� eller I/O port 13 p� arduinot */
#define BACK_1_STEPP_BUTTON 3		/* 1 steg bak knappen ligger p� PortB3 p� eller I/O port 11 p� arduinot */
#define BACK_2_STEPP_BUTTON 3		/* 2 steg bak knappen ligger p� PortB3 p� eller I/O port 11 p� arduinot */

#define LED1_ON PORTB	|= (1 << LED1)	/* T�nd LED1 p� pin 8 */
#define LED2_ON PORTB	|= (1 << LED2)	/* T�nd LED2 p� pin 9 */
#define LED3_ON PORTB	|= (1 << LED3)	/* T�nd LED3 p� pin 10 */

#define LED1_OFF PORTB	&= ~(1 << LED1)	/* Sl�ck LED1 p� pin 8 */
#define LED2_OFF PORTB	&= ~(1 << LED2)	/* Sl�ck LED2 p� pin 9 */
#define LED3_OFF PORTB	&= ~(1 << LED3)	/* Sl�ck LED3 p� pin 10 */

#define LEDS_ON		PORTB	|= ((1 << LED1)|(1 << LED2)|(1 << LED3))	/* T�nd alla LEDS */
#define LEDS_OFF	PORTB	&= ~((1 << LED1)|(1 << LED2)|(1 << LED3))	/* Sl�ck alla LEDS */

#define RESET_BUTTON_IS_PRESSED (PIND & (1 << RESET_BUTTON))						/*Reset knappen �r nertryckt (pin 2)*/
#define FORWARD_1_STEPP_BUTTON_IS_PRESSED (PINB & (1 << FORWARD_1_STEPP_BUTTON))	/*Fram�t 1 steg knappen �r nertryckt (pin 12)*/
#define FORWARD_2_STEPP_BUTTON_IS_PRESSED (PINB & (1 << FORWARD_2_STEPP_BUTTON))	/*Fram�t 2 steg knappen �r nertryckt (pin 13)*/
#define BACK_1_STEPP_BUTTON_IS_PRESSED	(PINB & (1 << BACK_1_STEPP_BUTTON))			/*bak 1 steg knappen �r nertryckt (pin 11)*/
#define BACK_2_STEPP_BUTTON_IS_PRESSED	(PIND & (1 << BACK_2_STEPP_BUTTON))			/*bak 2 knappen �r nertryckt (pin 3)*/


typedef enum {false, true} bool;
	
/*Enumeraktion f�r olika tilst�nd f�r dioderna*/

typedef enum {leds_off, leds_on, leds_blink_slow, leds_blink_medium, leds_blink_fast} led_state_t; 

void setup(void);
void led_reset(void);
void leds_blink(uint16_t* time_delay);
void leds_set_outputs(void);
void leds_set_state(void);

#endif /* HEADER_H_ */