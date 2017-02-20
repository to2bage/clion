//
// Created by apple on 2017/2/16.
//
#include <stdio.h>

int main测试dowhile(int argc, char* argv[])
{
    //总结： 对于while循环来说，是看i++(++i, i--, --i)这个表达式是从哪个数字开始的
    printf("while\n");
    {
        int i = 0;
        while(i++ < 5)  // 从0开始循环 0 < 5
        {
            printf("tobage\\"); //循环5次
        }
        printf("\n");
    }
    {
        int i = 0;
        while(++i < 5)  //从1开始循环 1 < 5
        {
            printf("tobage\\"); //循环4次
        }
        printf("\n");
    }
    {
        int i = 5;
        while(i-- > 0)  //从5开始循环 5 > 0
        {
            printf("tobage\\"); //循环5次
        }
        printf("\n");
    }
    {
        int i = 5;
        while(--i > 0)  //从4开始循环 4 > 0
        {
            printf("tobage\\"); //循环4次
        }
        printf("\n");
    }

    //总结dowhile:
    printf("dowhile\n");
    {
        int i = 0;
        do
        {
            printf("tobage\\"); //循环6次
        }
        while(i++ < 5); //从0开始循环 0 < 5, 又因为do...while先执行一次，所以是6次
        printf("\n");
    }
    {
        int i = 0;
        do
        {
            printf("tobage\\"); //循环5次
        }
        while(++i < 5); //从1开始循环 1 < 5, 又因为do...while先执行一次，所以是5次
        printf("\n");
    }
    {
        int i = 5;
        do
        {
            printf("tobage\\"); //循环6次
        }
        while(i-- > 0); //从5开始循环 5 > 0, 又因为do...while先执行一次，所以是6次
        printf("\n");
    }
    {
        int i = 5;
        do
        {
            printf("tobage\\"); //循环5次
        }
        while(--i > 0); //从5开始循环 4 > 0, 又因为do...while先执行一次，所以是5次
        printf("\n");
    }

    return 0;
}

