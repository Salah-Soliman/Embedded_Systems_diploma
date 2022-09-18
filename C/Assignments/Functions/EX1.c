/*
 * EX1.c
 * Created on: Sep 18, 2022
 * Author: salah soliman
 */
#include "stdio.h"
#include "string.h"

void prime_between(int a,int b)
{
	int i,j;
	printf("prime numbers between %d and %d are: ",a,b);
	for(i=a+1;i<b;i++)
	{
		for(j=i-1;j>1;j--)
		{
			if(i%j==0)
			{
				break;
			}
			else if (j==2)
			{
				printf("%d ",i);
			}
		}
		if(i==2)
		{
			printf("2 ");
		}
	}
}
int main()
{
	int s,l;
	printf("Enter two numbers(intervals)");
	fflush(stdin);    fflush(stdout);
	scanf("%d %d",&s,&l);
	prime_between(s,l);
}
