/*
 * main.c
 *
 *  Created on: Nov 13, 2023
 *      Author: Salah Soliman
 */

#include "linked_list.h"

 main ()
{
	char inputs[40];

	while(1){
		printf("\n====================");
		printf("\nChoose One Option off the following :- \n");
		printf("1:- Add Student \n");
		printf("2:- Delete A Student  \n");
		printf("3:- View All Students \n");
		printf("4:- Delete All Students \n");
		printf("5:- View Node \n");
		printf("6:- The length of The List  \n");
		printf("7:- View Node from End  \n");
		printf("8:- View Node The Middle Node  \n");
		printf("9:- Reverse The List Order  \n");
		printf("\nEnter Your Option Number : ");
		fflush(stdin);    fflush(stdout);
		gets(inputs);
		fflush(stdin);    fflush(stdout);
		printf("==================== \n \n");
		fflush(stdin);    fflush(stdout);

		switch(atoi(inputs))
		{
		case 1 :
			AddStudent();
			break ;
		case 2 :
			DeleteStudent();
			break ;
		case 3 :
			ViewAllStudents();
			break ;
		case 4 :
			DeleteAllStudent();
			break ;
		case 5 :
			ViewNode();
			break;
		case 6 :
			ListLegnth();
			break ;
		case 7 :
			ViewNodeBackward();
			break ;
		case 8 :
			MiddleNode();
			break ;
		case 9 :
			ListReverse();
			break ;
		default :
			printf("Unknown Option , Please choose correct one ");
		}

	}
}
