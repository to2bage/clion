//
// Created by apple on 2017/3/28.
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <memory.h>


#define N 6

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

static void heapAdjust(int *parr, int index, int size)  //size表示最有一个节点的下标
{
    {
        for(int i = index * 2; i <= size; i = 2 * i)    //因为size表示最后一个节点的下标，所以i<=size
        {
            if(i < size  && parr[i] < parr[i + 1])
            {
                i++;
            }       //此时i表示index下标的父节点的左右子树中的最大值的下标

            if(parr[i] > parr[index])
            {
                int temp = parr[i];
                parr[i] = parr[index];
                parr[index] = temp;
            }
            else
            {
                break;
            }
        }
    }
    {
//        int temp = parr[index];
//
//        for(int i = index * 2; i <= size; i = 2 * i)
//        {
//            if(i < size && parr[i] < parr[i + 1])     //i< size是因为size的值是最后一个数组元素的下标
//            {
//                i++;
//            }
//
//            if(parr[i] <= temp)
//            {
//                break;
//            }
//
//            parr[index] = parr[i];
//            index = i;
//        }
//
//        parr[index] = temp;
    }
}

static void heapSortBig(int *parr, int size)    //size == 5 表示最后一个节点的下标了
{
    //先期调整：从最后一个有子节点的节点开始，向上(向下标为1的元素)做大顶堆的调整
    for(int i = size / 2; i > 0; i--)
    {
        heapAdjust(parr, i, size);
        //show(parr, size + 1);
    }   //到此， 把元素中最大的元素放置在数组序号为1的位置

    //再次调整：此时数组下标为1的元素已经是最大值了
    //         按照从小到大的顺序排列，把下标为1的元素和最后一个元素对调
    //         再从下标为1的元素开始调整为大顶堆，因为有上面的先期调整，有子节点的节点的值比左右子节点的值要大，所以自上而下的调整
    for(int i = size; i > 0; i--)   // i > 0表示i只循环到1；
    {
        swap(parr, i, 1);
        heapAdjust(parr, 1, i - 1);
        //show(parr, size + 1);
    }

}


int main(int argc, char *argv[])
{
    srand(time(NULL));
    int *parr = (int *)calloc(N, sizeof(int));
    memset(parr, -1, N * sizeof(int));

    for(int i = 1; i < N; i++)
    {
        printf("%4d", parr[i] = rand() % 100);
    }
    printf("\n");

//    int *parr = (int[N]){-1, 61, 73, 21, 45, 100};


    heapSortBig(parr,N - 1);
//    heapAdjust(parr, 0, N);

    show(parr, N);

    return 0;
}
