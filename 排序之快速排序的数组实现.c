//
// Created by apple on 2017/3/10.
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10

//start数组parr区间开始的索引， end是数组parr区间的最后一个元素的索引
static int getAcher(int *parr, int start, int end)
{
    int archer = parr[start];
    int left = start + 1;
    int right = end;

    while(left <= right)    //等于 无非也就多做一次循环而已
    {
        //从左边找 比archer大的数
        while(parr[left] <= archer && left <= end)  //parr[left]<=archer 是有重复数据的情况
        {
            left++;
        }
        ////此时left指向区间中比archer大的数

        while(parr[right] >= archer && right > start)   //因为是和parr[start]比较，所以right>start
        {
            right--;
        }
        ////此时right指向区间中比archer小的数

        if(left <= right)           //这里的<= 或 < 都是可以的
        {
            //交换
            int temp = parr[left];
            parr[left] = parr[right];
            parr[right] = temp;
        }
    }

    //交换start 和 right 的数据
    int temp = parr[start];
    parr[start] = parr[right];
    parr[right] = temp;

    return right;
}

static void quickSort(int *parr, int start, int end)
{
    if(start < end)
    {
        int ach = getAcher(parr, start, end);
        quickSort(parr, start, ach - 1);
        quickSort(parr, ach + 1, end);
    }
}

static void show(int *parr, int length)
{
    for(int i = 0; i < N; i++)
    {
        printf("%4d", parr[i]);
    }
    printf("\n");
}

int main快速排序的数组实现(int argc, char* argv[])
{
    srand(time(NULL));

    int a[N] = {0};
    for(int i = 0; i < N; i++)
    {
        printf("%4d", a[i] = rand() % 100);
    }
    printf("\n");

//    int acher = getAcher(a, 0, N - 1);    //数组a , 区间是[0, N-1]
//    printf("acher = %d\n", acher);

    quickSort(a, 0, N - 1);

    show(a, N);

    return 0;
}
