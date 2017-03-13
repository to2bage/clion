//
// Created by apple on 2017/3/10.
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10

static void show(int *parr, int length)
{
    for(int i = 0; i < length; i++)
    {
        printf("%4d", parr[i]);
    }
    printf("\n");
}



static void findMax(int *parr, int length)
{
    for(int i = length - 1; i > 0; i--)
    {
        int parent = i / 2;
        int child = i;
        if(i < length - 1 && parr[i] < parr[i + 1])
        {
            child++;        //选出子节点中的最大的数，child指向这个最大数的下标
        }
        if(parr[child] > parr[parent])
        {
            int temp = parr[child];
            parr[child] = parr[parent];
            parr[parent] = temp;
        }
    }

}

static void heapSort(int *parr, int length)
{
    for(int i = 0; i < length; i++)
    {
        findMax(parr + i, length - i);
    }
}

int main堆(int argc, char* argv[])
{
    srand(time(NULL));

    int arr[N] = {0};
    for(int i = 0; i < N; i++)
    {
        printf("%4d", arr[i] = rand() % 100);
    }
    printf("\n");

//    findMax(arr, N);
    heapSort(arr, N);
    show(arr, N);

    return 0;
}
