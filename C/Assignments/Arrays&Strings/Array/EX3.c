/*
 * EX3.c
 * Created on: Sep 15, 2022
 * Author: salah soliman
 */
#include "stdio.h"
#include"math.h"

int main()
{
	int c,r;
	printf("Enter rows and column of the matrix: ");
	fflush(stdin);     fflush(stdout);
	scanf("%d%d",&r,&c);

	float a[r][c],a_t[c][r];

	printf("Enter elements of matrix matrix: ");
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
		{
			printf("Enter a%d%d: ",i+1,j+1);
			fflush(stdin);     fflush(stdout);
			scanf("%f",&a[i][j]);
		}
	}

	for(int i=0;i<c;i++)
	{
		for(int j=0;j<r;j++)
		{
			a_t[i][j]=a[j][i];
		}
	}

	printf("The entered matrix:\n");
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
		{
			fflush(stdin);     fflush(stdout);
			printf("%f    ",a[i][j]);
		}

		printf("\n");

	}

	printf("Transpose matrix:\n");
	for(int i=0;i<c;i++)
	{
		for(int j=0;j<r;j++)
		{
			fflush(stdin);     fflush(stdout);
			printf("%f    ",a_t[i][j]);
		}
		printf("\n");
	}

}
