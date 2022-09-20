#include <stdio.h>
#include <string.h>

int Fourth_Sbit(int n)
{
	int bits[4],i;
	for(i=0;i<4;i++)
	{
		bits[i]=n%2;
		n/=2;
	}

	return bits[3];
}

int main ()
{
	int num;
	printf("Enter an integer number:");
	fflush(stdin); fflush(stdout);
	scanf("%d",&num);

	printf("The 4th least significant Bit is:%d",Fourth_Sbit(num));

}

