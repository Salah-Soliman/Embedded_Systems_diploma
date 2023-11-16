/*
 * StateMachine.c
 *
 *  Created on: Nov 16, 2023
 *      Author: Salah Soliman
 */

#include "StateMachine.h"

unsigned int distance , speed , threshold =  50 ;

STATE_define(waiting)
{
	// state action
	state_id = waiting ;
	speed = 0 ;
	distance = Random(generate_random,45,55,1);

	// check event
	(distance <= threshold ) ? (state =STATE(waiting)) : (state = STATE(driving));
	printf("Waiting state : distance = %d   speed = %d \n",distance,speed);
}

STATE_define(driving)
{
	// state action
	state_id = driving ;
	speed = 30 ;
	distance = Random(generate_random,45,55,1);

	// check event
	(distance <= threshold ) ? (state =STATE(waiting)) : (state = STATE(driving));
	printf("Driving state : distance = %d   speed = %d \n",distance,speed);
}

STATE_define(setup)
{
	//motor_init(); //for left and right speed
	//init Soc Modules
	state = STATE(waiting);
}


random_define(generate_random,int l ,int r ,int count)
{
	int i ;
	for (i = 0 ; i < count ; i++)
	{
		int rand_num = (rand() % (r - l + 1)) + l;
		return rand_num ;
	}
}

