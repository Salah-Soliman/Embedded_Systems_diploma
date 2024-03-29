/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2023 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 ******************************************************************************
 */

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

typedef volatile unsigned int vuint32_t ;

//register address

//RCC
#define RCC_BASE	0x40021000
#define RCC_APB2ENR		*(vuint32_t *)(RCC_BASE + 0x18)

//GPIO
#define GPIOA_BASE	0x40010800
#define GPIOA_CRL	*(vuint32_t *)(GPIOA_BASE + 0x00)
#define GPIOA_CRH	*(vuint32_t *)(GPIOA_BASE + 0x04)
#define GPIOA_IDR	*(vuint32_t *)(GPIOA_BASE + 0x08)
#define GPIOA_ODR	*(vuint32_t *)(GPIOA_BASE + 0x0c)

#define GPIOA13		(1UL<<13)

#define GPIOB_BASE	0x40010C00
#define GPIOB_CRL	*(vuint32_t *)(GPIOB_BASE + 0x00)
#define GPIOB_CRH	*(vuint32_t *)(GPIOB_BASE + 0x04)
#define GPIOB_IDR	*(vuint32_t *)(GPIOB_BASE + 0x08)
#define GPIOB_ODR	*(vuint32_t *)(GPIOB_BASE + 0x0c)

void clock_init()
{
	//Init clock for GPIOA
	RCC_APB2ENR |= 1 << 2 ;

	//Init clock for GPIOB
	RCC_APB2ENR |= 1 << 3 ;
}

void GPIO_init()
{

	//PORTA.1  input floating mode
	GPIOA_CRL &=~(0b11<<4);
	GPIOA_CRL |=(0b01<<6);

	//PORTA.13  input floating mode
	GPIOA_CRH &=~(0b11<<20);
	GPIOA_CRH |=(0b01<<22);


	//PORTB.1  output push pull mode
	GPIOB_CRL |=(0b01<<4);
	GPIOB_CRL &=~(0b11<<6);

	//PORTB.13 output push pull mode
	GPIOB_CRH |=(0b01<<20);
	GPIOB_CRH &=~(0b11<<22);

}

void delay(int x)
{
	unsigned i,j ;
	for(i=0; i<x; i++)
		for(j=0; j<255; j++);
}
int main(void)
{
	clock_init();
	GPIO_init();

	while(1)
	{
		if(((GPIOA_IDR & (1<<1)) >>1) == 0) //pressed
		{
			GPIOB_ODR ^= (1<<1) ;
			while(((GPIOA_IDR & (1<<1)) >>1) == 0); //single press
		}

		if(((GPIOA_IDR & (1<<13)) >>13) == 1)  //multi press
		{
			GPIOB_ODR ^= (1<<13) ;
		}

		delay(1);

	}

}























