//
// Created by apple on 2017/2/27.
//
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#define COUNT 20

static void binarySearch(int *px, int length, int findNumber)
{
    int begin = 0;
    int end = length - 1;
    int mid = 0;
    _Bool isFind = false;

    while(begin <= end)
    {
        mid = (begin + end) / 2;

        if(findNumber < px[mid])
        {
            end = mid - 1;
        }
        else if(findNumber > px[mid])
        {
            begin = mid + 1;
        }
        else if(findNumber == px[mid])
        {
            isFind = true;
            break;
        }
    }

    if(isFind == true)
    {
        printf("恭喜！！！找到了%d\n", px[mid]);
    }
    else
    {
        printf("抱歉没有找到哦。。。\n");
    }
}

static void bubleSort(int *px, int length)
{
    for(int i = 0; i < length - 1; i++)
    {
        for(int j = 0; j < length - 1 - i; j++)
        {
            if(px[j] > px[j + 1])
            {
                int temp = px[j];
                px[j] = px[j + 1];
                px[j + 1] = temp;
            }
        }
    }
}

int main二分查找(int argc, char* argv[])
{
    time_t tstart;
    srand(time(&tstart));

    int *parr = (int *)malloc(COUNT * sizeof(int));

    if(parr == NULL)
    {
        printf("error\n");
        return -1;
    }


    for(int i = 0; i < COUNT; i++)
    {
        printf("%5d", parr[i] = rand() % 300);
        (i + 1) % 10 == 0 ? printf("\n") : printf("");
    }
    //二分查找： 首要条件是序列是有序的!!!
    bubleSort(parr,COUNT);

    while(1)
    {
        int findnum = 0;
        printf("请输入要查找的数字: ");
        scanf("%d", &findnum);
        printf("你输入的数字是%d\n", findnum);

        binarySearch(parr, COUNT, findnum);
    }



    free(parr);

    return 0;
}

