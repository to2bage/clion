//
// Created by apple on 2017/3/28.
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <memory.h>

#define N 10

static void showHeap(int *parr, int size)
{
    for(int i = 0; i < size; i++)
    {
        printf("%4d", parr[i]);
    }
    printf("\n");
}

static void heapAdjust(int *parr, int curIndex, int endIndex)
{
    for(int i = 2 * curIndex + 1; i <= endIndex; i = 2 * i + 1)
    {
        if(i < endIndex && parr[i] < parr[i + 1])
        {
            i++;
        }

        if(parr[i] > parr[curIndex])
        {
            int temp = parr[i];
            parr[i] = parr[curIndex];
            parr[curIndex] = temp;
            //
            curIndex = i;
        }
    }
}

static void heapSort(int *parr, int endIndex)
{
    for(int i = (endIndex - 1) / 2; i >= 0; i--)
    {
        heapAdjust(parr, i, endIndex);
        showHeap(parr, N);
    }

    //这里是大顶堆建立的情况下
    for(int i = endIndex; i >= 0; i--)
    {
        //
        int temp = parr[0];
        parr[0] = parr[i];
        parr[i] = temp;

        //
        heapAdjust(parr, 0, i - 1);
    }
}

int mainheap1(int argc, char *argv[])
{
    srand(time(NULL));
    int *parr = (int *)calloc(N, sizeof(int));
    memset(parr, 0, N * sizeof(int));

    for(int i = 0; i < N; i++)
    {
        printf("%4d", parr[i] = rand() % 100);
    }
    printf("\n");

//    int parr[N] = { 70,  44,  95,  86,  62,  90,  14,  91,  12,  96};

    //
    heapSort(parr, N - 1);
    showHeap(parr, N);

    return 0;
}
