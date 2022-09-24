#include <stdio.h>

struct Scomplexnumber
{
	float real;
	float img;
};

void add_complex(struct Scomplexnumber num1, struct Scomplexnumber num2)
{
	printf("Sum=%0.2f+%0.2f i",num1.real+num2.real,num1.img+num2.img);
}

int main ()
{
	struct Scomplexnumber num1,num2;

	printf("Enter the 1st complex number:\n");
	printf("Enter the real part: ");
	fflush(stdin);   fflush(stdout);
	scanf("%f",&num1.real);
	printf("Enter the imaginary part: ");
	fflush(stdin);   fflush(stdout);
	scanf("%f",&num1.img);

	printf("Enter the 2nd complex number:\n");
	printf("Enter the real part: ");
	fflush(stdin);   fflush(stdout);
	scanf("%f",&num2.real);
	printf("Enter the imaginary part: ");
	fflush(stdin);   fflush(stdout);
	scanf("%f",&num2.img);

	add_complex(num1,num2);
}
