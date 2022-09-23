#include <stdio.h>
#include <math.h>

int	sum_digits(int num)
{
	int digit,sum=0;
	while(num>0)
	{
		digit=num%10;
		sum+=digit;
		num/=10;
	}

	return sum;
}

int main ()
{
	int number ;
	printf("Enter an number to sum its digits : ");
	fflush(stdin);    fflush(stdout);
	scanf("%d",&number);

	printf("The sum of the digits is : %d",sum_digits(number));

}


