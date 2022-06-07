#pragma once
#ifndef  __LINKLIST_H__
#define  __LINKLIST_H__

#include"DataStruct.h"


void student_add(student** head);
void print(student* head, bool ctrl);
void SwapStudentDate(student* a, student* b);
void StudentNameSort(student* a);
void LoadingDate(student* head);
void freelist(student** head);
void StudentSorceSort(student* a);
void CountStudentData(student* a);

#endif // ! __LINKLIST_H__
