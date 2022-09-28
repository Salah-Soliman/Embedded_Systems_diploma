/*
 * EX2.c
 * Created on: Sep 28, 2022
 * Author: salah soliman
 */
#include "stdio.h"

int main()
{
	char start='A',alpha[27] ;
	int i;
	for(i=0;i<26;i++)
	{
		alpha[i]=start;
		start++;
	}

	char* ptr=alpha;
	printf("The Alphabets are :\n");

	for(i=0;i<26;i++)
	{
		printf("%c  ",*ptr++);
	}

}
