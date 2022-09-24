#include <stdio.h>

int main ()
{
	struct Sdistance
	{
		int feet ;
		float inch;
	};
	struct Sdistance distance1,distance2,sum;

	printf("Enter information for 1st distance:\n");
	printf("Enter feet: ");
	fflush(stdin);   fflush(stdout);
	scanf("%d",&distance1.feet);
	printf("Enter inch: ");
	fflush(stdin);   fflush(stdout);
	scanf("%f",&distance1.inch);

	printf("Enter information for 2nd distance:\n");
	printf("Enter feet: ");
	fflush(stdin);   fflush(stdout);
	scanf("%d",&distance2.feet);
	printf("Enter inch: ");
	fflush(stdin);   fflush(stdout);
	scanf("%f",&distance2.inch);

	sum.feet=distance1.feet+distance2.feet;
	sum.inch=distance1.inch+distance2.inch;
	if(sum.inch>=12){
		sum.inch-=12;
		sum.feet++;
	}
	printf("Sum of distances=%d\'-%0.1f\"",sum.feet,sum.inch);
}
