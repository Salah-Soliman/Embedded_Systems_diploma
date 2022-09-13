/*
 * EX4.c
 * Created on: Sep 13, 2022
 * Author: salah soliman
 */
#include "stdio.h"

int main()
{
	float x;
	printf("Enter a number: ");
	fflush(stdin);   fflush(stdout);
	scanf("%f",&x);
	if(x==0)
	{
		printf("You entered zero");
	}
	else if(x>0)
	{
		printf("%f is positive",x);
	}
	else
	{
		printf("%f is negative",x);
	}
}
