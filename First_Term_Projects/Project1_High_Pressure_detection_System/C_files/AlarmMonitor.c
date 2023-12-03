/*
 * AlarmMonitor.c
 *
 *  Created on: Nov 25, 2023
 *      Author: Salah Saliman
 */

#include "AlarmMonitor.h"


//Module Variables
unsigned int AlarmPeriod = 60000  ;

//Module APIs
void High_pressure_detected()
{
	AM_state = STATE(Alarm_Start);
}


STATE_define(Alarm_Start)
{
	AM_state_id = Alarm_Start ;
	Get_alarm_state(1);//sending start signal to Alarm Actuator
	AM_state = STATE(waiting);
}

STATE_define(waiting)
{
	AM_state_id = waiting ;
	Delay(AlarmPeriod);
	STATE(Alarm_Stop)();
}


STATE_define(Alarm_Stop)
{
	AM_state_id = Alarm_Stop ;
	Get_alarm_state(0); //sending stop signal to Alarm Actuator
	//AM_state = Pulling_intervals ;
}

void Pulling_intervals() {
	Delay(AlarmPeriod);
}





