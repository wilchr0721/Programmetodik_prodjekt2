/*
 * header.h
 *
 * Created: 2022-11-08 08:45:37
 *  Author: willi
 */ 

/********************************************************************************
* header.h inehåller definitioner av leds tryckknappar och macros för att styra arduios I/Os.
			
********************************************************************************/
#ifndef HEADER_H_
#define HEADER_H_


#define F_CPU 16000000UL /*definerar klockfrekvensen för arduinot */

#include <avr/io.h>			/*inehåller i/o portar och register för arduinot */
#include <util/delay.h>		/*icluderas för användning av _delay_ms funtionen*/
#include <avr/interrupt.h>	/*includeras för använding av interrupts för arduinot */

#define LED1 0  /* LED1 ligger på PortB0 på eller I/O port 8 på arduinot */
#define LED2 1	/* LED2 ligger på PortB1 på eller I/O port 9 på arduinot */
#define LED3 2	/* LED3 ligger på PortB2 på eller I/O port 10 på arduinot */

#define RESET_BUTTON 2				/* reset knappen ligger på PortD2 på eller I/O port 2 på arduinot */
#define FORWARD_1_STEPP_BUTTON 4	/* 1 steg fram knappen ligger på PortB4 på eller I/O port 12 på arduinot */
#define FORWARD_2_STEPP_BUTTON 5	/* 2 steg fram knappen ligger på PortB5 på eller I/O port 13 på arduinot */
#define BACK_1_STEPP_BUTTON 3		/* 1 steg bak knappen ligger på PortB3 på eller I/O port 11 på arduinot */
#define BACK_2_STEPP_BUTTON 3		/* 2 steg bak knappen ligger på PortB3 på eller I/O port 11 på arduinot */

#define LED1_ON PORTB	|= (1 << LED1)	/* Tänd LED1 på pin 8 */
#define LED2_ON PORTB	|= (1 << LED2)	/* Tänd LED2 på pin 9 */
#define LED3_ON PORTB	|= (1 << LED3)	/* Tänd LED3 på pin 10 */

#define LED1_OFF PORTB	&= ~(1 << LED1)	/* Släck LED1 på pin 8 */
#define LED2_OFF PORTB	&= ~(1 << LED2)	/* Släck LED2 på pin 9 */
#define LED3_OFF PORTB	&= ~(1 << LED3)	/* Släck LED3 på pin 10 */

#define LEDS_ON		PORTB	|= ((1 << LED1)|(1 << LED2)|(1 << LED3))	/* Tänd alla LEDS */
#define LEDS_OFF	PORTB	&= ~((1 << LED1)|(1 << LED2)|(1 << LED3))	/* Släck alla LEDS */

#define RESET_BUTTON_IS_PRESSED (PIND & (1 << RESET_BUTTON))						/*Reset knappen är nertryckt (pin 2)*/
#define FORWARD_1_STEPP_BUTTON_IS_PRESSED (PINB & (1 << FORWARD_1_STEPP_BUTTON))	/*Framåt 1 steg knappen är nertryckt (pin 12)*/
#define FORWARD_2_STEPP_BUTTON_IS_PRESSED (PINB & (1 << FORWARD_2_STEPP_BUTTON))	/*Framåt 2 steg knappen är nertryckt (pin 13)*/
#define BACK_1_STEPP_BUTTON_IS_PRESSED	(PINB & (1 << BACK_1_STEPP_BUTTON))			/*bak 1 steg knappen är nertryckt (pin 11)*/
#define BACK_2_STEPP_BUTTON_IS_PRESSED	(PIND & (1 << BACK_2_STEPP_BUTTON))			/*bak 2 knappen är nertryckt (pin 3)*/


typedef enum {false, true} bool;
	
/*Enumeraktion för olika tilstånd för dioderna*/

typedef enum {leds_off, leds_on, leds_blink_slow, leds_blink_medium, leds_blink_fast} led_state_t; 

void setup(void);
void led_reset(void);
void leds_blink(uint16_t* time_delay);
void leds_set_outputs(void);
void leds_set_state(void);

#endif /* HEADER_H_ */