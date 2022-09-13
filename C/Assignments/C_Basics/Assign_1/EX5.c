/*
 * EX5.c
 * Created on: Sep 13, 2022
 * Author: salah soliman
 */
#include "stdio.h"

int main()
{
	char x ;
	printf("Enter a character: ");
	fflush(stdin); fflush(stdout);
	scanf("%c",&x);
	printf("ASCII value of %c = %d",x,x);
}
