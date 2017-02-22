//
// Created by apple on 2017/2/21.
//
#include <stdio.h>
#include <time.h>

int mainVolatile(int argc, char* argv[])
{
    {
        time_t tstart, tend;
        time(&tstart);
        for(volatile int i = 0; i < 999999999; i++)
        {

        }
        time(&tend);
        printf("耗时: %d秒\n", tend - tstart);
        printf("hello world\n");
    }

    return 0;
}
