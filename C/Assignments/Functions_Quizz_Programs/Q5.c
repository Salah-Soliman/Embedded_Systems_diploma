#include <stdio.h>
#include <string.h>

int clear_bit(int n,int i)
{
	return n&=~(1<<i);
}

int main ()
{
	int num,indx;
	printf("Input number:");
	fflush(stdin); fflush(stdout);
	scanf("%d",&num);

	printf("Bit position:");
	fflush(stdin); fflush(stdout);
	scanf("%d",&indx);

	printf("The result:%d",clear_bit(num,indx));

}

