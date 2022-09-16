/*
 * EX3.c
 * Created on: Sep 16, 2022
 * Author: salah soliman
 */
#include "stdio.h"
#include "string.h"

int main()
{
	char arr[100],temp;
	printf("Enter the string: ");
	fflush(stdin);     fflush(stdout);
	gets(arr);

	for(int i=0;i<=(strlen(arr)-1)/2;i++)
	{
		temp=arr[i];
		arr[i]=arr[strlen(arr)-1-i];
		arr[strlen(arr)-1-i]=temp;
	}
	printf("Reverse string is : %s",arr);

}


