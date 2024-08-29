/*
 * AmitLCD.c
 *
 * Created: 8/29/2024 8:43:36 AM
 *  Author: salah soliman
 */ 

#include "lcd.h"
#define F_CPU 80000000UL

int main(void)
{
	LCD_INIT();
	LCD_WRITE_STRING("Learn In Depth");
}