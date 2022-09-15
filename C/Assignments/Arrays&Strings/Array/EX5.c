/*
 * EX5.c
 * Created on: Sep 15, 2022
 * Author: salah soliman
 */
#include "stdio.h"

int main()
{
	int n,val;
	printf("Enter number of elements: ");
	fflush(stdin);     fflush(stdout);
	scanf("%d",&n);
	int a[n];

	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("Enter the element to be searched :");
	fflush(stdin);     fflush(stdout);
	scanf("%d",&val);

	for(int i=0;i<n;i++)
	{
		if(a[i]==val)
		{
			printf("The number found at location = %d",i+1);
			break;
		}
		else if (i==(n-1))
		{
			printf("The number %d not found",val);
		}

	}

}


