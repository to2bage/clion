//
// Created by apple on 2017/2/15.
//
#include <stdio.h>

int main位运算(int argc, char* argv[])
{
    {
        unsigned char ch = 255; // 1111 1111
        unsigned char ch1 = 15; // 0000 1111
        // 任何数 &0 都会置0； 任何数 &1 都会保持不变
    }
    {
        // 任何数 |1 都会置1； 任何数 |0 都会保持不变
    }
    {
        //异或^
        // 任何数 ^0 都会保持不变 ; 任何数 ^1 都会反转
    }
    {
        // ~ 和 ！
    }
    {
        //左移
    }
    {
        //右移 等价于整除2
        int a = 1; // 0001
        printf("%d\n", a >> 1); //0

    }

    return 0;
}
