/*
 * main.c
 *
 *  Created on: Nov 16, 2023
 *      Author: Salah Soliman
 */

#include "CA.h"
#include "US_Sensor.h"
#include "DC_Motor.h"


void setup()
{
	//init all the drivers
	US_init();
	DC_init();
	//init IRQ ...
	//HAl US_Driver , DC_Driver
	//Init BLOCK

	CA_state = STATE(CA_waiting);
	US_state = STATE(US_busy);
	DC_state = STATE(DC_idle);
}

int main()
{
	volatile int d ;
	setup();
	while(1)
	{
		//call state each Block
		US_state();
		CA_state();
		DC_state();
		//delay
		for(d=0 ;d<=1000 ;d++);
	}
}
