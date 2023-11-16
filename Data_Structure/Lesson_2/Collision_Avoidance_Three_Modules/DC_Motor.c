/*
 * DV_Motor.c
 *
 *  Created on: Nov 16, 2023
 *      Author: Salah Soliman
 */

#include "DC_Motor.h"

//module variables

unsigned int speed ;


void DC_init()
{
	//init DC Motor
	printf("DC_init\n\n");
}

void DC_motor(int s)
{
	speed = s ;
	(speed == 30 ) ? (DC_state =STATE(DC_busy)) : (DC_state = STATE(DC_idle));
	DC_state = STATE(DC_busy);
	printf("CA ------ speed = %d  ------> DC \n",speed);
}

STATE_define(DC_idle)
{
	DC_state_id = DC_idle ;
	DC_state = STATE(DC_idle);
	printf("DC_idle state : speed = %d  \n \n \n ",speed);
}


STATE_define(DC_busy)
{
	//Sate Action
	DC_state_id = DC_busy ;
	DC_state = STATE(DC_busy);
	printf("DC_busy state : speed = %d  \n \n \n ",speed);
}
