//
// Created by apple on 2017/3/28.
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <memory.h>

#define N 11

static void showTest(int *parr, int size)
{
    for(int i = 1; i < size; i++)
    {
        printf("%4d", parr[i]);
    }
    printf("\n");
}

static void heapAdjust(int *parr, int curIndex, int endIndex)
{
    int cur = parr[curIndex];

    for(int i = curIndex * 2; i <= endIndex; i *= 2)
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
            curIndex = i;       //因为交换过一次之后, curIndex没有变,但parr[curIndex]改变了，所以要改变curIndex的值
        }
//        else
//        {
//            break;
//        }
    }
}

static void heapsortTest(int *parr, int endIndex)
{
    for(int i = endIndex / 2; i > 0; i--)
    {
        //循环至数组下标1的元素为止, 调整为大顶堆
        heapAdjust(parr, i, endIndex);
        showTest(parr, endIndex + 1);
    }

    for(int i = endIndex; i > 0; i--)
    {
        {
            int temp = parr[1];
            parr[1] = parr[i];
            parr[i] = temp;
        }

        heapAdjust(parr, 1, i - 1);
    }

}

int mainheap(int argc, char *argv[])
{
//    int parr[11] = {-1, 45, 12, 78, 23, 90, 200, 21, 67, 9, 51};

//    srand(time(NULL));
//    int *parr = (int *)calloc(N, sizeof(int));
//    memset(parr, -1, N * sizeof(int));
//
//    for(int i = 1; i < N; i++)
//    {
//        printf("%4d", parr[i] = rand() % 100);
//    }
//    printf("\n");

    int parr[N] = { -1, 70,  44,  95,  86,  62,  90,  14,  91,  12,  96};

    heapsortTest(parr, N - 1);  //第二个参数是最后一个元素的下标, 也可以理解为多少个有效元素
    //showTest(parr, N);


    return 0;
}
