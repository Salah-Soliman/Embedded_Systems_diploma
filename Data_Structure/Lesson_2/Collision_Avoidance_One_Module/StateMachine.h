/*
 * StateMachine.h
 *
 *  Created on: Nov 16, 2023
 *      Author: bebo
 */

#ifndef STATEMACHINE_H_
#define STATEMACHINE_H_

#include "state.h"

enum {
	waiting,
	driving
}state_id;

//prototypes

STATE_define(waiting);
STATE_define(driving);
STATE_define(setup);
random_define(generate_random,int l ,int r ,int count);

void (* state)();

#endif /* STATEMACHINE_H_ */
