# BingHomeWork
基于easyx的大作业，使用单向链表的数据结构，使用的IDE为vs2019

代码中使用了windows系统的api，请在Windows系统下运行

resource文件夹需要和main放在同一个工程

该项目存在着相当多的bug: 

    1.所有的数据只能是两位（姓名，学号，成绩），因为在把字符串映射成宽字符串的时候有点问题（ wchar_t* tran(char*) ; 位于tran.h ），有个想法，但是不想整了。 
    
    2.那个“下一页( void print(student*,bool); 位于linklist.h )”其实只能有两页，因为我用bool类型进行了控制，如果要多加一页需要改类型和一些逻辑。
