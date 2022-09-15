/*
 * EX4.c
 * Created on: Sep 15, 2022
 * Author: salah soliman
 */
#include "stdio.h"
#include"math.h"

int main()
{
	int n,val,indx;
	printf("Enter number of elements: ");
	fflush(stdin);     fflush(stdout);
	scanf("%d",&n);
	int a[n+1];

	printf("Enter elements of the array: ");
	for(int i=0;i<n;i++)
	{
			fflush(stdin);     fflush(stdout);
			scanf("%d",&a[i]);
	}

	printf("Enter the element to be inserted :\n");
	fflush(stdin);     fflush(stdout);
	scanf("%d",&val);

	printf("Enter the location :\n");
	fflush(stdin);     fflush(stdout);
	scanf("%d",&indx);
	indx-=1;

	for(int i=n;i>=0;i--)
	{
		if(i==indx)
		{
			a[i]=val;
			break;
		}
		else
		{
			a[i]=a[i-1];
		}
	}

	printf("The elements of array after inserting:\n");
	for(int i=0;i<n+1;i++)
	{
		fflush(stdin);     fflush(stdout);
		printf("%d ",a[i]);
	}

}

