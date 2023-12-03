/*
 * PressureSensoor.h
 *
 *  Created on: Nov 25, 2023
 *      Author: Salah Saliman
 */

#ifndef PRESSURESENSOR_H_
#define PRESSURESENSOR_H_

#include "driver/driver.h"
#include "state.h"

//Pressure Sensor Module States
enum
{
	PS_Reading
}PS_state_id;


//APIs protoTypes
//void PS_init();
STATE_define(PS_Reading);

//Connectors Prototypes
extern void Get_sensor_val(int);

//pointer to function to control modules switching
void (* PS_state)();

#endif /* PRESSURESENSOR_H_ */
