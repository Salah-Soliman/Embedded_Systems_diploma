/*
 * EX5.c
 * Created on: Sep 28, 2022
 * Author: salah soliman
 */

#include "stdio.h"
#include "string.h"



struct Semployee
{
	char name[10];
	int id;
};

int main()
{
	struct Semployee emp1,emp2 ;
	struct Semployee* pstruct1= &emp1 ;
	struct Semployee* pstruct2= &emp2 ;


	strcpy(pstruct1->name,"Alex");a
	pstruct1->id=1002;

	strcpy(pstruct2->name,"Ali");
	pstruct2->id=1003;

	int arr[2];
	arr[0]=(int)pstruct1;
	arr[1]=(int)pstruct2;

	struct Semployee** parr=arr;

	printf("Employee Name : %s\nEmployee ID : %d",(*parr)->name,(*parr)->id);
	printf("\nEmployee Name : %s\nEmployee ID : %d",(*(parr+1))->name,(*(parr+1))->id);









}
