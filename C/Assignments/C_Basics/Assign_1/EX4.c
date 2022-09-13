/*
 * EX4.c
 * Created on: Sep 13, 2022
 * Author: salah soliman
 */
#include "stdio.h"

int main()
{
	float x,y ;
	printf("Enter two integers: ");
	fflush(stdin); fflush(stdout);
	scanf("%f %f",&x,&y);
	printf("Sum: %0.6f",x*y);
}

