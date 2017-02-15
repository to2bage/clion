//
// Created by apple on 2017/2/15.
//
#include <stdio.h>

int main输入输出(int argc, char* argv[])
{
    {
        puts("Content-type:text/html\n\n");
        puts("puts是输出字符串，而且可以自动换行");
        putchar('a');
    }

    {
        char str[100] = {0};
        gets(str);  //直接初始化一个字符串
        puts(str);
        getchar();
    }
    return 0;
}

