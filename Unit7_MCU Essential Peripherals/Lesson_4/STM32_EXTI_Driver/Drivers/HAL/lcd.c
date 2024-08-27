/*
 * lcd.c
 *
 * Created:
 *  Author: Salah Soliman
 */ 
#include "lcd.h"



void _delay_ms(int x)
{
	unsigned i,j ;
	for(i=0; i<x; i++)
		for(j=0; j<255; j++);
}


void LCD_clear_screen()
{
	LCD_WRITE_COMMAND(LCD_CLEAR_SCREEN);
}


void LCD_INIT()
{
	
	_delay_ms(20);

	// SET THE 3 CTRL PINS AS OUTPUT

	PinCfg.GPIO_PinNumber = RS_SWITCH ;
	PinCfg.GPIO_Mode = GPIO_Mode_Output_PP ;
	PinCfg.GPIO_Output_Speed = GPIO_Speed_10M ;
	MCAL_GPIO_Init_Port_Range(LCD_CTRL, &PinCfg,3);

	_delay_ms(15);
	
	// SET THE 8 DATA PINS AS OUTPUT
	PinCfg.GPIO_PinNumber = GPIO_Pin_0 ;
	PinCfg.GPIO_Mode = GPIO_Mode_Output_PP;
	PinCfg.GPIO_Output_Speed = GPIO_Speed_10M ;
	MCAL_GPIO_Init_Port_Range(LCD_Port, &PinCfg,8);

	LCD_clear_screen();
	
	//#ifdef EIGHT_BIT_MODE
	LCD_WRITE_COMMAND(LCD_FUNCTION_8BIT_2LINES);
	// #endif
	
//	#ifdef FOUR_BIT_MODE
//	LCD_WRITE_COMMAND(0x02);
//	LCD_WRITE_COMMAND(LCD_FUNCTION_4BIT_2LINES);
//	#endif
	
	LCD_WRITE_COMMAND(LCD_ENTRY_MODE);
	LCD_WRITE_COMMAND(LCD_BEGIN_AT_FIRST_ROW);
	LCD_WRITE_COMMAND(LCD_DISP_ON_CURSOR_BLINK);
}

void LCD_lcd_kick()
{
	MCAL_GPIO_WritePin(LCD_CTRL, EN_SWITCH, GPIO_Pin_Set);
	_delay_ms(50);
 	MCAL_GPIO_WritePin(LCD_CTRL, EN_SWITCH, GPIO_Pin_Reset);
}

void LCD_check_lcd_isbusy()
{
	PinCfg.GPIO_PinNumber = GPIO_Pin_0 ;
	PinCfg.GPIO_Mode = GPIO_Mode_Input_FLO ;
	MCAL_GPIO_Init_Port_Range(LCD_Port,&PinCfg,8);

	MCAL_GPIO_WritePin(LCD_CTRL, RW_SWITCH, GPIO_Pin_Set);
	MCAL_GPIO_WritePin(LCD_CTRL, RS_SWITCH, GPIO_Pin_Reset);

	LCD_lcd_kick();

	PinCfg.GPIO_PinNumber = GPIO_Pin_0 ;
	PinCfg.GPIO_Mode = GPIO_Mode_Output_PP;
	PinCfg.GPIO_Output_Speed = GPIO_Speed_10M ;
	MCAL_GPIO_Init_Port_Range(LCD_Port,&PinCfg,8);

	MCAL_GPIO_WritePin(LCD_CTRL, RW_SWITCH, GPIO_Pin_Reset);
}


void LCD_GOTO_XY(unsigned char line, unsigned char position)
{
	if (line == 1)
	{
		if (position < 16 && position >= 0)
		{
			LCD_WRITE_COMMAND(LCD_BEGIN_AT_FIRST_ROW+position);
		}
	}
	if (line == 2)
	{
		if (position < 16 && position >= 0)
		{
			LCD_WRITE_COMMAND(LCD_BEGIN_AT_SECOND_ROW+position);
		}
	}
}

void LCD_WRITE_COMMAND(unsigned char command)
{
	//#ifdef EIGHT_BIT_MODE
		LCD_check_lcd_isbusy();
		MCAL_GPIO_WritePort(LCD_Port, command);

		MCAL_GPIO_WritePin(LCD_CTRL, RS_SWITCH, GPIO_Pin_Reset);
		MCAL_GPIO_WritePin(LCD_CTRL, RW_SWITCH, GPIO_Pin_Reset);

		_delay_ms(1);
		LCD_lcd_kick();
	//#endif
	
//	#ifdef FOUR_BIT_MODE
//		LCD_check_lcd_isbusy();
//		LCD_PORT = (LCD_PORT & 0x0F) | (command & 0xF0);
//		LCD_CTRL &= ~ ((1<<RW_SWITCH)|(1<<RS_SWITCH));
//		LCD_lcd_kick ();
//		LCD_PORT = (LCD_PORT & 0x0F) | (command << 4);
//		LCD_CTRL &= ~ ((1<<RW_SWITCH)|(1<<RS_SWITCH));
//		LCD_lcd_kick();
//	#endif
}

void LCD_WRITE_CHAR(unsigned char character)
{
	//#ifdef EIGHT_BIT_MODE
		LCD_check_lcd_isbusy();
		MCAL_GPIO_WritePort(LCD_Port, character);
		MCAL_GPIO_WritePin(LCD_CTRL, RW_SWITCH, GPIO_Pin_Reset);
		MCAL_GPIO_WritePin(LCD_CTRL, RS_SWITCH, GPIO_Pin_Set);
		_delay_ms(1);
		LCD_lcd_kick();
	//#endif
	
//	#ifdef FOUR_BIT_MODE
//		LCD_PORT = (LCD_PORT & 0x0F) | (character & 0xF0);
//		LCD_CTRL |= 1<<RS_SWITCH; //turn RS ON for Data mode.
//		LCD_CTRL &= ~ (1<<RW_SWITCH);//turn RW off so you can write.
//		LCD_lcd_kick();
//		LCD_PORT = (LCD_PORT & 0x0F) | (character << 4);
//		LCD_CTRL |= 1<<RS_SWITCH; //turn RS ON for Data mode.
//		LCD_CTRL &= ~ (1<<RW_SWITCH);//turn RW off so you can write.
//		LCD_lcd_kick ();
//	#endif
}

void LCD_WRITE_STRING(char* string)
{
	int count = 0;
	while (*string > 0)
	{
		count++;
		LCD_WRITE_CHAR(*string++);
		if (count == 16)
		{
			LCD_GOTO_XY(2,0);
		}
		else if (count == 32)
		{
			LCD_clear_screen();
			LCD_GOTO_XY(1,0);
			count = 0;
		}
	}
}

