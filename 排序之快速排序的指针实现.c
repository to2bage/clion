//
// Created by apple on 2017/3/10.
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10

static int *getArcher(int *parr, int* pstart, int *pend)
{
    int *pleft = pstart;
    int *pright = pend;
    int archer = *pstart;

    while(pleft <= pright)
    {
        //从左边找比archer大的数
        while(*pleft <= archer && pleft <= pend)
        {
            pleft++;
        }
        ////此时pleft指向比archer大的数

        //从右边找比archer小的数
        while (*pright >= archer && pright > pstart)
        {
            pright--;
        }
        ////此时pright指向比archer小的数

        if(pleft <= pright)
        {
            int temp = *pleft;
            *pleft = *pright;
            *pright = temp;
        }
    }

    //交换pstart和pright pright始终指向小于archer的值
    int temp = *pstart;
    *pstart = *pright;
    *pright = temp;

    return pright;
}

static void quickSort(int *parr, int *pstart, int *pend)
{
    if(pstart <= pend)
    {
        int *ptemp = getArcher(parr, pstart, pend);
        quickSort(parr, pstart, ptemp - 1);
        quickSort(parr, ptemp + 1, pend);
    }
}

static void show(int *parr, int length)
{
    for(int i = 0; i < length; i++)
    {
        printf("%4d", parr[i]);
    }
    printf("\n");
}

int main快速排序的指针实现(int argc, char* argv[])
{
    srand(time(NULL));

    int arr[N] = {0};
    for(int i = 0; i < N; i++)
    {
        printf("%4d", arr[i] = rand() % 100);
    }
    printf("\n");

//    int *parch = getArcher(arr, arr, arr + N - 1);
//    printf("index = %lu, %d\n", parch - arr, *parch);
    quickSort(arr, arr, arr + N - 1);

    show(arr, N);

    return 0;
}
