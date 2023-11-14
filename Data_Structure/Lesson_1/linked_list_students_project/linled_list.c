/*
 * linled_list.c
 *
 *  Created on: Nov 13, 2023
 *      Author: Salah Soliman
 */

#include "linked_list.h"



struct SStudent* Head = NULL ;
char inputs[40];


void AddStudent ()
{
	struct SStudent* NewStudent ;

	NewStudent = (struct SStudent*) malloc (sizeof(struct SStudent));
	if(NewStudent)
	{
		//fill the new student
		printf("Enter The Student ID : ");
		fflush(stdin);    fflush(stdout);
		gets(inputs);
		NewStudent->StudentDATA.ID = atoi(inputs);

		printf("Enter The Student Name : ");
		fflush(stdin);    fflush(stdout);
		gets(NewStudent->StudentDATA.name);

		printf("Enter The Student height : ");
		fflush(stdin);    fflush(stdout);
		gets(inputs);
		NewStudent->StudentDATA.height = atof(inputs);

		if(Head == NULL) // check if list is empty
		{
			Head = NewStudent ;
			NewStudent->P_nextStudent = NULL ;
		}else
		{
			struct SStudent* current = Head ;
			while(current->P_nextStudent)
			{
				current = current->P_nextStudent ;
			}
			current->P_nextStudent = NewStudent ;
			NewStudent->P_nextStudent = NULL ;
		}
		printf("========== Successfully Added ========== \n");

	}else
	{
		printf("memory allocation failed") ;
	}

}


int DeleteStudent()
{
	printf("Enter Student Id To BE Deleted : ");
	fflush(stdin);    fflush(stdout);
	gets(inputs);
	int selectedID = atoi(inputs);

	if(Head)
	{
		struct SStudent* Current = Head ;
		struct SStudent* previous = NULL ;

		while(Current)
		{
			if(Current->StudentDATA.ID == selectedID)
			{
				if (previous)
				{
					previous->P_nextStudent = Current->P_nextStudent ;
				}else
				{
					Head = Current->P_nextStudent ;
				}
				free(Current);
				printf("========== Successfully deleted ========== \n");
				return 1 ;
			}else
			{
				previous = Current ;
				Current = Current->P_nextStudent ;
			}
		}
		printf("Selected ID Does Not Exist");
	}else
	{
		printf("List Is Already Empty :) \n");
		return 1 ;
	}
}


int ViewNode()
{
	printf("Enter Record Number To View : ");
	fflush(stdin);    fflush(stdout);
	gets(inputs);
	int RequiredRecord = atoi(inputs);

	if(Head)
	{
		struct SStudent* current = Head ;
		int RecordNumber = 1 ;
		while(current)
		{
			if(RecordNumber == RequiredRecord)
			{
				printf("========================= \n");
				fflush(stdin);    fflush(stdout);
				printf("record number %d \n", RecordNumber);
				fflush(stdin);    fflush(stdout);
				printf("Student Id = %d \n", current->StudentDATA.ID);
				fflush(stdin);    fflush(stdout);
				printf("Student Name : %s \n", current->StudentDATA.name);
				fflush(stdin);    fflush(stdout);
				printf("Student Id = %f \n", current->StudentDATA.height);
				fflush(stdin);    fflush(stdout);
				printf("========================= \n");
				return 1 ;
			}
			else
			{
				current = current->P_nextStudent ;
				RecordNumber ++ ;
			}
		}
		printf("The Required Record does Not Exist");

	}else
	{
		printf("The List Is Empty :) ");
	}


}


void ViewAllStudents()
{
	if(Head)
	{
		struct SStudent* current = Head ;
		int count = 1 ;
		while(current)
		{
			printf("========================= \n");
			fflush(stdin);    fflush(stdout);
			printf("record number %d \n", count);
			fflush(stdin);    fflush(stdout);
			printf("Student Id = %d \n", current->StudentDATA.ID);
			fflush(stdin);    fflush(stdout);
			printf("Student Name : %s \n", current->StudentDATA.name);
			fflush(stdin);    fflush(stdout);
			printf("Student Id = %f \n", current->StudentDATA.height);
			fflush(stdin);    fflush(stdout);
			printf("========================= \n");

			current = current->P_nextStudent ;
			count ++ ;
		}
	}else
	{
		printf("List Is Empty :) \n");
	}
}


void DeleteAllStudent()
{
	if(Head)
	{
		while(Head)
		{
			struct SStudent* current = Head ;
			Head = current->P_nextStudent ;
			free(current);
		}
		printf("==========Deletion complete ========== \n");
	}else
	{
		printf("List Is Already Empty :) ");

	}
}


void ListLegnth()
{
	if(Head)
	{
		struct SStudent* current = Head ;
		printf("list has %d Record(s)",findLength(current));
	}else
	{
		printf("The List Is Empty :) ");
	}
}

int findLength(struct SStudent* Inner_current)
{
	static int length ;
	if (Inner_current)
	{
		length = 1 + findLength(Inner_current->P_nextStudent);
		return length ;

	}else
	{
		return 0 ;
	}
}


int ViewNodeBackward()
{
	printf("Enter Record Number From End To View : ");
	fflush(stdin);    fflush(stdout);
	gets(inputs);
	int RequiredRecord = atoi(inputs),i,count=1 ;

	if(Head)
	{
		struct SStudent* Pmain = Head ;
		struct SStudent* referance = Head ;
		for(i = 0 ; i< RequiredRecord ; i++)
		{
			referance = referance->P_nextStudent ;
			if (referance == NULL && ((i+1) < RequiredRecord))
			{
				printf("The Required Record does Not Exist");
				return 0 ;
			}
			if(referance == NULL)
				break;
		}

		while(referance)
		{
			referance = referance->P_nextStudent;
			Pmain = Pmain->P_nextStudent;
			count ++ ;
		}
				printf("========================= \n");
				fflush(stdin);    fflush(stdout);
				printf("record number %d \n", count);
				fflush(stdin);    fflush(stdout);
				printf("Student Id = %d \n", Pmain->StudentDATA.ID);
				fflush(stdin);    fflush(stdout);
				printf("Student Name : %s \n", Pmain->StudentDATA.name);
				fflush(stdin);    fflush(stdout);
				printf("Student Id = %f \n", Pmain->StudentDATA.height);
				fflush(stdin);    fflush(stdout);
				printf("========================= \n");
				return 1 ;
	}else
	{
		printf("The List Is Empty :) ");
	}


}

void MiddleNode()
{
	if(Head)
	{
		struct SStudent* PFast = Head ;
		struct SStudent* PSlow = Head ;
		unsigned count = 1 ;

		while(PFast->P_nextStudent)
		{
			PFast = PFast->P_nextStudent->P_nextStudent ;
			PSlow = PSlow->P_nextStudent ;
			count ++ ;
			if(PFast == NULL)
				break;
		}

		printf("========================= \n");
		fflush(stdin);    fflush(stdout);
		printf("record number %d \n", count);
		fflush(stdin);    fflush(stdout);
		printf("Student Id = %d \n", PSlow->StudentDATA.ID);
		fflush(stdin);    fflush(stdout);
		printf("Student Name : %s \n", PSlow->StudentDATA.name);
		fflush(stdin);    fflush(stdout);
		printf("Student Id = %f \n", PSlow->StudentDATA.height);
		fflush(stdin);    fflush(stdout);
		printf("========================= \n");
	}else
	{
		printf("List Is Empty :) \n");
	}
}


void ListReverse()
{
	if(Head)
	{
		struct SStudent* next = Head ;
		struct SStudent* current = Head ;
		next=next->P_nextStudent ;
		Head->P_nextStudent = NULL ;
		while(next)
		{
			current = next ;
			next=next->P_nextStudent ;
			current->P_nextStudent = Head ;
			Head = current;
		}
		printf("==========List reversed successfully=========\n");


	}else
	{
		printf("List Is Empty");
	}
}



