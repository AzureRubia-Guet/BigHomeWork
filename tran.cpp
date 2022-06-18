#include<stdio.h>
#include<easyx.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
#include<Windows.h>
#include<graphics.h>
#include<mmsystem.h>
#include<wchar.h>

wchar_t* TranNumToStr(int number = 0)
{
    wchar_t* ret = (wchar_t*)malloc(sizeof(wchar_t) * 3);
    if(ret)
        wmemset(ret, 0, sizeof(wchar_t) * 3);

    ret[0] = L'0' + number / 10;
    ret[1] = L'0' + number % 10;
    ret[2] = '\0\0';
    return ret;
}

wchar_t* tran(char *sBuf = 0)
{

    int sBufSize = strlen(sBuf);

    wchar_t* dBuf = 0;

    DWORD dBufSize = MultiByteToWideChar(CP_UTF8, 0, sBuf, sBufSize, NULL, 0);

    dBuf = (wchar_t*)malloc(dBufSize * sizeof(wchar_t));

    if(dBuf)
        wmemset(dBuf, 0, dBufSize);

    int nRet = MultiByteToWideChar(CP_UTF8, 0, sBuf, sBufSize, dBuf, dBufSize);

    dBuf[2] = '\0\0';

    for (unsigned int i = 2; i < wcslen(dBuf); i += 1)
    {
           dBuf[i] = '\0\0';
    }
   
    return dBuf;
}