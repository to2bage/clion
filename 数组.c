//
// Created by apple on 2017/2/24.
//
//  &a[i] <=> a + i;   *&a[i] <=> *(a + i)
//
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main数组初步(int argc, char* argv[])
{
    double a[10] = {0}; //c/c++的数组必须初始化
    double a1[] = {1.1,2.1}; //明确了数组的大小，可以省略数组的大小

    printf("sizeof(a) = %lu\n", sizeof(a)); //80个字节
    for(int i = 0; i < 10; i++)
    {
        printf("%f, %f, %f, %p, %p\n", a[i], *&a[i], *(a + i), &a[i], a + i);
    }
    //
    int num = 10;
    //int b[num] = {0};   //vc不可以这样做，vc必须静态分配； 而gcc可以动态分配

    printf("%p, %p\n", &a[4], &a[0] + sizeof(double));//?????

    {
        //选择排序
        time_t tstart;
        unsigned int num = time(&tstart);
        srand(num);
        int a[20] = {0};
        for(int i = 0; i < 20; i++)
        {
            a[i] = rand() % 300;
        }

        for(int i = 0; i < 20 - 1; i++) // 20-1 表示：程序在运行到数组的倒数第二个元素时，就已经排好序了，没必要在运行下去了
        {
            int maxindex = i;
            for(int j = i + 1; j < 20; j++)
            {
                if(a[j] > a[maxindex])
                {
                    maxindex = j;
                }
            }
            {
                //交换
                int temp = a[i];
                a[i] = a[maxindex];
                a[maxindex] = temp;
            }
        }

        for(int i = 0; i < 20; i++)
        {
            printf("%5d", a[i]);
        }
        printf("\n");
    }
    {
        //冒泡排序
        time_t tstart;
        unsigned int num = time(&tstart);
        srand(num);
        int a[20] = {0};
        for(int i = 0; i < 20; i++)
        {
            a[i] = rand() % 300;
        }

        for(int i = 0; i < 20 - 1; i++) //20-1：程序运行到数组的倒数第二个元素时，一轮的比较就已经结束了，不需要在运行下去了
        {
            for(int j = 0; j < 20 - i - 1; j++) //20-i-1：20-1是因为20个元素两两比较，只能比较19次; -i是因为每轮比较都会都会有一个元素排好序了
            {
                if(a[j] > a[j + 1])
                {
                    int temp = a[j];
                    a[j] = a[j + 1];
                    a[j + 1] = temp;
                }
            }
        }

        for(int i = 0; i < 20; i++)
        {
            printf("%5d", a[i]);
        }
        printf("\n");
    }
    {
        //斐波那契的数组法
        int num = 0;
        printf("请输入斐波那契数组的长度:");
        scanf("%d", &num);

        int *px = (int *)malloc(num * sizeof(int));
        int *pend = px + num ;
        if(px == NULL)
        {
            return -1;
        }


        int num1 = 1;
        int num2 = 1;
        px[0] = num1;
        px[1] = num2;
        int *p = px + 2;
        while(p != pend)
        {
            int temp = num1 + num2;
            num1 = num2;
            num2 = temp;
            *p++ = temp;
        }
        for(int i = 0; i < num; i++)
        {
            printf("%15d", px[i]);
            (i + 1) % 5 == 0 ? printf("\n"): printf("");
        }
    }

    return 0;
}
