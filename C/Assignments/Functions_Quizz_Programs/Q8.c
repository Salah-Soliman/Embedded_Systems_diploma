#include <stdio.h>
#include <math.h>

int last_occurrence_of_no(int ar[],int n )
{
	int i,indx ;
	for(i=0;i<=10;i++)
	{
		if(ar[i]==n)
		{
			indx=i;
		}
	}
	return indx;

}

int main ()
{
	int num,arr[10],i;
	printf("Enter the array to search in:");
	fflush(stdin); 	fflush(stdout);

	for(i=0;i<10;i++)
	{
		scanf("%d",&arr[i]);
	}



	printf("Enter a number to search for:");
	fflush(stdin); fflush(stdout);
	scanf("%d",&num);

	printf("last occurrence of the char %d is in index: %d",num,last_occurrence_of_no(arr,num));

}

