/*
 * EX3.c
 * Created on: Sep 28, 2022
 * Author: salah soliman
 */
#include "stdio.h"
#include "string.h"

int main()
{
	char str[50] ;
	int i;
	printf("Input a string : ");
	fflush(stdin);    fflush(stdout);
	gets(str);

	char* ptr=&str[strlen(str)-1];
	printf("The Alphabets are :\n");

	printf("Reverse of the string is : ");
	for(i=0;i<=strlen(str)-1;i++)
	{
		printf("%c",*ptr--);
	}

}
