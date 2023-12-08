/*
 * Management.c
 *
 *  Created on: Dec 4, 2023
 *      Author: bebo
 */

#include "Database.h"
#include "Management.h"
#include "string.h"
#include <stdlib.h>

int i = 0 ;
static int Ccount = 5;


void add_student_manually()
{
	Student newStudent ;
	int i ;

	printf("Enter The Student Roll ID: ");
	fflush(stdin);    fflush(stdout);
	scanf("%d",&newStudent.roll);

	if(!checkUnique(&newStudent.roll))
	{
		printf("\n============Can Not Be Added The Student roll id Must be Unique============\n\n");
		return ;
	}

	printf("Enter Student First Name: ");
	fflush(stdin);    fflush(stdout);
	gets(newStudent.fname);

	printf("Enter Student Last Name: ");
	fflush(stdin);    fflush(stdout);
	gets(newStudent.lname);

	printf("Enter The Student GPA: ");
	fflush(stdin);    fflush(stdout);
	scanf("%f",&newStudent.GPA);

	printf("Enter The ID of each course \n");
	for(i = 0; i<Ccount; i++)
	{
		printf("Course %d ID: ",i+1);
		fflush(stdin);    fflush(stdout);
		scanf("%d",&newStudent.Cid[i]);
	}

	//store the new member
	if(Create_Student(&newStudent))
	{
		printf("\n============Successfully Added============\n\n");
	}
	else
	{
		printf("\n============Can Not Be Added The Student Document is Full============\n\n");
	}
}

void add_student_file()
{
	FILE* filePtr =fopen("StudentsData.txt","r");
	if (filePtr == NULL)
	{
		printf("cannot open the file \n");
		return ;
	}

	Student fileStudents[50];
	int count = 0 ;
	char line[100] ;
	while(fgets(line,sizeof(line),filePtr)!=NULL)
	{
		Student newStudent ;

		char* token = strtok(line," ");
		if(token != NULL)
		{
			newStudent.roll = atoi(token);
		}

		token = strtok(NULL," ");
		if(token != NULL)
		{
			strcpy(newStudent.fname , token);
		}

		token = strtok(NULL," ");
		if(token != NULL)
		{
			strcpy(newStudent.lname , token);
		}

		token = strtok(NULL," ");
		if(token != NULL)
		{
			newStudent.GPA = atof(token) ;
		}

		int i ;
		for(i=0; i<5; i++)
		{
			token = strtok(NULL," ");
			if(token != NULL)
			{
				newStudent.Cid[i] = atoi(token);
			}
		}
		fileStudents[count] = newStudent ;
		count++ ;
	}
	//function to store the fileStudens
	if(Store_File_Students(fileStudents,count))
	{
		printf("\n");
	}

}


void find_rl()
{
	int temp_RollID,state ;
	printf("Enter Student Roll ID To find: ");
	fflush(stdin);    fflush(stdout);
	scanf("%d",&temp_RollID);
	Student requiredStudent ;
	//read the required student
	state = Read_Student_BY_ID(temp_RollID,&requiredStudent);
	//print the required student
	if(state == OP_Successfull)
	{
		Print_Student(&requiredStudent);
	}
}

void find_fn()
{
	char fName[10];
	int state,count,i ;
	printf("Enter Student First Name To find: ");
	fflush(stdin);    fflush(stdout);
	gets(fName);
	Student requiredStudents[50] ;
	//read the required student
	state = Read_Student_BY_fName(fName,requiredStudents,&count);
	//print the required student
	if(state == OP_Successfull)
	{
		printf("there is %d Student with First Name %s\n",count,fName);
		for(i=0;i<count;i++)
		{
			Print_Student(&requiredStudents[i]);
		}
	}
}

void find_c()
{
	unsigned int courseID ,state,count;
	Student List[50];
	printf("Enter the Course ID to Find The Enrolled Students: ");
	fflush(stdin);  fflush(stdout);
	scanf("%d",&courseID);
	state = Read_Students_BY_CourseID(courseID,List,&count);
	if(state == OP_Successfull)
	{
		Print_Enrroled_Students(List);
	}
	printf("Total number of students enrolled on Course ID=%d is %d Student/s\n\n",courseID,count);
}

void tot_s()
{
	//extern Students_Document_Count ;
	unsigned int total,state ;
	state = Find_Students_Total(& total);
	if(state)
	{
		printf("Total number of students is %d\n",total);
		printf("You can add up to %d\n",Document_max_Size);
		printf("you can add %d more students\n\n",Document_max_Size-total);
	}

}

void del_s()
{
	int temp_RollID,state ;
	printf("Enter Student Roll ID To be deleted: ");
	fflush(stdin);    fflush(stdout);
	scanf("%d",&temp_RollID);
	Student requiredStudent ;
	//read the required student
	state = Read_Student_BY_ID(temp_RollID,&requiredStudent);
	//print the required student
	if(state == OP_Successfull)
	{
		//delete function
		Delete_Student();
	}
}

void show_s()
{
	int state ,NXT_index =0 ;
	Student requiredStudent ;
	state = Find_Next_Student(&requiredStudent,NXT_index) ;
	while(state)
	{
		Print_Student(&requiredStudent);
		printf("----------------------------\n");
		NXT_index ++ ;
		state = Find_Next_Student(&requiredStudent,NXT_index) ;
	}
}

void up_s()
{
	int temp_RollID,state,field ;
	printf("Enter Student Roll ID To Update: ");
	fflush(stdin);    fflush(stdout);
	scanf("%d",&temp_RollID);
	Student requiredStudent ;
	//read the required student
	state = Read_Student_BY_ID(temp_RollID,&requiredStudent);

	if(state)
	{
		Updated_Data newData ;
		printf("Enter Field number you want to update:\n");
		printf("1. First Name\n");
		printf("2. Last Name\n");
		printf("3. Roll Number\n");
		printf("4. GBA\n");
		printf("5. Courses\n");
		printf("enter Your choice: ");
		fflush(stdin);    fflush(stdout);
		scanf("%d",&field);
		switch(field)
		{
		case 1 :
			printf("Enter Student New First Name: ");
			fflush(stdin);    fflush(stdout);
			gets(newData.name);
			break ;
		case 2 :
			printf("Enter Student New Last Name: ");
			fflush(stdin);    fflush(stdout);
			gets(newData.name);
			break;
		case 3 :
			printf("Enter The Student New Roll ID: ");
			fflush(stdin);    fflush(stdout);
			scanf("%d",&newData.rollID);
			if(!checkUnique(&newData.rollID))
			{
				printf("\n============The New Roll Id Already exist The Roll No. Must be Unique============\n\n");
				return ;
			}
			break ;
		case 4 :
			printf("Enter The Student New GPA: ");
			fflush(stdin);    fflush(stdout);
			scanf("%f",&newData.GPA);
			break ;
		case 5 :
			printf("Enter The New ID of each course \n");
			for(i = 0; i<Ccount; i++)
			{
				printf("Course %d New ID: ",i+1);
				fflush(stdin);    fflush(stdout);
				scanf("%d",&newData.Cid[i]);
			}
			break ;
		default :
			printf("enter proper field to be altered\n\n");
		}
		Update_Student(&requiredStudent,field,&newData);
	}
}





