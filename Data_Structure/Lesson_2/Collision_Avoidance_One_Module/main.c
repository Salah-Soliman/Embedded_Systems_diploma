/*
 * main.c
 *
 *  Created on: Nov 16, 2023
 *      Author: Salah Soliman
 */

#include "StateMachine.h"

int main()
{
	volatile int d ;
	STATE(setup)();
	while(1)
	{
		state();
		//delay
		for(d=0 ;d<=1000 ;d++);
	}
}
