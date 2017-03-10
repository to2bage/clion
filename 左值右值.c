//
// Created by apple on 2017/3/9.
//
#include <stdio.h>

int main左值右值(int argc, char* argv[])
{
    {
        //常量10 存在于代码区的常量符号表中
        int a = 10; //cpu把常量10 读入寄存器中， 再复制给内存中的变量a
        // &10, &(a + 12)都是错误的！！！
        //左值： 都在内存，都有内存实体的
        //右值： 一般都在寄存器中， 没有内存实体
        //左值可以当做右值
    }
    {
        int a = 10;
        int b = 20;
        int *p = &a;
    }
    {
        const int num = 10;
        printf("%4d\n", num);

        *((int *)(&num)) = 100;
        printf("%4d\n", num);
    }

    return 0;
}
