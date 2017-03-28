//
// Created by apple on 2017/3/23.
//
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

//结构体至少需要一个成员变量
struct MyStruct
{
    int num;
    double db;
    char str[20];
}*p, x[10], z;

int main结构体数组和指针(int argc, char *argv[])
{
    {
        //结构体数组的定义
        struct MyStruct my[10] = {0};
        struct MyStruct *p = (struct MyStruct[10]){0};

        //结构体数组初始化
        struct MyStruct myx[2] = {
                {10, 23.45, "hello"},
                {45, 67.123, "world"}
        };
        struct MyStruct *px = (struct MyStruct[2])  //纬度2可以省略
                {
                        {10, 23.45, "hello"},
                        {45, 67.123, "world"}
                };

        //结构体数组初始化，去除数组元素的{}也是正确的。不推荐这样写
        struct MyStruct my1[2] = {
                10, 23.45, "hello", 45, 67.123, "world"
        };
        struct MyStruct *px1 = (struct MyStruct[2])  //纬度2可以省略
                {
                        10, 23.45, "hello", 45, 67.123, "world"
                };
        //
    }

    {
        //结构体动态数组
        int num = 10;
        struct MyStruct *p1 = (struct MyStruct *)malloc(num * sizeof(struct MyStruct));//堆
        struct MyStruct *p2 = (struct MyStruct *)calloc(num, sizeof(struct MyStruct));//栈

        memset(p1, 0, num * sizeof(struct MyStruct));
        memset(p2, 0, num * sizeof(struct MyStruct));

        free(p1); //p2不需要free，因为是在栈上分配的内存
    }

    return 0;
}
