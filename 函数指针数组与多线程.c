//
// Created by apple on 2017/3/9.
//
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

static void *run1(void *p)
{
    printf("run1 function\n");
    return NULL;
}
static void *run2(void *p)
{
    printf("run2 function\n");
    return NULL;
}
static void *run3(void *p)
{
    printf("run3 function\n");
    return NULL;
}

int main函数指针数组和多线程(int argc, char* argv[])
{
    {
        pthread_t pid;
        pthread_create(&pid, NULL, run1, NULL);
        pthread_join(pid, NULL);
    }
    {
        //pthread_t pids[3];
        //pthread_t *pids = (pthread_t[3]){};
        pthread_t *pids = (pthread_t *)calloc(3, sizeof(pthread_t));

        //void * (*afp[3])(void *) = {run1, run2, run3};    // 栈上分配内存，定义函数指针数组，老版本
        void* (**fpp)(void*) = (void* (*[])(void*)){run1, run2, run3};// 栈上分配内存，定义函数指针数组，c99版本
//        void *(**pp)(void *) = (void *(**)(void*))calloc(3, sizeof(void*(*)(void*)));//堆上分配内存
//        *pp = run1;
//        *(pp + 1) = run2;
//        *(pp + 2) = run3;

        for(int i = 0; i < 3; i++)
        {
            //pthread_create(&pids[i], NULL, afp[i], NULL);
            //pthread_create(&pids[i], NULL, pp[i], NULL);
            pthread_create(&pids[i], NULL, fpp[i], NULL);
        }

        for(int i = 0; i < 3; i++)
        {
            pthread_join(pids[i], NULL);    //主线程等待每个子线程完成
        }
    }

    return 0;
}
