/*
 * AlarmActuator.c
 *
 *  Created on: Nov 25, 2023
 *      Author: Salah Saliman
 */

#include "AlarmActuator.h"

//Module Variables
unsigned int Alarm_state = 0 ;

//Module APIs

void AA_init()
{
	//Alarm Actuator Init();
	//printf("AA_Init... \n");
	Set_Alarm_actuator(0);
}


void Get_alarm_state(int state)
{
	Alarm_state = state ;
	/*
	if (Alarm_state == 1)
	{
		printf("AM ------ Signal: Alarm Start  ------> AA \n");
	}
	else if (Alarm_state == 0)
	{
		printf("AM ------ Signal: Alarm Stop  ------> AA \n");
	}
	*/
	AA_state = STATE(Setting_Alarm_State);
}


STATE_define(Setting_Alarm_State)
{
	AA_state_id = Setting_Alarm_State ;
	/*
	if (Alarm_state == 1)
	{
		printf("AA ------> Alarm is On  \n");
	}
	else if (Alarm_state == 0)
	{
		printf("AA ------> Alarm is Off  \n\n\n");
	}
	*/
	Set_Alarm_actuator(Alarm_state);
}
