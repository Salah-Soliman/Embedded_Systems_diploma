/*
 * PressureSensor.c
 *
 *  Created on: Nov 25, 2023
 *      Author: Salah Saliman
 */
#include "PressureSensor.h"

//Module Variables

unsigned int PressureVal ;

//Module APIs
/*
void PS_init()
{
	//Pressure Sensor Init();
	printf("PS_Init... \n");
}
*/

STATE_define(PS_Reading)
{
	PS_state_id = PS_Reading ;
	PressureVal = getPressureVal();
	//printf("PS_Reading : Pressure = %d Par \n",PressureVal);

	Get_sensor_val(PressureVal); //send the PressureVal to HP_detectionModule

	PS_state = STATE(PS_Reading);
}
