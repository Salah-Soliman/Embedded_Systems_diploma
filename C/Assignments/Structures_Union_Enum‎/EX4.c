#include <stdio.h>

int main ()
{
	struct Sstudent
	{
		int roll ;
		char name[10];
		float marks;
	};

	int i,numberOfStudent=2 ;
	struct Sstudent student[numberOfStudent];

	printf("Enter the information of the students:\n");

	for(i=0;i<numberOfStudent;i++)
	{
		printf("Enter roll number: ");
		fflush(stdin);   fflush(stdout);
		scanf("%d",&student[i].roll);

		printf("Enter name: ");
		fflush(stdin);   fflush(stdout);
		scanf("%s",student[i].name);

		printf("Enter marks: ");
		fflush(stdin);   fflush(stdout);
		scanf("%f",&student[i].marks);

	}

	printf("\nDisplaying information of the students:\n");

	for(i=0;i<numberOfStudent;i++)
	{
		printf("information for roll number: %d\n",student[i].roll);
		printf("name: %s\n",student[i].name);
		printf("marks: %0.2f\n",student[i].marks);
	}

}
