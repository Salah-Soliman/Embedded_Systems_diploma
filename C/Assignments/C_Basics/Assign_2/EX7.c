/*
 * EX7.c
 * Created on: Sep 13, 2022
 * Author: salah soliman
 */
#include "stdio.h"

int main()
{
	int x,fact=1;
	printf("Enter an integer: ");
	fflush(stdin);   fflush(stdout);
	scanf("%d",&x);

	if(x>0)
	{
		for(int i=1;i<=x;i++)
		{
			fact*=i;
		}
		printf("Factorial = %d",fact);
	}
	else if(x==0)
	{
		printf("Factorial = %d",fact);
	}
	else
	{
		printf("Error!!! Factorial of negative values doesn't exist");
	}
}


