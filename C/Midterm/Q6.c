#include <stdio.h>

int	find_unique(int arr[],int len)
{
	int i,c=0 ;

	for(i=0;i<len;i++)
	{
		c^=arr[i];
	}

	return c;
}

int main ()
{
	int arr[50],num,i;
	printf("Enter the number of elements : ");
	fflush(stdin);    fflush(stdout);
	scanf("%d",&num);

	printf("Enter the elements of the array : ");
	fflush(stdin);    fflush(stdout);
	for(i=0;i<num;i++)
	{
		scanf("%d",&arr[i]);
	}

//	find_unique(arr,num);
	printf("the Unique number in the array is: %d",find_unique(arr,num));

}

