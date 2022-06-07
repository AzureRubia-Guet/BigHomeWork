#include<stdio.h>
#include<easyx.h>
#include<stdlib.h>
#include<mmsystem.h>
#include<WinUser.h>

#pragma comment(lib,"Winmm.lib")

/*
 *对系统的编码格式进行改变，从ASCII变成utf-8
 *
 */
void InitOfSystem(void)
{
	system("chcp 65001");
	system("cls");
}


/*
 *初始化出一块画布，并加载背景画面和背景提示音以及各个按键提示
 *
 */
void InitOfWindow(void)
{
	initgraph(630, 660);
	IMAGE img;

	loadimage(&img, _T("resource\\background.png"));
	putimage(0, 0, &img);
	settextcolor(BLACK);
	settextstyle(0, 0, _T("Consolas"));
	setbkmode(TRANSPARENT);
	fillrectangle(0,60,630,500);

	outtextxy(20, 40, _T("学号"));

	outtextxy(80, 40, _T("姓名"));

	outtextxy(140, 40, _T("成绩"));

	outtextxy(100, 500, _T("成绩排序"));

	outtextxy(340, 500, _T("加载信息"));

	outtextxy(200, 500, _T("字典排序"));

	outtextxy(440, 500, _T("加载原始信息"));

	outtextxy(100, 540, _T("安全退出"));

	outtextxy(340, 540, _T("学号查询"));

	outtextxy(200, 540, _T("统计信息"));

	outtextxy(440, 540, _T("下一页"));

	outtextxy(220, 0, _T("Maker:2100201117梁若瑜"));
	outtextxy(200, 20, _T("欢迎使用学生成绩统计查询系统"));

	mciSendString(_T("open resource\\student_sources_system.mp3 alias bkmusic"), NULL, 0, NULL);
	mciSendString(_T("play resource\\student_sources_system.mp3 "), NULL, 0, NULL);
}


/*
 *清空显示区
 *
 */
void flush()
{
	fillrectangle(0, 60, 630, 500);
}

void EndOfInit()
{
	mciSendString(_T("close resource\\student_sources_system.mp3 "), NULL, 0, NULL);
	closegraph();
}