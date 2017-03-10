//
// Created by apple on 2017/3/8.
//
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

static int getMax(int a, int b)
{
    return a > b ? a : b;
}
static int getMin(int a, int b)
{
    return a < b ? a : b;
}

static int add(int a, int b)
{
    return a + b;
}
static int sub(int a, int b)
{
    return a - b;
}
static int mull(int a, int b)
{
    return a * b;
}
static int divv(int a, int b)
{
    return a / b;
}

int main函数指针数组(int argc, char* argv[])
{
    {
        //函数指针
        int (*fp)(int, int) = getMax;
        //函数指针数组
        int (*afp[6])(int, int) = {getMax, getMin, add, sub, mull, divv};//afp是常量
        printf("sizeof(afp) = %lu\n", sizeof(afp)); //48个字节=6 * 8个字节
        //函数指针数组的遍历
        for(int i = 0; i < 6; i++)
        {
            //printf("%5d", afp[i](100, 45));
            printf("%5d", (*(afp + i))(100, 45));   //注意优先级
        }
        printf("\n");
        //使用指针遍历函数指针数组
//        int (*px)(int, int);
//        for(px = afp[0]; px < afp[0] + 6; px++)  （函数指针 + 常数是没有意义的）
//        {
//            printf("%5d", px(100, 45));
//        }
//        printf("\n");
        //函数指针数组名 的类型是一个二级函数指针
        for(int (**pp)(int,int) = afp; pp < afp + 6; pp++)
        {
            printf("%5d", (*pp)(100, 45)); //注意优先级
        }
        printf("\n");

        /**
         *   int *a      int (*fp)(int, int)
         *
         *   int *a[10]  int (*fp[10])(int, int)
         *
         *   int **a     int (**fp)(int, int)
         * */
    }
    {
        //在栈上定义数组和函数指针数组
        //a 和 fp 都是常量
        int a[6] = {1,2,3,4,5,6};
        int (*fp[6])(int, int) = {getMax, getMin, add, sub, mull, divv};

        //在栈上定义数组和函数指针数组的另一种方式
        int *pa = (int[6]){1,2,3,4,5,6};
        int (**fpp)(int, int) = (int (*[6])(int, int)){getMax, getMin, add, sub, mull, divv};
        //二级函数指针 存贮 函数指针数组类型
        for(int i = 0; i < 6; i++)
        {
            printf("%5d", fpp[i](100, 45));
        }
        printf("\n");

        //在堆上建立函数指针数组
        int *p = (int *)calloc(6, sizeof(int));
        int (**ffpp)(int, int) = (int (**)(int, int))calloc(6, sizeof(int(*)(int, int)));
        *ffpp = getMax;
        *(ffpp + 1) = getMin;
        *(ffpp + 2) = add;
        *(ffpp + 3) = sub;
        *(ffpp + 4) = mull;
        *(ffpp + 5) = divv;
    }
    {
        //简化函数指针
        typedef int Aint;   //类型Aint 就是int类型
        typedef int A[10];  //类型A 就是 int[10]类型
        typedef double* d;  //类型d 就是double*类型
        A a;
        printf("sizeof(A) = %lu\n", sizeof(a));  //40个字节
        d d1;
        printf("sizeof(d) = %lu\n", sizeof(d1));    //8个字节


        typedef int (*FP)(int, int);    //定义函数指针类型
        FP fp;  //FP是函数指针类型，fp是函数指针变量

        typedef int (*AFP[4])(int, int);    //定义函数指针数组类型
        AFP afp = {add, sub, mull, divv};   //AFP是函数指针数组类型，afp是函数指针数组变量

        typedef int (**PP)(int, int);   //定义指向函数指针的指针类型
        PP pp = afp;
    }
    {
        //

    }

    return 0;
}