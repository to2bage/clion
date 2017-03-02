//
// Created by apple on 2017/3/1.
//

/*
 *  指针 就是变量的地址,比如说&num就是一个指针
 *  指针变量(p) 它是存贮地址的变量
 *
 * */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main指针(int argc, char* argv[])
{
    {
        int num = 10;   //变量num代表内存中的数据10
        int *p = &num;
        //&num:取变量num的地址，这是在cpu的寄存器里产生的, 且不占内存
        //地址作为常量，不占用内存，地址是计算机总线产生的
        //使用变量p保存了变量num的地址(占4个字节)，但变量p的地址是由系统总线产生的(寄存器)
        printf("sizeof(p) = %lu\n", sizeof(p)); //8
        printf("sizeof(double*) = %lu\n", sizeof(double*)); //8
        printf("sizeof(int*) = %lu\n", sizeof(int*)); //8
    }
    {
        int num1 = 100;
        double *p = &num1;
        printf("%f\n", *p); //打印是 垃圾数据
        //指针的类型 决定了从&num1地址开始读取数据的步长和解析数据的方式
        //使用指针读取数据(*p)时， 要注意指针变量的类型，此时*p是double类型，从地址&num开始要读取8个字节的内容
    }
    {
        //指针的间接赋值
        int num = 10;
        *((int *)(&num)) = 2345;
        printf("num = %d\n", num);    //2345
    }
    {
        //空类型的指针变量
        //void a; //不合法，无法确定变量a的类型，无法分配内存
        int num = 10;
        double db = 19.3;
        void *p = &num;
        p = &db; //void*类型的指针变量 可以指向任何的数据类型的地址
        //printf("%d", *p); //但不能读取void*类型的指针变量指向的数据
        //void *p 不能间接取值(*p)， 也不能间接赋值(*p = 12);
    }
    {
        //空指针
        double* p = NULL; //NULL是空类型的0
        //不能间接取值(*p)
    }
    {
        //指针的定义初始化
        int a, b, c;
        int *pa, pb, pc;    //pa是int*类型, pb和pc是int类型
        printf("%d, %d\n", sizeof(pa), sizeof(pc)); //8, 4

#define pdouble double*
        typedef int* pint;
        pdouble pdx = NULL;
        pint pix = NULL;
    }
    {
        //指针数组排序
        time_t tstart;
        unsigned int num = time(&tstart);
        srand(num);

        int a[20] = {0};
        const int *pa[20] = {0};
        for(int i = 0; i < 20; i++)
        {
//            printf("%4d", a[i] = rand() % 300);
            a[i] = rand() % 300;
            pa[i] = a + i;
        }
        printf("\n");

        //
        for(int i = 0; i < 20 - 1; i++)
        {
            for(int j = 0; j < 20 - i - 1; j++)
            {
                if(*pa[j] < *pa[j + 1])
                {
                    int *ptemp = pa[j]; //交换指针的值
                    pa[j] = pa[j + 1];
                    pa[j + 1] = ptemp;
                }
            }
        }
        //
        for(int i = 0; i < 20; i++)
        {
            printf("%4d", a[i]);
        }
        printf("\n");
        //
        for(int **p = pa; p < pa + 20; p++)
        {
            printf("%4d", **p);
        }
        printf("\n");

    }
    {
        //地址的输入
        int num = 10;
        int data = 20;
        printf("&num = %p, &data = %p\n", &num, &data);
        int *p = NULL;
        scanf("%p", &p);    //输入num的地址0x7fff594168bc
        *p = num + data;
        printf("*p = %d\n", *p);    //30
        printf("num = %d\n", num); //30
    }

    return 0;
}

