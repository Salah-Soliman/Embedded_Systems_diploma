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
	SetBit(DDRD,4) ;
	ClearBit(PORTD,4) ;
	
	DDRC = 0xFF;
	PORTC = 0x00;
	
	//Input Init
	//Configure PortD Pin0 as Input Pin
	ClearBit(DDRD,0);
	//init PortC Pin0 as Pull down Input Pin
	SetBit(PORTD,0) ;
	
	//Configure PortD Pin1 as Input Pin
	ClearBit(DDRD,1);
	//init PortC Pin1 as Pull down Input Pin
	SetBit(PORTD,1) ;
}
int main(void)
{
	IO_init();
	int i,j,inputVal;
    while(1)
    {
		inputVal = PIND & 0xFF ;
		switch(inputVal)
		{
			case 1:
				SetBit(PORTD,4);
				_delay_ms(3000);
				ClearBit(PORTD,4) ;
				_delay_ms(3000);
				break;
			case 2:
				for (i=0; i<10; i++)
				{
					for(j=0; j<10; j++)
					{
						PORTC =0b0111 | (j<<4) ;
						_delay_ms(1000);
						PORTC=0b1011 | (i<<4) ;
						_delay_ms(1000);
					}
				}
				PORTC =0x00;
				break;
			
				
		}
		
    }
}