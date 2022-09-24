#include <stdio.h>

int main ()
{
	struct Sstudent
	{
		char name[10];
		int roll ;
		float marks;
	};

	struct Sstudent student1;

	printf("Enter the information of the student:\n");
	printf("Enter name: ");
	fflush(stdin);   fflush(stdout);
	scanf("%s",student1.name);

	printf("Enter roll number: ");
	fflush(stdin);   fflush(stdout);
	scanf("%d",&student1.roll);

	printf("Enter marks: ");
	fflush(stdin);   fflush(stdout);
	scanf("%f",&student1.marks);

	printf("\nDisplaying information:\n");
	printf("name: %s\n",student1.name);
	printf("roll: %d\n",student1.roll);
	printf("marks: %f\n",student1.marks);
}
