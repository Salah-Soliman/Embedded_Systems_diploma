/*
 * EX4.c
 * Created on: Sep 28, 2022
 * Author: salah soliman
 */
#include "stdio.h"

int main()
{
	char arr[15] ;
	int i,num;

	printf("Input the number of elements to store in the array (max 15) : ");
	fflush(stdin);    fflush(stdout);
	scanf("%d",&num);

	printf("Input %d number of elements in the array :\n",num);
	for(i=0;i<num;i++)
	{
		printf("element - %d : ",i+1);
		fflush(stdin);    fflush(stdout);
		scanf("%c",&arr[i]);
	}
	char* ptr=&arr[num]-1;
	printf("\nThe elements of array in reverse order are : \n");
	for(i=num;i>0;i--)
	{
		printf("element - %d : %c\n",i,*ptr--);
	}
}
