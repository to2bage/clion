//
// Created by apple on 2017/2/20.
//
#include <stdio.h>
#include <stdlib.h>

int getmax(int a, int b)
{
    return a > b ? a : b;
}

int main(int argc, char* argv[])
{
    {
//        int a , b;
//        scanf("%d, %d", &a, &b);
//        if(b == 0)
//        {
//            abort();
//        }
//        printf("%d\n", a / b);
    }
    {
        printf("addr = %p\n", getmax);

    }

    return 0;
}

