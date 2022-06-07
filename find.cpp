#include<stdio.h>
#include<easyx.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
#include<Windows.h>
#include<graphics.h>
#include<mmsystem.h>
#include<WinUser.h>
#include<wchar.h>
#include"Init.h"
#include"tran.h"
#include"str.h"
#include"linklist.h"


/*
 *生成一个消息窗口，获取输入
 */
wchar_t* InputXueHao(void)
{
	wchar_t* input = (wchar_t*)malloc(sizeof(wchar_t) * 3);
	wmemset(input, 0, sizeof(wchar_t));
	while (wcslen(input) != 2)
	{
		InputBox(input,3,_T("输入一个二位数"), _T("学号查找"), _T("01"),300,0,false);
	}
	return input;
}


/*
 *显示查询出来的结果
 */
void FindBaseOnXueHao(student* a = 0)
{
	wchar_t* xuehao = InputXueHao();

	student* rear_q = 0;

	for (rear_q = a; rear_q; rear_q = rear_q->next)
	{
		if (wcscmp(rear_q->xuehao, xuehao) == 0)
		{
			break;
		}
	}
	flush();
	outtextxy(20, 80 , rear_q->xuehao);
	outtextxy(80, 80 , rear_q->wname);
	outtextxy(140, 80 , rear_q->sorce);
}