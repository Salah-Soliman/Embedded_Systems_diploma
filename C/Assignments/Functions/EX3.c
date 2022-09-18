/*
 * EX3.c
 * Created on: Sep 18, 2022
 * Author: salah soliman
 */
#include "stdio.h"
#include "string.h"

int indx=0;
void reverse_sentence(char a[])
{
	if(strlen(a)!=1)
	{
		reverse_sentence(&a[indx+1]);
	}

	printf("%c",a[0]);
}

int main()
{
	char arr[100] ;
	printf("Enter a sentence:");
	fflush(stdin);    fflush(stdout);
	gets(arr);

	printf("The reverse of the sentence : ");
	reverse_sentence(arr);

}
