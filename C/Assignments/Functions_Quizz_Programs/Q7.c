#include <stdio.h>
#include <math.h>

int is_power_of3(int n)
{
	int i;
	float j;
	j=log(n)/log(3);
	i=(int)j;
	if(i==j)
	{
		return 0 ;
	}
	else
	{
		return 1 ;
	}
}

int main ()
{
	int num;
	printf("Enter the number to check:");
	fflush(stdin); fflush(stdout);
	scanf("%d",&num);

	printf("==>%d",is_power_of3(num));

}

