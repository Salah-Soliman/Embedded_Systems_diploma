/*
 * main.c
 *
 *  Created on: Dec 4, 2023
 *      Author: Salah Soliman
 *
 */

#include "Management.h"
#include "stdio.h"

int choice ;
int main(){
	printf("Welcome to the Student Management System\n");
	while(1){
		printf("Choose The Task that you want to perform\n");
		printf("1. Add the Student Details Manually\n");
		printf("2. Add the Student Details From Text File\n");
		printf("3. Find the Student Details by Roll Number\n");
		printf("4. Find the Student Details by First Name\n");
		printf("5. Find the Student Details by Course Id\n");
		printf("6. Find the Total number of Students\n");
		printf("7. Delete the Students Details by Roll Number\n");
		printf("8. Update the Students Details by Roll Number\n");
		printf("9. Show all information\n");
		printf("10. To Exit\n");
		printf("Enter your choice to perform the task:");
		fflush(stdin); fflush(stdout);
		scanf("%d",&choice);
		printf("=======================================\n\n");

		switch(choice){
		case 1 :
			add_student_manually();
			printf("----------------------------\n");
			tot_s();
			break;
		case 2 :
			add_student_file();
			printf("----------------------------\n");
			tot_s();
			break;
		case 3 :
			find_rl();
			break;
		case 4 :
			find_fn();
			break;
		case 5 :
			find_c();
			break;
		case 6 :
			tot_s();
			break;
		case 7 :
			del_s();
			break;
		case 8 :
			up_s();
			break;
		case 9 :
			show_s();
			tot_s();
			break;
		case 10 :
			printf("System Terminated...");
			break;
		default :
			printf("please choose proper option\n\n");
		}
		if(choice==10)
		{
			break;
		}
	}

}
