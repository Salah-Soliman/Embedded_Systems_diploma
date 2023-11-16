/*
 * state.h
 *
 *  Created on: Nov 16, 2023
 *      Author: Salah Soliman
 */

#ifndef STATE_H_
#define STATE_H_

#define STATE_define(_stateFunc_) void ST_##_stateFunc_()
#define STATE(_stateFunc_) ST_##_stateFunc_


//#define function_define(function_name, ...) int function_name(__VA_ARGS__)
//#define function_call(function_name, ...)  function_name(__VA_ARGS__)


#include <stdio.h>
#include <stdlib.h>

//states Connection
void US_distance_set(int d);
void DC_motor(int s);
void setup();

#endif /* STATE_H_ */
