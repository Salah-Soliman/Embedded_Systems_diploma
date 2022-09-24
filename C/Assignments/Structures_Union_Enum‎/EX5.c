#include <stdio.h>
#define area(r) (3.1415*r*r)

int main ()
{
	float rad;
	printf("enter the the circle radius : ");
	fflush(stdin);  fflush(stdout);
	scanf("%f",&rad);

	printf("the area of the circle = %0.2f",area(rad));

}
