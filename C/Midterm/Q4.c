#include <stdio.h>

int	number_reverse(int num)
{
	int bit,dec=1,sum=0,i,number=num,c=-1;

	while(num>0)
	{
		c++;
		num/=10;
	}

	for(i=c;i>0;i--)
	{
		dec*=10;
	}

	while(number>0)
	{
		bit=number%10;
		sum+=bit*dec;
		dec/=10;
		number/=10;
	}

	return sum;
}

int main ()
{
	int number ;
	printf("Enter an number to reverse : ");
	fflush(stdin);    fflush(stdout);
	scanf("%d",&number);

	printf("The reverse of the number is : %d",number_reverse(number));

}
