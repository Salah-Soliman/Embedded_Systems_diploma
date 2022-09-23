#include "stdio.h"

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
	int n1,n2;
	printf("Enter n1: ");
	fflush(stdin);    fflush(stdout);
	scanf("%d",&n1);

	printf("Enter n2: ");
	fflush(stdin);    fflush(stdout);
	scanf("%d",&n2);

	prime_between(n1,n2);
}
