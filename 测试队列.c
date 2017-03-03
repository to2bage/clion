//
// Created by apple on 2017/3/2.
//

#include "队列.h"
#include <pthread.h>

Queue queue;

static void *go(void *p)
{
    int *px = (int *)p;
    printf("线程%d\n", *px);
    enQueue(&queue, *px);
    return NULL;
}

int mainc测试队列(int argc, char* argv[])
{
    {
        //测试队列
        Queue queue;
        initQueue(&queue);

        for(int i = 99; i < 108; i++)
        {
            enQueue(&queue, i);
        }

        showQueue(&queue);

        while(!isEmptyOfQueue(&queue))
        {
            printf("%5d出队\n", getLast(&queue));
            deQueue(&queue);
            showQueue(&queue);
        }

    }
    {
        //测试线程
        initQueue(&queue);

        pthread_t threadId;
        for(int i = 0; i < 20; i++)
        {
            pthread_create(&threadId, NULL, go, (void*)&i);
        }


    }

    return 0;
}