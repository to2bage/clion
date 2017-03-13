//
// Created by apple on 2017/3/12.
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 20

static void show(int *parr, int size)
{
    for(int i = 1; i < size; i++)
    {
        printf("%4d", parr[i]);
    }
    printf("\n");
}

static void swap(int *parr, int index1, int index2)
{
    int temp = parr[index1];
    parr[index1] = parr[index2];
    parr[index2] = temp;
}

static void heapAdjust(int *parr, int index, int size)
{
    int temp = parr[index];

    for(int i = index * 2; i <= size; i *= 2)
    {
        if( i < size && parr[i] < parr[i + 1])
        {
            i++;
        }

        if(parr[i] <= temp)
        {
            break;
        }

        parr[index] = parr[i];
        index = i;
    }

    parr[index] = temp;
}

static void heapSort(int *parr, int size)
{
    //从有子节点的节点(size / 2)开始，构建大顶堆。
    for(int i = size / 2; i > 0; i--)           // i > 0 也即i！= 0, 数组是从索引1开始排序的
    {
        //调用函数，把数组索引从i开始的数据,包括其子节点，子子节点都调整为大顶堆
        heapAdjust(parr, i, size);
    }

    //再将索引为1的元素和数组的最后一个元素互换， 因为是要从小到大的排序
    //此时，整个数组又不符合大顶堆的要求了，所用还要再次的调用函数heapAdjust
    for(int i =  size; i > 0; i--)
    {
        swap(parr, i, 1);
        //再次调整为大顶堆(因为索引为1的值已经不符合大顶堆的要求了)
        heapAdjust(parr, 1, i - 1);
    }
}

int main大顶堆(int argc, char* argv[])
{
    srand(time(NULL));
    int *parr = (int *)calloc(N, sizeof(int));
    if(!parr)
    {
        printf("分配内存失败\n");
        return -1;
    }

    //数组是从索引1开始的，索引0的值是-1，保存最大的值
    *parr = -1;
    int *px = parr + 1;
    while(px < parr + N)
    {
        printf("%4d", *px++ = rand() % 100);
    }
    printf("\n");

    //heapSort
//    heapSort(parr, N - 1);
    heapAdjust(parr, 1, N - 1);

    show(parr, N);

    return 0;
}

