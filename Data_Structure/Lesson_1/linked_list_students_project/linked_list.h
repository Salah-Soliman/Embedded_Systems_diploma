/*
 * linked_list.h
 *
 *  Created on: Nov 13, 2023
 *      Author: bebo
 */

#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_

#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "conio.h"

//effective data

struct Sdata
{
	int ID ;
	char name [40];
	float height ;
};


//linked list node
struct SStudent
{
	struct Sdata StudentDATA ;
	struct SStudent* P_nextStudent ;
};


//APIs

void AddStudent ();
int RemvoeStudent();
void ViewAllStudents();
void RemoveAllStudent();
int ViewNode();
void ListLegnth();
int findLength(struct SStudent* );

int ViewNodeBackward();

void MiddleNode();

void ListReverse();

#endif /* LINKED_LIST_H_ */
