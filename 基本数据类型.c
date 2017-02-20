//
// Created by apple on 2017/2/17.
//
#include <stdio.h>

int main基本数据类型(int argc, char* argv[])
{
    {
        int a = 2, b = 3, c = 4;
        printf("%d\n", a + b > c && b == c && a || b + c && b + c);
    }
    {
        double a = 23.56, b = 67.09;
        int w = 123;
        long c = 5678;
        printf("%d\n", w = a = b);
    }
    {
        long a = -2L;
        printf("%ld\n", a);
    }
    {
        int z = 1;
        // z = 0000 0000 0000 0000 0000 0001
        //~z = 1111 1111 1111 1111 1111 1110
         //      1000 0000 0000 0000 0000 0001
    }

    return 0;
}

