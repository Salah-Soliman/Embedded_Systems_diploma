/*
 * EX4.c
 * Created on: Sep 18, 2022
 * Author: salah soliman
 */
#include "stdio.h"
#include "string.h"

int multiple=1;
int square( int b,int p)
{
	multiple*=b;
	if(p!=1)
	{
		square(b,p-1);
	}
	return multiple;
}

int main()
{
	int base,power ;
	printf("Enter base: ");
	fflush(stdin);    fflush(stdout);
	scanf("%d",&base);

	printf("Enter power number(positive integer): ");
	fflush(stdin);    fflush(stdout);
	scanf("%d",&power);

	printf("%d^%d = %d",base,power,square(base,power));

}

