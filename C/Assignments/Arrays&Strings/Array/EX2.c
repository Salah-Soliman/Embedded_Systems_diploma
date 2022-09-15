/*
 * EX2.c
 * Created on: Sep 15, 2022
 * Author: salah soliman
 */
#include "stdio.h"
#include"math.h"

int main()
{
	int n ;
	printf("Enter the number of the data: ");
	fflush(stdin);     fflush(stdout);
	scanf("%d",&n);

	float a[n],sum=0;

	for(int i=0;i<n;i++)
	{
		printf("Enter number: ");
		fflush(stdin);     fflush(stdout);
		scanf("%f",&a[i]);
	}


	for(int i=0;i<n;i++)
	{
		sum+=a[i];
	}

	printf("Average = %f",sum/n);

}


