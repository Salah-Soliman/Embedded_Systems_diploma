/*
 * EX2.c
 * Created on: Sep 16, 2022
 * Author: salah soliman
 */
#include "stdio.h"

int main()
{
	char arr[100];
	int counter=0;
	printf("Enter a string: ");
	fflush(stdin);     fflush(stdout);
	gets(arr);




	for(int i=0;arr[i]!=0;i++)
	{
		if(arr[i]!=' ')
		{
			counter+=1;
		}
	}
	printf("The length of string: %d",counter);

}


