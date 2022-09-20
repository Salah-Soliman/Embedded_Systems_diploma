#include <stdio.h>
#include <string.h>

void decimalization(char n[] ,int m[],int len)
{
	int i ;
	for(i=0;i<=len;i++)
	{
		m[i]=n[i]-'0';
	}
}

int main ()
{
	char arr[100];
	int i ,sum=0,dec=1,len,ar[100]={0};
	printf("Enter the number to convert:");
	fflush(stdin); 	fflush(stdout);
	gets(arr);
	len=strlen(arr)-1;


	decimalization(arr,ar,len);

	for(i=len;i>=0;i--)
	{
		ar[i]*=dec;
		sum+=ar[i];
		dec*=10;
	}

	printf("Your number is:");
	fflush(stdin); fflush(stdout);
	printf("%d",sum);
}

