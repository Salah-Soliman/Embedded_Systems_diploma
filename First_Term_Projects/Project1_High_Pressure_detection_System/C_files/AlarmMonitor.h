/*
 * AlarmMonitor.h
 *
 *  Created on: Nov 25, 2023
 *      Author: Salah Saliman
 */

#ifndef ALARMMONITOR_H_
#define ALARMMONITOR_H_

#include "state.h"
#include "driver/driver.h"

//Alarm Monitor Module States
enum
{
	Alarm_Stop,
	Alarm_Start,
	waiting
}AM_state_id;

//APIs Prototypes

void High_pressure_detected();
STATE_define(Alarm_Stop);
STATE_define(Alarm_Start);
STATE_define(waiting);
void Pulling_intervals();

//Connectors Prototypes
extern void Get_alarm_state(int);




//pointer to function to control state switching
void (* AM_state)();

#endif /* ALARMMONITOR_H_ */
