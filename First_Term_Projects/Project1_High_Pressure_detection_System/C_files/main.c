/*
 * main.c
 *
 *  Created on: Nov 25, 2023
 *      Author: Salah Saliman
 */

#include "AlarmMonitor.h"
#include "AlarmActuator.h"
#include "PressureSensor.h"
#include "HPDetection.h"


void setup()
{
	GPIO_INITIALIZATION();
	AA_init();

	// pointers initialization
	PS_state = STATE(PS_Reading);
}

int main ()
{
	setup();
	while (1)
	{
		PS_state();
		int state = HPD_state();
		if (!state) //if the pressure <= threshold
			continue ;
		AM_state();
		AA_state();
		AM_state();
		AA_state();
		//AM_state();
	}
}
