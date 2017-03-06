//
// Created by apple on 2017/3/6.
//
/*
 *  | 数组元素1 | 数组元素2 | 数组元素3 |
 *  |          |          |          |
 *  |
 *  a+0       a+1        a+2        a+3
 *
 *
 * */
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
#include <memory.h>
#include <zconf.h>
//#include "队列.h"

#define N 1024

struct MyInfo
{
    int id; //线程编号
    int length; // 每个线程要处理多少元素
    int *pstart;    //开始地址
    int sum;    //数据之和
};

typedef struct MyInfo Info;


static void * go(void *p)
{
    Info *pinfo = (Info*)p;
    for(int i = 0; i < pinfo->length; i++)
    {
        pinfo->sum += pinfo->pstart[i];
    }
    printf("线程%d计算的结果是: %d\n", pinfo->id, pinfo->sum);
    return &pinfo->sum;
}

int main指针数组强化(int argc, char* argv[])
{
    {
//        int a[10] = {1,2,3,4,5,6,7,8,9,10};
//        printf("%d\n", 8[a]);   //9
    }
    {
        srand(time(NULL));
        int data[N] = {0};
        int sum = 0;
        for(int i = 0; i < N; i++)
        {
            int num = rand() % 1000;
            sum += num;
            printf("%5d", data[i] = num);
        }
        printf("\nsum = %d\n", sum);

        {
            //1.
//            int threadLength = 0;
//            printf("请输入线程的长度: ");
//            scanf("%d", &threadLength);
//
//            if(N % threadLength == 0)
//            {
//
//                Info *pInfos = (Info *)malloc((N / threadLength) * sizeof(Info));
//                memset(pInfos, 0, (N / threadLength) * sizeof(Info));
//
//                for(int i = 0; i < N / threadLength; i++)
//                {
//                    pInfos[i].id = i;
//                    pInfos[i].length = threadLength;
//                    pInfos[i].pstart = data + threadLength * i;
//                    pInfos[i].sum = 0;
//
//                    pthread_create((pthread_t*)&i, NULL, go, &pInfos[i]);
//                }
//
//                //
//                for(int i = 0; i < N / threadLength; i++)
//                {
//                    pthread_join((pthread_t)pInfos[i].id, NULL);
//                }
//            }
//            else
//            {
//
//                Info *pinfos = (Info *)malloc((N / threadLength + 1) * sizeof(Info));
//                memset(pinfos, 0, (N / threadLength + 1) * sizeof(Info));
//
//                int i = 0;
//                for(; i < N / threadLength; i++)
//                {
//                    pinfos[i].id = i;
//                    pinfos[i].length = threadLength;
//                    pinfos[i].pstart = data + threadLength * i;
//                    pinfos[i].sum = 0;
//
//                    pthread_create((pthread_t*)&i, NULL, go, &pinfos[i]);
//                }
//
//                int j = i;
//                pinfos[j].id = j;
//                pinfos[j].length = N % threadLength;
//                pinfos[j].sum = 0;
//                pinfos[j].pstart = data + N / threadLength * threadLength;
//
//                pthread_create((pthread_t*)&j, NULL, go, &pinfos[j]);
//
//                for(int i = 0; i < N / threadLength + 1; i++)
//                {
//                    pthread_join((pthread_t)pinfos[i].id, NULL);
//                }
//            }
        }

        {
            //2.
            Info infos[8] = {0};
            //void *res = NULL;
            for(int i = 0; i < 8; i++)
            {
                infos[i].id =  i;
                infos[i].length = N / 8;
                infos[i].sum = 0;
                infos[i].pstart = data + i * (N / 8);

                pthread_t pid = (pthread_t)i;
                pthread_create(&pid, NULL, go, &infos[i]);
//                pthread_join(pid, NULL);

               // printf("%d\n", *((int*)res));
            }

            for(int i = 0; i < 8; i++)
            {
                pthread_t pid = (pthread_t)infos[i].id;
                pthread_join((pthread_t)infos[i].id, NULL);
            }
        }

        sleep(2);
    }


    return 0;
}
