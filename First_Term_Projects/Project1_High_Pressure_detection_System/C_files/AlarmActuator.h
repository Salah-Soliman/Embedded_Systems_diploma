/*
 * AlarmActuator.h
 *
 *  Created on: Nov 25, 2023
 *      Author: Salah Saliman
 */

#ifndef ALARMACTUATOR_H_
#define ALARMACTUATOR_H_

#include "driver/driver.h"
#include "state.h"

//Alarm Actuator Module States
enum
{
	Setting_Alarm_State
}AA_state_id;

//APIs Prototypes
void AA_init();
void Get_alarm_state(int);
STATE_define(Setting_Alarm_State);

//pointer to function to control state switching
void (* AA_state)();


#endif /* ALARMACTUATOR_H_ */
