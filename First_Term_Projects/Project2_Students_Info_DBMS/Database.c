/*
 * Database.c
 *
 *  Created on: Dec 4, 2023
 *      Author: bebo
 */

#include "Database.h"
#include <string.h>

unsigned int Students_Document_Count = 0 , EnrrolledNumber,index ;
static unsigned int Ccount = 5 ;

//FIFO APIs
DB_Status_id Create_Student(Student* newStudent)
{
	if(Students_Document_Count == Document_max_Size )
	{
		return OP_failed ;
	}

	Students_Document [Students_Document_Count] = *newStudent;
	Students_Document_Count ++ ;
	return OP_Successfull ;
}

DB_Status_id Read_Student_BY_ID(unsigned int Roll_ID,Student* requiredStudent)
{
	if(Students_Document_Count == 0)
	{
		printf("\n============The Student Document is Empty ============\n\n");
		return OP_failed ;
	}
	else
	{
		for(index = 0; index <Students_Document_Count; index++)
		{
			if(Students_Document[index].roll == Roll_ID)
			{
				*requiredStudent = Students_Document[index];
				return OP_Successfull ;
			}
		}
	}
	printf("\n============ This Roll ID not exist ============\n\n");
	return OP_failed ;
}

DB_Status_id Read_Student_BY_fName(char fName[],Student requiredStudents[],int* count)
{
	if(Students_Document_Count == 0)
	{
		printf("\n============The Student Document is Empty ============\n\n");
		return OP_failed ;
	}
	else
	{
		int i = 0 ;
		for(index = 0; index <Students_Document_Count; index++)
		{
			if(!(stricmp(Students_Document[index].fname,fName)))
			{
				requiredStudents[i] = Students_Document[index];
				i ++ ;
			}
		}
		*count = i;
		if(i==0)
		{
			printf("first name %s not exist\n\n",fName);
			return OP_failed ;
		}
		return OP_Successfull ;
	}
	printf("\n============ This Student first name does not exist ============\n\n");
	return OP_failed ;


}

DB_Status_id Read_Students_BY_CourseID(unsigned int CourseID,Student EnrolledList[],unsigned int* count)
{
	if(Students_Document_Count == 0)
	{
		printf("\n============The Student Document is Empty ============\n\n");
		return OP_failed ;
	}
	else
	{
		EnrrolledNumber = 0 ;
		int j;
		for(index = 0; index <Students_Document_Count; index++)
		{
			for(j=0; j< Ccount; j++)
			{
				if(Students_Document[index].Cid[j] == CourseID)
				{
					EnrolledList[EnrrolledNumber] = Students_Document[index];
					EnrrolledNumber ++ ;
					break ;
				}

			}
		}
		*count = EnrrolledNumber ;
		return OP_Successfull ;
	}
	printf("\n============ This Roll ID not exist ============\n\n");
	return OP_failed ;

}

DB_Status_id Find_Students_Total(unsigned int* TotalNumber)
{
	*TotalNumber = Students_Document_Count ;
	return OP_Successfull ;
}

DB_Status_id Delete_Student()
{
	int i ;
	for(i=index; i<=Students_Document_Count; i++)
	{
		Students_Document[i] = Students_Document[i+1];
	}

	Students_Document_Count--;
	printf("\n============The Student Successfully Deleted ============\n\n");
	return OP_Successfull ;
}

DB_Status_id Find_Next_Student(Student* requiredStudent,int NXT_index)
{
	if(NXT_index < Students_Document_Count)
	{
		*requiredStudent = Students_Document[NXT_index];
		index ++;
		return OP_Successfull ;
	}
	return OP_failed ;
}

DB_Status_id Update_Student(Student* changed,int field,Updated_Data* newData)
{
	int i ;
	switch(field)
	{
	case 1 :
		strcpy(changed->fname, newData->name);
		break ;
	case 2 :
		strcpy(changed->lname, newData->name);
		break ;
	case 3 :
		changed->roll = newData->rollID ;
			break ;
	case 4 :
		changed->GPA = newData->GPA ;
			break ;
	case 5 :
		for(i=0; i<5; i++)
		{
			changed->Cid[i] = newData->Cid[i] ;
		}
			break ;
	default:
		return OP_failed ;
	}
	Students_Document[index]=*changed;
	printf("\n=============Student Successfully Updated=============\n\n");
	return OP_Successfull ;
}

DB_Status_id Store_File_Students(Student fileStudents[],int count)
{
	int i ;
	for(i=0; i<count; i++)
	{
		if(checkUnique(&fileStudents[i].roll))
		{
			if(Create_Student(&fileStudents[i]))
			{
				printf("The Roll Number %d Added Successfully\n",fileStudents[i].roll) ;
			}
		}
		else
		{
			printf("The Roll Number %d already taken\n",fileStudents[i].roll);
		}
	}
	return OP_Successfull ;
}


DB_Status_id Print_Student(Student*requiredStudent)
{
	int i ;
	printf("The First name: %s\n",requiredStudent->fname);
	printf("The Last name: %s\n",requiredStudent->lname);
	printf("The Roll Number: %d\n",requiredStudent->roll);
	printf("The GPA: %0.2f\n",requiredStudent->GPA);

	for(i = 0; i<Ccount; i++)
	{
		printf("The Course %d ID is %d\n",i+1,requiredStudent->Cid[i]);
	}
	printf("\n");
	return OP_Successfull ;

}

DB_Status_id Print_Enrroled_Students(Student Enrrolledlist[])
{
	int index ;
	for(index=0;index<EnrrolledNumber ;index++)
	{
		printf("The First name: %s\n",Enrrolledlist[index].fname);
		printf("The Last name: %s\n",Enrrolledlist[index].lname);
		printf("The Roll Number: %d\n",Enrrolledlist[index].roll);
		printf("The GPA: %0.2f\n\n",Enrrolledlist[index].GPA);
	}
	printf("\n");
	return OP_Successfull ;
}

DB_Status_id checkUnique(int* NewRollID)
{
	int i ;
	for(i=0; i < Students_Document_Count; i++)
	{
		if(*NewRollID == Students_Document[i].roll)
		{
			return OP_failed ;
		}
	}
	return OP_Successfull ;
}










