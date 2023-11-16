/*
 * DC_Motor.h
 *
 *  Created on: Nov 16, 2023
 *      Author: Salah Soliman
 */

#ifndef DC_MOTOR_H_
#define DC_MOTOR_H_

#include "state.h"

enum {
	DC_idle,
	DC_busy
}DC_state_id;

//protoTypes
void DC_init();
STATE_define(DC_idle);
STATE_define(DC_busy);

void (* DC_state)();

#endif /* DC_MOTOR_H_ */
