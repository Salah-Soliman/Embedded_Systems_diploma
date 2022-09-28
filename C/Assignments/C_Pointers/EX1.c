/*
 * EX1.c
 * Created on: Sep 28, 2022
 * Author: salah soliman
 */
#include "stdio.h"

int main()
{
	int m = 29;
	printf("The address of m : 0x%x\n",&m);
	printf("Value of m : %d\n",m);

	int* ab =&m;
	printf("\nNow ab is assigned with the address of m\n");
	printf("The address of ab : 0x%x\n",ab);
	printf("Value of ab : %d\n",*ab);

	m = 34;
	printf("\nThe value of m assigned to 34 now\n");
	printf("The address of ab : 0x%x\n",ab);
	printf("Value of ab : %d\n",*ab);

	*ab=7;
	printf("\nThe pointer variable ab is assigned with the value 7 now\n");
	printf("The address of m : 0x%x\n",&m);
	printf("Value of m : %d\n",m);
}
