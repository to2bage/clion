//
// Created by apple on 2017/2/20.
//
#include <stdio.h>

int a;
int a; //全局变量的声明， 可以有多个
int a = 12345;//全局变量的定义, 如果全局变量没有定义，则默认为0
//全局变量可以跨文件调用哦

int main全局变量的声明和定义(int argc, char* argv[])
{
    {
        int b;  //局部变量没有声明和定义的区别
        //int b; //出错， 重复定义
    }
    {
        printf("a = %d\n", a);
        int a = 10;
        printf("a = %d\n", a);  //局部变量a屏蔽了全局变量a, a = 10
    }
    int a = 100;
    {
        int a = 13;
        printf("a = %d\n", a); //块语句中的局部变量a 又屏蔽了外部的局部变量 a = 13
    }
    return 0;
}

