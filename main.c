/*
 * Prodjekt2.c
 *
 * Created: 2022-11-08 08:45:14
 * Author : willi
 */ 

#include "header.h"

/**************************************************************************

 -main: k�r setup som initeierar I/Os och avbrott
		och k�r sedan leds_set_outputs som best�mer l�get p� dioderna.
		diodernas l�ge �ndras vid avbrot som aktiveras med knapparna.
 
***************************************************************************/

int main(void)
{
	
   setup();
    while (1) 
    {
			leds_set_outputs();
	}
}

