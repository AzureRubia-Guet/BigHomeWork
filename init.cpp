#include<stdio.h>
#include<easyx.h>
#include<stdlib.h>
#include<mmsystem.h>
#include<WinUser.h>

#pragma comment(lib,"Winmm.lib")

void InitOfSystem(void)
{
	system("chcp 65001");
	system("cls");
}

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

	outtextxy(20, 40, _T("ѧ��"));

	outtextxy(80, 40, _T("����"));

	outtextxy(140, 40, _T("�ɼ�"));

	outtextxy(100, 500, _T("�ɼ�����"));

	outtextxy(340, 500, _T("������Ϣ"));

	outtextxy(200, 500, _T("�ֵ�����"));

	outtextxy(440, 500, _T("����ԭʼ��Ϣ"));

	outtextxy(100, 540, _T("��ȫ�˳�"));

	outtextxy(340, 540, _T("ѧ�Ų�ѯ"));

	outtextxy(200, 540, _T("ͳ����Ϣ"));

	outtextxy(440, 540, _T("��һҳ"));

	outtextxy(220, 0, _T("Maker:2100201117�����"));
	outtextxy(200, 20, _T("��ӭʹ��ѧ���ɼ�ͳ�Ʋ�ѯϵͳ"));

	mciSendString(_T("open resource\\student_sources_system.mp3 alias bkmusic"), NULL, 0, NULL);
	mciSendString(_T("play resource\\student_sources_system.mp3 "), NULL, 0, NULL);
}

void flush()
{
	fillrectangle(0, 60, 630, 500);
}

void EndOfInit()
{
	mciSendString(_T("close resource\\student_sources_system.mp3 "), NULL, 0, NULL);
	closegraph();
}