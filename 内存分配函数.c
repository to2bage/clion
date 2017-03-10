//
// Created by apple on 2017/3/8.
//
#include <stdio.h>
#include <stdlib.h>
#include <alloca.h>


int main内存分配函数(int argc, char* argv[])
{
    {
        //malloc
        int *p = (int *)malloc(100);    //100个字节的内存
        for(int i = 0; i < 25; i++)     //100个字节的内存 == 25个int类型的数据
        {
            printf("%4d", p[i]);
        }
        printf("\n");
    }
    {
        //calloc(元素的个数，单个元素的字节大小)
        int *p = (int *)calloc(25, sizeof(int));    //100个字节的内存，25个int类型的数据
        for(int i = 0; i < 25; i++)     //100个字节的内存 == 25个int类型的数据
        {
            printf("%4d", p[i]);
        }
        printf("\n");
    }
    {
        //realloc
        int *p = (int *)malloc(10 * sizeof(int));
        printf("p = %p\n", p);
        p = realloc(p, 20 * sizeof(int));   //拓展内存
        printf("p = %p\n", p);
    }
    {
        //_recalloc
        int *p = (int *)malloc(10 * sizeof(int));
        //p = _recalloc(p, 20, sizeof(int));  //linux 下好像不能用哦
    }
    {
        //栈上栈上栈上 分配内存函数 ： alloca, 要包含头文件 alloca.h
        int *p = alloca(10 * sizeof(int)); //因为实在栈上分配内存，所以不能超过栈的内存大小

    }

    return 0;
}
