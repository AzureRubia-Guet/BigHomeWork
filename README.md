# BingHomeWork
基于easyx的大作业，使用单向链表的数据结构，使用的IDE为vs2019

代码中使用了windows系统的api，请在Windows系统下运行

resource文件夹需要和main放在同一个工程

该项目存在着相当多的bug

    1.在“加载原始数据（ void LoadingDate(student* head) ; 位于linklist.h ）”那一项，malloc了没释放。尝试挣扎过，没搞明白怎么办。（已解决）

    2.所有的数据只能是两位（姓名，学号，成绩），因为在把字符串映射成宽字符串的时候有点问题（ wchar_t* tran(char*) ; 位于tran.h ），有个想法，但是不想整了。

    3.那个“统计信息”有问题，在两个宽字符串相比的时候不知道为什么抽风了，全部统计到了同一个地方。

    4.那个“下一页( void print(student*,bool); 位于linklist.h )”其实只能有两页，因为我用bool类型进行了控制，如果要多加一页需要改类型和一些逻辑。
