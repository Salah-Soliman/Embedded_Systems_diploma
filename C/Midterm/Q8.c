#include "stdio.h"
#include "string.h"

void reverse(char arr[])
{
	int i,temp;
	for(i=0;i<=(strlen(arr)-1)/2;i++)
	{
		temp=arr[i];
		arr[i]=arr[strlen(arr)-1-i];
		arr[strlen(arr)-1-i]=temp;
	}
	printf("Reverse string is : %s",arr);

}
int main()
{
	char arr[100];
	printf("Enter the string: ");
	fflush(stdin);     fflush(stdout);
	gets(arr);


	reverse(arr);

}
