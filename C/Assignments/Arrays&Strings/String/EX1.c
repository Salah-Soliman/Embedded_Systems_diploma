/*
 * EX1.c
 * Created on: Sep 16, 2022
 * Author: salah soliman
 */
#include "stdio.h"

int main()
{
	char c,arr[100];
	int counter=0;
	printf("Enter a string: ");
	fflush(stdin);     fflush(stdout);
	gets(arr);

	printf("Enter a character to find frequency: ");
	fflush(stdin);     fflush(stdout);
	scanf("%c",&c);


	for(int i=0;arr[i]!=0;i++)
	{
		if(arr[i]==c)
		{
			counter+=1;
		}
	}
	printf("Frequency of %c = %d",c,counter);

}


