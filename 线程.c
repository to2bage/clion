//
// Created by apple on 2017/3/6.
//
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

static void * thread_start(void *p)
{
    int *px = (int *)p;
    printf("线程打印%d\n", *px);
    return px;
}

int main线程(int argc, char* argv[])
{
    {
        srand(time(NULL));

        int a[8] = {0};
        for(int i = 0; i < 8; i++)
        {
            a[i] = rand() % 100;
        }

        for(int i = 0; i < 8; i++)
        {
            pthread_t  pid = (pthread_t)i;
            pthread_create(&pid, NULL, thread_start, &a[i]);
            pthread_join(pid, NULL);
        }
    }

    return 0;
}
