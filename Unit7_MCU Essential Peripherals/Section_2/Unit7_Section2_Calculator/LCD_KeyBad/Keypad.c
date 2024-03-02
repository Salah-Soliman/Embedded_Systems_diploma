/*
 * Keypad.c
 *
 * Created:
 *  Author: salah soliman
 */ 

#include "Keypad.h"

int KeypadRow[] = {R0,R1,R2,R3};	//keypad rows
int KeypadCol[] = {C0,C1,C2,C3};	//Keypad coulomb

void Keypad_Init()
{
	//set upper part of keypad port as input
	//KeypadDDR &=~(0x0F);
	KeypadDDR &=~((1<<R0)|(1<<R1)|(1<<R2)|(1<<R3));
	//set lower part of keypad port as output
	//KeypadDDR |=(0xF0);
	KeypadDDR |=((1<<C0)|(1<<C1)|(1<<C2)|(1<<C3));
	
	KeypadPORT = 0xFF ;   //set Keypad Port as pull up
}

char Keypad_Getkey()
{
	int i,j;
	for(i=0; i<4; i++)
	{
		KeypadPORT |=((1<<KeypadCol[0])|(1<<KeypadCol[1])|(1<<KeypadCol[2])|(1<<KeypadCol[3])) ;
		KeypadPORT &=~(1<<KeypadCol[i]); //send low to the next coulomb to check which intersect is pushed
		
		for(j=0; j<4; j++)
		{
			if(!(KeypadPIN & (1<<KeypadRow[j]))) //check if key is pressed
			{
				while(!(KeypadPIN & (1<<KeypadRow[j])));
				switch(i)
				{
					case 0 :
					{
						if (j == 0) return '7';
						else if (j == 1) return '4';
						else if (j == 2) return '1';
						else if (j == 3) return '?';
						break;
					}
					case 1 :
					{
						if (j == 0) return '8';
						else if (j == 1) return '5';
						else if (j == 2) return '2';
						else if (j == 3) return '0';
						break;
					}
					case 2 :
					{
						if (j == 0) return '9';
						else if (j == 1) return '6';
						else if (j == 2) return '3';
						else if (j == 3) return '=';
						break;
					}
					case 3 :
					{
						if (j == 0) return '/';
						else if (j == 1) return '*';
						else if (j == 2) return '-';
						else if (j == 3) return '+';
						break;
					}
				}
			}
			
		}
	}
	return 'A';	//Return 'A' if no key is pressed
}