#include "stdio.h"
#include "string.h"

int main()

{
	char string [100];
   printf("Enter your string:");
   fflush(stdin);	fflush(stdout);
   gets(string);
   printf("%s",strcmp(string,"USERNAME")?"your string is not the same as \"USERNAME\"":"your string is the same as \"USERNAME\"");

}
