/*
 * HPDetection.h
 *
 *  Created on: Nov 27, 2023
 *      Author: Salah Soliman
 */

#ifndef HPDETECTION_H_
#define HPDETECTION_H_

#include "state.h"

//High Pressure Detection Module States
enum
{
	checking
}HPD_state_id;

//APIs Prototypes
void Get_sensor_val(int);
int ST_checking();

//Connectors Prototypes
extern void High_pressure_detected();

//pointer to function to control state switching
int (* HPD_state)();


#endif /* HPDETECTION_H_ */
