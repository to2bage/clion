//
// Created by apple on 2017/2/20.
//
#include <stdio.h>
#include <stdarg.h>

int add(int argsNumber,...) //argsNumber表示参数的数量
{
    int rect = 0;
    //one:
    va_list argp; //分配内存空间，容纳不确定个数的参数， argp指向这片内存的首地址
    va_start(argp, argsNumber); //把argsNumber之后的参数读取到 新开辟的内存空间中；
    for(int i = 0; i < argsNumber; i++)
    {
        rect += va_arg(argp, int);//va_arg读取内存空间中的数据，并按照int类型解析， argp后移一个int数据类型的长度
    }
    va_end(argp); //释放argp指向的内存空间
    return rect;
}

void showString(int argsNumber,...)
{
    va_list  argp;
    va_start(argp, argsNumber);
    for(int i = 0; i < argsNumber; i++)
    {
//        char str[50] = {0};
//        sprintf(str, "%s", va_arg(argp, char*));
//        printf("%s ", str);
        printf("%s ", va_arg(argp, char*));
    }
    va_end(argp);
    return;
}

void showInt(int start, ...)
{
    //约定-1为参数的结束标志
    va_list argp;
    va_start(argp, start);
    if(start == -1)
    {
        va_end(argp);
        return;
    }
    printf("%d ", start);
    int num = va_arg(argp, int);

    while(num != -1)
    {
        printf("%d ", num);
        num = va_arg(argp, int);
    }
    printf("\n");

    va_end(argp);
    return;
}

int main(int argc, char* argv[])
{
    {
        printf("%d\n", add(3, 1, 2, 3));
        printf("%d\n", add(4, 1, 2, 3, 4));
    }
    {
        showString(3, "notepad", "calc", "tasklist");
        printf("\n");
    }
    {
        showInt(12, 34,56, 78, -1); //约定-1表示参数的结束
        showInt(34, 78, 12, -1);
        showInt(-1, 34, 890, -1);
    }

    return 0;
}

