//
// Created by apple on 2017/2/15.
//
#include <stdio.h>

int mainprintscanf返回值(int argc, char* argv[])
{
    {
        //print返回值是打印字符的个数（包括回车符）
        int num = printf("12345\n");
        printf("num = %d\n", num);  //6

        num = printf("a=%d,b=%d\n", 10, 20);
        printf("num = %d\n", num);  //10
    }
    {
        //scanf的返回值是 成功输入的数据的个数
        int a, b, c;
        int num = scanf("%d%d%d", &a, &b, &c);
        printf("num = %d\n", num);  //
    }

    return 0;
}
