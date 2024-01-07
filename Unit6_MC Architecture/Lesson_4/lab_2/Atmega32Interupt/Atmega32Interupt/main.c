/*
 * Atmega32Interupt.c
 *
 * Created: 1/6/2024 11:34:03 AM
 *  Author: Salah Soliman
 */ 

#define F_CPU 8000000UL
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#define IO_BASE 0x20
#define INT_MCUCR *(volatile unsigned int *)(IO_BASE + 0x35)
#define INT_MCUCSR *(volatile unsigned int *)(IO_BASE + 0x34)
#define INT_GICR *(volatile unsigned int *)(IO_BASE + 0x3B)
#define INT_GIFR *(volatile unsigned int *)(IO_BASE + 0x3A)
#define INT_SREG *(volatile unsigned int *)(IO_BASE + 0x3F)


void GPIO_init(void)
{
	//configure PORTD pins 2,3 and PORTD pin 2 as inputs for EXTI
	DDRB &= ~(1<<2);
	DDRD &= ~(11<<2);
	
	DDRD |= (111 << 5) ; //configure PORTD pins 5,6,7 as output for Leds
}

void EXTI_init(void)
{
	//trigger EXTI 0 on both rising and falling edges
	INT_MCUCR |= (1<<0) ;
	INT_MCUCR &= ~(1<<1) ;
	
	INT_MCUCR |= (11<<2) ; //trigger EXTI 1 on rising edge
	INT_MCUCSR &=~(1<<6) ; //trigger EXTI 2 on falling edge
	
	INT_GICR |= (111<<5); //Enable EXTI 0,1,2 Masks
	
	INT_SREG |= (1<<7) ; //Global interrupts Enable
}



int main(void)
{
	GPIO_init();
	EXTI_init();
	
    while(1)
    {
		PORTD &=~(111<<5) ; //Turn off all leds
    }
}



ISR(INT0_vect)
{
	PORTD |= (1<<5) ; //Turn On Led0
	GIFR |= (1<<6) ;  //Clear EXTI0  Pending Request Flag (write 1 to clear)
	_delay_ms(1000);  //waiting 1 sec
}
ISR(INT1_vect)
{
	PORTD |= (1<<6) ; //Turn On Led1
	GIFR |= (1<<7) ;  //Clear EXTI1  Pending Request Flag (write 1 to clear)
	_delay_ms(1000);  //waiting 1 sec
}	
ISR(INT2_vect)
{
	PORTB |= (1<<7) ;  //Turn On Led2
	GIFR |= (1<<5) ;   //Clear EXTI2  Pending Request Flag (write 1 to clear)
	_delay_ms(1000);   //waiting 1 sec
}
