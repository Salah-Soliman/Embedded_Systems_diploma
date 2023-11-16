/*
 * US_Sensor.h
 *
 *  Created on: Nov 16, 2023
 *      Author: Salah Soliman
 */

#ifndef US_SENSOR_H_
#define US_SENSOR_H_

#include "state.h"

enum {
	US_busy
}US_state_id;

//protoTypes
void US_init();
int generate_random(int l ,int r ,int count);

STATE_define(US_busy);
void (* US_state)();

#endif /* US_SENSOR_H_ */
