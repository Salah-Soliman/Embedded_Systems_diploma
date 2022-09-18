/*
 * EX2.c
 * Created on: Sep 18, 2022
 * Author: salah soliman
 */
#include "stdio.h"
#include "string.h"

int fact=1;
int factorial(int n)
{
	fact*=n;
	if(n==1)
	{
		return fact ;
	}
	else
	{
		factorial(n-1);
	}
}

int main()
{
	int num ;
	printf("Enter a positive integer:");
	fflush(stdin);    fflush(stdout);
	scanf("%d",&num);

	if(num==0)
	{
		printf("Factorial of %d = %d",num, 1);
	}
	else
	{
		printf("Factorial of %d = %d",num, factorial(num));
	}

}
