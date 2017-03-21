//
// Created by apple on 2017/3/21.
//
#include <stdio.h>

struct MyStruct
{
    int num;
    char str[100];
}m0 = {.str = "hello"};



int main结构体(int argc, char* argv[])
{
    {
        //C99结构体初始化
        struct MyStruct m1 = {.num = 1234};
        struct MyStruct m2 = {.str = "world", .num = 23};

        printf("m0.num = %d, m0.str = %s\n", m0.num, m0.str);
        printf("m1.num = %d, m1.str = %s\n", m1.num, m1.str);
        printf("m2.num = %d, m2.str = %s\n", m2.num, m2.str);
    }

    return 0;
}
