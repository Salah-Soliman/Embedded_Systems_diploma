/*
 * EX1.c
 * Created on: Sep 15, 2022
 * Author: salah soliman
 */
#include "stdio.h"
#include"math.h"

int main()
{
	float a[2][2];
	float b[2][2];
	float sum[2][2];

	printf("Enter the elements of the 1st matrix\n");
	fflush(stdin);     fflush(stdout);

	for(int i=0;i<2;i++)
	{
		for(int j=0;j<2;j++)
		{
			printf("Enter a%d%d: ",i+1,j+1);
			fflush(stdin);     fflush(stdout);
			scanf("%f",&a[i][j]);
		}
	}


	printf("Enter the elements of the 2nd matrix\n");
	fflush(stdin);     fflush(stdout);

	for(int i=0;i<2;i++)
	{
		for(int j=0;j<2;j++)
		{
			printf("Enter b%d%d: ",i+1,j+1);
			fflush(stdin);     fflush(stdout);
			scanf("%f",&b[i][j]);
		}
	}


	for(int i=0;i<2;i++)
	{
		for(int j=0;j<2;j++)
		{
			sum[i][j]=a[i][j]+b[i][j];
		}
	}


	printf("Sum of matrix:\n");

	for(int i=0;i<2;i++)
	{
		for(int j=0;j<2;j++)
		{
			fflush(stdin);     fflush(stdout);
			printf("%f    ",sum[i][j]);
		}

		printf("\n");

	}

}


