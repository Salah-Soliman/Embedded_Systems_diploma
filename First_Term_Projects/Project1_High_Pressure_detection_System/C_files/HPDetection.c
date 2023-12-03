/*
 * HPDetection.c
 *
 *  Created on: Nov 27, 2023
 *      Author: Salah Soliman
 */
#include "HPDetection.h"

//Module Variables
unsigned int PressureVal ;
unsigned int Threshold = 20 ;

//Module APIs
void Get_sensor_val(int PVal)
{
	PressureVal = PVal ;
	//printf("PS ------ Pressure = %d Par  ------> HPD \n",PressureVal);
	HPD_state = STATE(checking);
}

int ST_checking()
{
	HPD_state_id = checking ;
	if (PressureVal>Threshold)
	{
		//printf("High Pressure Detected in the cabin.. !!! Alarm Will Be triggered\n");
		High_pressure_detected(); //send signal to the alarm monitor module to trigger the alarm
		return 1 ;
	}
	else
	{
		//printf("Cabin Pressure in Normal State ...Enjoy your Flight \n\n\n");
		return 0 ;
	}
}


