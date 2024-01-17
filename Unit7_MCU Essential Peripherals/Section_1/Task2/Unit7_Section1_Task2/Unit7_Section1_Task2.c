/*
 * Unit7_Section1_Task1.c
 *
 * Created: 1/14/2024 5:01:01 PM
 *  Author: Salah Soliman
 */ 

#include "MemMap.h"
#include "Utilites.h"
#include "util/delay.h"
#define F_CPU 8000000UL

void IO_init(void)
{
	//Output Init
	//Configure PortA as OutPut Port
	DDRA = 0xFF ;
	//Init PortA with Zeros
	PORTA = 0 ;
	
	//Input Init
	//Configure PortC Pin0 as Input Pin
	ClearBit(DDRC,0);
	//init PortC Pin0 as Pull up Input Pin
	SetBit(PORTC,0) ;
}
int main(void)
{
	IO_init();
	int count = 0,Mutiplier=1,flag=1;
    while(1)
    {
		if(ReadBit(PINC,0) == 0) //pressed
		{
			while(ReadBit(PINC,0) == 0) ;
			Mutiplier*=2 ;
			PORTA = Mutiplier-1;
			count ++ ;
			_delay_ms(3000) ;
			
			while(ReadBit(PINC,0) == 0); //single press				
		}
		if(count == 8 && ReadBit(PINC,0) == 0)
		{
			PORTA = 0 ;
			count = 0 ;
			Mutiplier = 1 ;
			_delay_ms(3000) ;
		}
	
    }
}