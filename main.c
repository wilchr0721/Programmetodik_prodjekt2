/*
 * Prodjekt2.c
 *
 * Created: 2022-11-08 08:45:14
 * Author : willi
 */ 

#include "header.h"

/**************************************************************************

 -main: kör setup som initeierar I/Os och avbrott
		och kör sedan leds_set_outputs som bestämer läget på dioderna.
		diodernas läge ändras vid avbrot som aktiveras med knapparna.
 
***************************************************************************/

int main(void)
{
	
   setup();
    while (1) 
    {
			leds_set_outputs();
	}
}

