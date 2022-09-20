#include <stdio.h>
#include <string.h>

int main ()
{
	char A[100],B[100],temp[100];
	int i ,maxlen;

	printf("Enter array A: ");
	fflush(stdin); fflush(stdout);
	gets(A);

	printf("Enter array B: ");
	fflush(stdin); fflush(stdout);
	gets(B);

	if (strlen(A)>=strlen(B))
		maxlen=strlen(A);
	else
		maxlen=strlen(B);


	for(i=0;i<=maxlen;i++)
	{
		temp[i]=A[i];
		A[i]=B[i];
		B[i]=temp[i];
	}

	printf("After swapping A:%s , B:%s",A,B);

}


