/*
 * CA.h
 *
 *  Created on: Nov 16, 2023
 *      Author: Salah Soliman
 */

#ifndef CA_H_
#define CA_H_

#include "state.h"

enum {
	CA_waiting,
	CA_driving
}CA_state_id;

//Prototyping
STATE_define(CA_waiting);
STATE_define(CA_driving);

void (* CA_state)();



#endif /* CA_H_ */
