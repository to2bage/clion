//
// Created by apple on 2017/3/7.
//
#include <stdio.h>

int main指针的运算(int argc, char* argv[])
{
    {
        int a;
        int b;
        int c;
        printf("&a = %p\n&b = %p\n&c = %p\n", &a, &b, &c);
        // &a > &b > &c 变量a先入栈，其次是变量b， 最后是变量c
    }
    {
        //指针的减法的单位是字节，比奥斯两个指针相差多少字节
        int a[5] = {1,2,3,4};
        int *p = a;
        int *px = a + 4;
        printf("px - p = %d\n", px - p);    // 4字节 = (&a[4] - &a[0]) / sizeof(int)

        char *px1 = a;
        char *px2 = a + 4;
        printf("px2 - px1 = %d\n", px2 - px1); //16字节 = (&a[4] - &a[0]) / sizeof(char)

        int *p1 = a;
        double *p2 = a + 4;
        //printf("p2 - p1 = %d\n", p2 - p1); //error 两个不同类型的指针相减没有意义
    }
    {
        int a[10] = {1,2,3,4,5,6,7,8,9,10};
        int b[3][4] = {1,2,3,4,5,6,7,8,9,10,11,12};

        printf("a = %p, &a = %p\n", a, &a);
        //a是一个指针， 步长是4个字节， 指向一个元素
        //&a是一个指针，步长是40个字节， 指向一个有10个元素的int类型的一维数组
        //可以通过下面的方式来验证 a 和 &a 的类型
        printf("a + 1 = %p, &a + 1 = %p\n", a + 1, &a + 1);



        printf("b = %p, &b = %p, *b = %p\n", b, &b, *b);
        //b是一个行指针，步长是16个字节， 指向一行（一维数组）
        //&b是一个数组指针，步长是48个字节， 指向一个二维数组
        //*b是一个元素指针，步长是4个字节， 指向一个元素
        printf("b + 1 = %p, &b + 1 = %p, *b + 1 = %p\n", b + 1, &b + 1, *b + 1);
    }

    return 0;
}
