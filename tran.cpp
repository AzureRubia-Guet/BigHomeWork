#include<stdio.h>
#include<easyx.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
#include<Windows.h>
#include<graphics.h>
#include<mmsystem.h>
#include<wchar.h>

char* TranNumToStr(int number)
{
    char* ret = (char*)malloc(sizeof(char) * 3);
    ret[0] = '0' + number % 10;
    number /= 10;
    ret[1] = '0' + number % 10;
    return ret;
}

wchar_t* tran(char *sBuf)
{

    int sBufSize = strlen(sBuf);

    wchar_t* dBuf = 0;

    DWORD dBufSize = MultiByteToWideChar(CP_UTF8, 0, sBuf, sBufSize, NULL, 0);

    dBuf = (wchar_t*)malloc(dBufSize * sizeof(wchar_t));

    wmemset(dBuf, 0, dBufSize);

    int nRet = MultiByteToWideChar(CP_UTF8, 0, sBuf, sBufSize, dBuf, dBufSize);

    for (int i = 2; i < wcslen(dBuf); i += 1)
    {
           dBuf[i] = '\0\0';
    }
   
    return dBuf;
}