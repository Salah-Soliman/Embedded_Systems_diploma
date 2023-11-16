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


#define random_define(generateRandom, ...) int generateRandom(__VA_ARGS__)
#define Random(generateRandom, ...)  generateRandom(__VA_ARGS__)




#include <stdio.h>
#include <stdlib.h>



#endif /* STATE_H_ */
