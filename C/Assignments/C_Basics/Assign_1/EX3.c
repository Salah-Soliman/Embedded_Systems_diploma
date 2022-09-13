/*
 * EX3.c
 * Created on: Sep 13, 2022
 * Author: salah soliman
 */
#include "stdio.h"

int main()
{
	int x,y ;
	printf("Enter two integers: ");
	fflush(stdin); fflush(stdout);
	scanf("%d %d",&x,&y);
	printf("Sum: %d",x+y);
}

