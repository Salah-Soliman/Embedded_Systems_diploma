/*
 * EX2.c
 * Created on: Sep 13, 2022
 * Author: salah soliman
 */
#include "stdio.h"

int main()
{
	char x;
	printf("Enter an alphabet: ");
	fflush(stdin);   fflush(stdout);
	scanf("%c",&x);
	if(x=='a'||x=='e'||x=='i'||x=='o'||x=='u'||x=='A'||x=='E'||x=='I'||x=='O'||x=='U')
	{
		printf("%c is a vowel",x);
	}
	else
	{
		printf("%c is a consonant",x);
	}
}
