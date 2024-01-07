/*
 * EX8.c
 * Created on: Sep 13, 2022
 * Author: salah soliman
 */
#include "stdio.h"

int main()
{
	float x,y;
	char operator;
	printf("Enter operator either + or - or * or / :- ");
	fflush(stdin);   fflush(stdout);
	scanf("%c",&operator);

	printf("Enter two Operands :-");
	fflush(stdin);   fflush(stdout);
	scanf("%f %f",&x,&y);

	switch (operator)
	{
	case '+' :
	{
		printf("%f %c %f = %f",x,operator,y,x+y);
		break;
	}
	case '-' :
	{
		printf("%f %c %f = %f",x,operator,y,x-y);
		break;
	}

	case '*' :
	{
		printf("%f %c %f = %f",x,operator,y,x*y);
		break;
	}

	case '/' :
	{
		printf("%f %c %f = %f",x,operator,y,x/y);
		break;
	}

	}
}


