#include<stdio.h>

int FGetStr(char* str, int size, FILE* file)
{
    int i = 0;
    char c = 0;
    while (c = fgetc(file), c != '\n' && c != EOF && i < size - 1)
    {
        str[i] = c;
        i += 1;
    }
    if (c != '\n')
    {
        ungetc(c, stdin);
    }
    str[i] = '\0';

    return (c == EOF) ?  -1 : 0 ;
}