/*
 * Keypad.h
 *
 * Created:
 *  Author: Salah Soliman
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_

#include "MemMap.h"
#include<util/delay.h>

//keypad Information
#define R0 0
#define R1 1
#define R2 2
#define R3 3
#define C0 4
#define C1 5
#define C2 6
#define C3 7

#define KeypadPORT PORTD 
#define KeypadPIN PIND
#define KeypadDDR DDRD

//keypad Functions and variables

void Keypad_Init();
char Keypad_Getkey();


#endif /* KEYPAD_H_ */