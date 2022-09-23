#include <math.h>
#include <stdio.h>

float square_root(float num)
{
	return pow(10, 0.5 * log10(num));
}


int main()
{

	int number;
	printf("Enter an number to find its square root : ");
	fflush(stdin);    fflush(stdout);
	scanf("%d",&number);

	printf("The square root is : %f",square_root(number));


}
