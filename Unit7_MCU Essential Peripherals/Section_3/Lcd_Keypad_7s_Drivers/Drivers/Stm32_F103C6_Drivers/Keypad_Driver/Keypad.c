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


	//-------------------------------------------
	//set upper part of keypad port as input
	//KeypadDDR &=~(0x0F);
	//KeypadDDR &=~((1<<R0)|(1<<R1)|(1<<R2)|(1<<R3));
	PinCfg.GPIO_PinNumber = R0 ;
	PinCfg.GPIO_Mode = GPIO_Mode_Output_PP;
	PinCfg.GPIO_Output_Speed = GPIO_Speed_10M ;
	MCAL_GPIO_Init_Port_Range(KeypadPORT,&PinCfg,2);

	PinCfg.GPIO_PinNumber = R2 ;
	PinCfg.GPIO_Mode = GPIO_Mode_Output_PP;
	PinCfg.GPIO_Output_Speed = GPIO_Speed_10M ;
	MCAL_GPIO_Init_Port_Range(KeypadPORT,&PinCfg,6);


	MCAL_GPIO_WritePort(KeypadPORT, 0xFF);

}

char Keypad_Getkey()
{

	int i,j;
	for(i=0; i<4; i++)
	{
		//KeypadPORT |=((1<<KeypadCol[0])|(1<<KeypadCol[1])|(1<<KeypadCol[2])|(1<<KeypadCol[3])) ;
		MCAL_GPIO_WritePin(KeypadPORT, KeypadCol[0] , GPIO_Pin_Set);
		MCAL_GPIO_WritePin(KeypadPORT, KeypadCol[1] , GPIO_Pin_Set);
		MCAL_GPIO_WritePin(KeypadPORT, KeypadCol[2] , GPIO_Pin_Set);
		MCAL_GPIO_WritePin(KeypadPORT, KeypadCol[3] , GPIO_Pin_Set);

		//KeypadPORT &=~(1<<KeypadCol[i]); //send low to the next coulomb to check which intersect is pushed
		MCAL_GPIO_WritePin(KeypadPORT,KeypadCol[i] ,GPIO_Pin_Reset);

		for(j=0; j<4; j++)
		{
			if(MCAL_GPIO_ReadPin(KeypadPORT, KeypadRow[j]) == 0) //check if key is pressed
			{
				while(MCAL_GPIO_ReadPin(KeypadPORT, KeypadRow[j]) == 0);
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
