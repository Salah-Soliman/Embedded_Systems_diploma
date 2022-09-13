/*
 * EX5.c
 * Created on: Sep 13, 2022
 * Author: salah soliman
 */
#include "stdio.h"

int main()
{
	char x;
	printf("Enter a character: ");
	fflush(stdin);   fflush(stdout);
	scanf("%c",&x);
	if((91>x&&x>64)||(123>x&&x>96))
	{
		printf("%c is an alphabet",x);
	}

	else
	{
		printf("%c is not an alphabet",x);
	}
}
