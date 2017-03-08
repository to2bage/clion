//
// Created by apple on 2017/3/8.
//
#include <stdio.h>
#include <stdlib.h>

int main数组的三种形式(int argc, char* argv[])
{
    {
        int a[5] = {1,2,3,4,5}; //静态数组
        int *p = (int *)malloc(5 * sizeof(int));    //动态数组
        int *pc99 = (int[]){[4] = 5};   //静态数组
    }
    {
        //C99最新的数组定义方式： [10]=50表示下表为10的元素值为50，其余默认为0
        //vs2013 gcc4.7支持
        int a[] = {[10] = 50};
        for(int i = 0; i < 11; i++)
        {
            printf("%4d", a[i]);
        }
    }
    {
        //int[] 代表数组类型， 在栈上分配一片内存，并让p1，p2指向它
        int *p1 = (int[]){[2] = 1, [4] = 10};   //静态数组
        int *p2 = (int[10]){[5] = 100};     //明确了数组的长度为10个元素，第6个元素值是100
        int *p3 = (int[30]){};
        int *p4 = (int[13]){0};
    }

    return 0;
}
