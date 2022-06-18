#include<stdio.h>
#include<easyx.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
#include<Windows.h>
#include<graphics.h>
#include<mmsystem.h>
#include"Init.h"
#include"tran.h"
#include"str.h"
#include<WinUser.h>
#include<wchar.h>
#include"linklist.h"

void student_add(student** head = 0)
{
	FILE* readname = 0;
	FILE* readscore = 0;
	FILE* readxuehao = 0;

	fopen_s(&readname, "resource\\StudentData.txt", "r");
	fopen_s(&readscore, "resource\\StudentSorce.txt", "r");
	fopen_s(&readxuehao, "resource\\StudentXueHao.txt", "r");

	int flag = 0;

	while (flag!=-1)
	{
		wchar_t* namew = 0;
		char name[9] = { 0 };

		student* ahead_p = (student*)malloc(1* sizeof(student));
		if (ahead_p == NULL)
		{
			printf("\nerror!\n");
			return;
		}
		student* last = *head;

		flag = FGetStr(name, 8, readname);
		namew = tran(name);
		ahead_p->wname = namew;
		memset(name, 0, sizeof(name));
		namew = 0;

		FGetStr(name, 4, readscore);
		namew = tran(name);
		ahead_p->sorce = namew;
		memset(name, 0, sizeof(name));
		namew = 0;

		FGetStr(name, 4, readxuehao);
		namew = tran(name);
		ahead_p->xuehao = namew;
		memset(name, 0, sizeof(name));
		namew = 0;


		ahead_p->next = NULL;

		if (last)
		{
			while (last->next)
			{
				last = last->next;
			}
			last->next = ahead_p;
		}
		else
		{
			*head = ahead_p;
		}
	}

	if (readname)
		fclose(readname);

	if (readscore)
		fclose(readscore);

	if (readxuehao)
		fclose(readxuehao);
}

void print(student *head = 0,bool ctrl = 0)
{
	student* rear_q = 0;

	int i = 0;

	int j = 0;
	
		for (rear_q = head; rear_q ; rear_q = rear_q->next,i += 1)
		{
			if (ctrl == 0 && i <= 8)
			{
				outtextxy(20, 80 + i * 50, rear_q->xuehao);
				outtextxy(80, 80 + i * 50, rear_q->wname);
				outtextxy(140, 80 + i * 50, rear_q->sorce);
			}

			if (ctrl == 1 && j <= 8 && i > 8 )
			{
				outtextxy(20, 80 + j * 50, rear_q->xuehao);
				outtextxy(80, 80 + j * 50, rear_q->wname);
				outtextxy(140, 80 + j * 50, rear_q->sorce);
				j += 1;
			}
		}

}

void freelist(student** head = 0)
{
	student* rear_a = *head;
	if(head)
	    for (; rear_a; rear_a = rear_a->next)
	    {
			free(rear_a->sorce);
			free(rear_a->wname);
			free(rear_a->xuehao);
		}
	return;
}

/*
 *交换数据域
 */
void SwapStudentDate(student* a = 0, student* b = 0)
{
	student temp ;

	temp.sorce = a->sorce;
	temp.wname = a->wname;
	temp.xuehao = a->xuehao;

	a->sorce = b->sorce;
	a->wname = b->wname;
	a->xuehao = b->xuehao;

	b->sorce = temp.sorce;
	b->wname = temp.wname;
	b->xuehao = temp.xuehao;
}

/*
 *字典序排序，但是有大问题
 */
void StudentNameSort(student* a = 0)
{
	student* apoint = a;
	student* bpoint = a->next;
	while (apoint->next!=0)
	{
	bpoint = apoint->next;
		while (bpoint != 0) 
		{
			if (wcscmp(apoint->wname, bpoint->wname) > 0)
			{
				SwapStudentDate(apoint, bpoint);
			}
			bpoint = bpoint->next;	
		}
	apoint = apoint->next;
	}
}

/*
 *成绩高低排序
 */
void StudentSorceSort(student* a = 0)
{
	student* apoint = a;
	student* bpoint = a->next;
	while (apoint->next != 0)
	{
		bpoint = apoint->next;
		while (bpoint != 0)
		{
			if (wcscmp(apoint->sorce, bpoint->sorce) < 0)
			{
				SwapStudentDate(apoint, bpoint);
			}
			bpoint = bpoint->next;
		}
		apoint = apoint->next;
	}
}

/*
 *加载原始数据
 */
void LoadingDate(student* head = 0)
{
	freelist(&head);/*把之前的的释放了*/
	FILE* readname = 0;
	FILE* readscore = 0;
	FILE* readxuehao = 0;

	fopen_s(&readname, "resource\\StudentData.txt", "r");
	fopen_s(&readscore, "resource\\StudentSorce.txt", "r");
	fopen_s(&readxuehao, "resource\\StudentXueHao.txt", "r");

	int flag = 0;

	student* ahead_p = head;

	while (flag != -1)
	{
		wchar_t* namew = 0;
		char name[9] = { 0 };

		flag = FGetStr(name, 8, readname);
		namew = tran(name);
		ahead_p->wname = namew;
		memset(name, 0, sizeof(name));
		namew = 0;

		flag = FGetStr(name, 4, readscore);
		namew = tran(name);
		ahead_p->sorce = namew;
		memset(name, 0, sizeof(name));
		namew = 0;

		flag = FGetStr(name, 4, readxuehao);
		namew = tran(name);
		ahead_p->xuehao = namew;
		memset(name, 0, sizeof(name));
		namew = 0;

		ahead_p = ahead_p->next;
	}

	if (readname)
		fclose(readname);
	if (readscore)
		fclose(readscore);
	if (readxuehao)
		fclose(readxuehao);
}

void CountStudentData(student* a = 0)
{
	if (!a) return;

	student* apoint = a;
	int CountOfGood = 0;
	int CountOfCommon = 0;
	int CountOfBad = 0;

	while (apoint)
	{
		if (wcscmp(apoint->sorce, L"90") >= 0 )
		{
			CountOfGood += 1;
		}
		if ( (wcscmp(apoint->sorce, L"90") < 0) && (wcscmp(a->sorce, L"60") >= 0 ) )
		{
			CountOfCommon += 1;
		}
		if (wcscmp(apoint->sorce, L"60") < 0)
		{
			CountOfBad += 1;
		}
		apoint = apoint->next;
	}
	flush();
	outtextxy(20, 80 , _T("优秀"));
	outtextxy(20, 130, _T("及格"));
	outtextxy(20, 180, _T("不及格"));

	outtextxy(80, 80, TranNumToStr(CountOfGood));
	outtextxy(80, 130, TranNumToStr(CountOfCommon));
	outtextxy(80, 180, TranNumToStr(CountOfBad));
}
