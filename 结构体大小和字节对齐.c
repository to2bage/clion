//
// Created by apple on 2017/3/23.
//
//  结构体默认对齐的规则
//  char int double float是基本数据类型
//  结构体内存大小  大于等于所有成员内存大小的总和
//  结构体每一个成员相对于结构体首地址的偏移量，必须是当前成员内存大小的整数倍, 不足的自动填充
//  结构体内存大小是最宽基本数据类型的整数倍
//  嵌套的结构体，最大的基本数据类型，不局限于当前的结构体，也可能是被嵌套的结构体
//
#include <stdio.h>

int main结构体默认对齐规则(int argc, char *argv[])
{
    {
        struct mystruct
        {
            int num;    //只有一个元素，就不存在对齐的规则了
        };
        printf("%d\n", sizeof(struct mystruct));    //4
    }

    {
        struct mystruct
        {
            int num;
            double num2;
        };
        printf("%d\n", sizeof(struct mystruct));    //16
    }

    {
        struct mystruct
        {
            int num;
            double num2;
            int num3;
        };
        printf("%d\n", sizeof(struct mystruct));    //24
    }

    {
        struct mystruct
        {
            char num;
            double num4;
            int num3;
            char num2;
        };
        printf("%d\n", sizeof(struct mystruct));    //24
    }

    {
        struct mystruct
        {
            char num1;
            double num2;
            int num3;
            char ch1;
            short ch2;
            char newch;
            long long num4;
        };
        printf("%d\n", sizeof(struct mystruct));    //40
    }

    return 0;
}
