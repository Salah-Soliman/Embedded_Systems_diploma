/*
 * EX7.c
 * Created on: Sep 13, 2022
 * Author: salah soliman
 */
#include "stdio.h"

int main()
{
	float a,b;
	printf("Enter value of a: ");
	fflush(stdin); fflush(stdout);
	scanf("%f",&a);
	printf("Enter value of b: ");
	fflush(stdin); fflush(stdout);
	scanf("%f",&b);
	a*=b;
	b=a/b;
	a/=b;
	printf("\nAfter swapping, value of a = %f ",a);
	printf("\nAfter swapping, value of b = %f ",b);
}

