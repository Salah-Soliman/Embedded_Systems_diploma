/*
 * EX1.c
 * Created on: Sep 13, 2022
 * Author: salah soliman
 */
#include "stdio.h"

int main()
{
	int x;
	printf("Enter an integer number you want to check : ");
	fflush(stdin);   fflush(stdout);
	scanf("%d",&x);
	x%2==0?printf("%d is even",x):printf("%d is odd",x);
}
