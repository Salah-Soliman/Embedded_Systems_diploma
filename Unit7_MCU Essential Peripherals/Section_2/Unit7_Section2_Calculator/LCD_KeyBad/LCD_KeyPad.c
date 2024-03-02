/*
 * LCD_KeyBad.c
 *
 * Created: 2/12/2024 2:55:56 PM
 *  Author: salah soliman
 */ 


#define F_CPU 8000000UL
#include "lcd.h"
#include "Keypad.h"
#include "calculator.h"
#include "string.h"


int main(void)
{
	LCD_INIT();
	Keypad_Init();
	char keyinput,StrResult[20]="";
    while(1)
    {
		keyinput = Keypad_Getkey();
		Get_Operands(keyinput);
		
		switch(keyinput)
		{
			case 'A':
				break;
			case '?':
				LCD_clear_screen();
				break;
			case '=' :
				LCD_WRITE_CHAR(keyinput);
				Get_Cacls_Output(StrResult);
				LCD_WRITE_STRING(StrResult);
				Reset_Operands();
				strcpy(StrResult,"");
				break;
			default:
				LCD_WRITE_CHAR(keyinput);
		}
		
    }
}