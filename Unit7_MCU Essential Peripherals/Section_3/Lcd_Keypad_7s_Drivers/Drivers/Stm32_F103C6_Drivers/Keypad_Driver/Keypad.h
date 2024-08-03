/*
 * Keypad.h
 *
 * Created:
 *  Author: Salah Soliman
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_

#include "Stm32_F103C6_GPIO_Driver.h"
#include "Stm32f103x6.h"

//keypad Information
#define R0 GPIO_Pin_0
#define R1 GPIO_Pin_1
#define R2 GPIO_Pin_3
#define R3 GPIO_Pin_4
#define C0 GPIO_Pin_5
#define C1 GPIO_Pin_6
#define C2 GPIO_Pin_7
#define C3 GPIO_Pin_8

#define KeypadPORT GPIOB

GPIO_PinConfig_t PinCfg ;

//keypad Functions and variables

void Keypad_Init();
char Keypad_Getkey();


#endif /* KEYPAD_H_ */
