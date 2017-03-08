//
// Created by apple on 2017/3/8.
//
#include <stdio.h>
#include <stdlib.h>

int main二维数组栈堆(int argc, char* argv[])
{
    {
        //栈上开辟二维数组
        int a[3][4] = {0};
        int (*p2)[4] = (int [3][4]){0}; //明确了有3行
        int (*p3)[4] = (int [][4]){0}; //默认只有一行
        //堆上开辟二维数组
        int (*px)[4] = (int (*)[4])calloc(12, sizeof(int));
        free(px);   //释放内存

        int **pp = (int **)calloc(3, sizeof(int*));
        for(int i = 0; i < 3; i++)
        {
            pp[i] = (int *)calloc(4, sizeof(int));
        }
        //释放分块的内存
        for(int i = 0; i < 3; i++)
        {
            free(pp[i]);
        }
        free(pp);

    }
    {
        //栈上开辟三维数组
        int a[3][4][5] = {0};
        int (*p1)[4][5] = (int [3][4][5]){0};
        int (*p2)[4][5] = (int [][4][5]){0};
        //堆上开辟三维数组
        int (*px)[4][5] = (int (*)[4][5])calloc(60, sizeof(int));
    }
    {

    }

    return 0;
}
