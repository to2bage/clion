//
// Created by apple on 2017/2/16.
//
#include <stdio.h>

int mainfor(int argc, char* argv[])
{
    {
        int sum = 0;
        for(int i = 0; i < 100; i += 2)
        {
            sum += i * (i + 1);
        }
        printf("sum = %d\n", sum);
    }

    return 0;
}

