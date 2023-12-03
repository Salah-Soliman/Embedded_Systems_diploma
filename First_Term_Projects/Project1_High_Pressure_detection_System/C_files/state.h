/*
 * state.h
 *
 *  Created on: Nov 25, 2023
 *      Author: Salah Soliman
 */

#ifndef STATE_H_
#define STATE_H_

#define STATE_define(_stateFunc_) void ST_##_stateFunc_()
#define STATE(_stateFunc_) ST_##_stateFunc_

#include <stdlib.h>

//main Prototypes
void setup();

#endif /* STATE_H_ */
