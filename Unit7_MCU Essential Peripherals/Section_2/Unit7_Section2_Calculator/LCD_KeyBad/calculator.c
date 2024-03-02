/*
 * calculator.c
 *
 * Created:
 *  Author: salah soliman
 */ 

#include "calculator.h"

char n1[10]="", n2[10]="",operaton;
int result,num1,num2,flag=0;

void Get_Operands(char keyinput)
{
	
	while(keyinput != 'A' && keyinput != '=' && keyinput != '?')
	{
		if (keyinput != '/' && keyinput != '*' && keyinput != '-' && keyinput != '+')
		{
			switch(flag)
			{
				case 0 :
				strncat(n1,&keyinput , 1);
				break;
				case 1 :
				strncat(n2,&keyinput , 1);
				break;
			}
		}else
		{
			operaton = keyinput;
			flag = 1 ;
		}
		break;
	}
}

void Get_Cacls_Output(char* r[20])
{
	num1 = atoi(n1);
	num2 = atoi(n2);
	switch(operaton)
	{
		case '*':
		result = num1 * num2;
		break;
		case '/':
		result = num1 / num2;
		break;
		case '-':
		result = num1 - num2;
		break;
		case '+':
		result = num1 + num2;
		break;
	}
	sprintf(r, "%d", result);
}

void Reset_Operands()
{
	flag = 0 ;
	strcpy(n1,"");
	strcpy(n2,"");	
}
