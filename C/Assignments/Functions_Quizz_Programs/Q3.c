#include <stdio.h>
#include <string.h>

void reverse(int rev[])
{
	int i,t;
	for(i=0;i<=5-i;i++)
	{
		t=rev[i];
		rev[i]=rev[5-i];
		rev[5-i]=t;
	}
}

int main ()
{
	int arr[6],i;
	printf("Enter the array:");
	fflush(stdin); fflush(stdout);
	for(i=0;i<6;i++)
	{
		scanf("%d",&arr[i]);
	}

	reverse(arr);
	printf("The array after reversing: ");
	for(i=0;i<6;i++)
	{
		printf("%d",arr[i]);
	}

}


