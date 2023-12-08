/*
 * Database.h
 *
 *  Created on: Dec 4, 2023
 *      Author: bebo
 */

#ifndef DATABASE_H_
#define DATABASE_H_

#include "stdio.h"

//Student Structure
typedef struct{
	char fname[50];
	char lname[50];
	int roll;
	float GPA;
	int Cid[10];
}Student;

typedef union {
	char name[50];
	int rollID ;
	float GPA;
	int Cid[5];
}Updated_Data;
//Creating Database Cluster
#define Document_max_Size 50
Student Students_Document[Document_max_Size] ;

typedef enum {
	OP_failed,
	OP_Successfull

}DB_Status_id;

//CRUD OPerations APIs

DB_Status_id Create_Student(Student*);
DB_Status_id Read_Student_BY_ID(unsigned int,Student*);
DB_Status_id Read_Student_BY_fName(char[],Student[],int*);
DB_Status_id Read_Students_BY_CourseID(unsigned int,Student[],unsigned int*);
DB_Status_id Update_Student(Student*,int,Updated_Data*);
DB_Status_id Delete_Student(void);
DB_Status_id Find_Next_Student(Student*,int);
DB_Status_id Print_Student(Student*);
DB_Status_id Print_Enrroled_Students(Student[]);
DB_Status_id Find_Students_Total(unsigned int*);
DB_Status_id checkUnique(int*);
DB_Status_id Store_File_Students(Student[],int);





#endif /* DATABASE_H_ */
