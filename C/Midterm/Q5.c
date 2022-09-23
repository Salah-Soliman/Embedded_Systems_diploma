#include <stdio.h>

int	ones_count(int num)
{
	int i,c=0 ;

	for(i=0;i<32;i++)
	{
		if((1<<i)&num)
		{
			c++;
		}
	}

	return c;
}

int main ()
{
	int number ;
	printf("Enter the number to count the ones in its binary : ");
	fflush(stdin);    fflush(stdout);
	scanf("%d",&number);

	printf("The number of ones is : %d",ones_count(number));

}

