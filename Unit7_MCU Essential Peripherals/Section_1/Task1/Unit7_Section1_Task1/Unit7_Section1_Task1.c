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
	//Configure PortA as OutPut Port
	DDRA = 0xFF ;
	//Init PortA with Zeros
	PORTA = 0 ;
}
int main(void)
{
	IO_init();
	int count = 0,Mutiplier=2,flag=1;
    while(1)
    {
		if(flag)
		{
			
			PORTA = Mutiplier-1;
			count ++ ;
			Mutiplier*=2 ;
			_delay_ms(3000) ;
			if(count == 8)
			{
				flag = 0 ;
			}
		}

		else
		{
			Mutiplier/=2 ;
			PORTA = Mutiplier-1;
			count -- ;
			_delay_ms(3000) ;
			if(count == -1)
			{
				flag = 1 ;
			}
		}
		
    }
}