/*
 * US_Sensor.c
 *
 *  Created on: Nov 16, 2023
 *      Author: Salah Soliman
 */

#include "US_Sensor.h"

//module variables

unsigned int distance ;

int generate_random(int l ,int r ,int count)
{
	int i ;
	for (i = 0 ; i < count ; i++)
	{
		int rand_num = (rand() % (r - l + 1)) + l;
		return rand_num ;
	}
}


void US_init()
{
	//init US Sensor
	//call the US Driver or Function
	printf("US_init\n");
}

STATE_define(US_busy)
{
	//Sate Action
	US_state_id = US_busy ;
	distance = generate_random(45,55,1);
	printf("US_busy : distance = %d\n",distance);

	US_distance_set(distance);
	US_state = STATE(US_busy);

}
