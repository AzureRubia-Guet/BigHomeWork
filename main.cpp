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
#include"find.h"
#include<stdbool.h>

#define _CRT_SECURE_NO_WARNINGS 1

#pragma comment(lib,"Winmm.lib")/*音乐播放器的api*/
#pragma warning(disable:4996)/*vs的东西，在其它地方请注释掉*/

int main(void)
{
	InitOfSystem();
	InitOfWindow();

	bool ctrl = 0;

	MOUSEMSG m;

	student* a = 0;

	student_add(&a);

	while (1)
	{
		m = GetMouseMsg();/*获取鼠标消息*/

		if (m.uMsg == WM_LBUTTONDOWN)/*如果是左键按下*/
		{
			if (m.x >= 340 && m.x <= 400 && m.y >= 500 && m.y <= 540)
			{
				flush();
				print(a,ctrl);
			}
			if (m.x >= 100 && m.x <= 160 && m.y >= 500 && m.y <= 540)
			{
				flush();
				StudentSorceSort(a);
				print(a, ctrl);
			}
			if (m.x >= 200 && m.x <= 260 && m.y >= 500 && m.y <= 540)
			{
				flush();
				StudentNameSort(a);
				print(a, ctrl);
			}
			if (m.x >= 440 && m.x <= 520 && m.y >= 500 && m.y <= 540)
			{
				flush();
				LoadingDate(a);
				print(a, ctrl);
			}
			if (m.x >= 100 && m.x <= 160 && m.y >= 540 && m.y <= 580)
			{
				EndOfInit();
				break;
			}
			if (m.x >= 340 && m.x <= 400 && m.y >= 540 && m.y <= 580)
			{
				FindBaseOnXueHao(a);
			}
			if (m.x >= 200 && m.x <= 260 && m.y >= 540 && m.y <= 580)
			{
				CountStudentData(a);
			}
			if (m.x >= 440 && m.x <= 500 && m.y >= 540 && m.y <= 580)
			{
				flush();
				ctrl = !ctrl;
				print(a, ctrl);
			}
		}
	}
	return 0;
}