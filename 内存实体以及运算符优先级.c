//
// Created by apple on 2017/2/15.
//
#include <stdio.h>

int main内存和运算优先级(int argc, char* argv[])
{
    int a = 10;
    const int d = 0;
    *((int*)&d) = 100;
    printf("d = %d\n", d);

//    a = a + 7;
//    printf("a = %d\n", a);
    int b = 2, c = 5;
    printf("%d\n", a = 7 + b + c, a++);

    {
        double x = 1.0;
        double y = ++x*++x;
        printf("%lf\n", y);
    }
    {
        int a = 3;
        printf("rect = %d, a = %d\n", a < 1 && --a > 1, a);
    }
    {
        double x = 213.82631;
        printf("%-6.2e\n", x);
    }
    {
        char b, c, *d;
        char a;
        b = '\xbc';
        c = '\0xab';
        d = '\0127';
        printf("%c\n%c\n%c\n", b, c, d);

        // 1111 1111 1111 1110
        // 0000 0000 0000 0010
        // 0000 0000 0000 0010
        // 0000 0000 0000 0011
        // 0000 0000 0000 0001

    }

    return 0;
}
