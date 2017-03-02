//
// Created by apple on 2017/3/1.
//
#include <stdio.h>
#include <stdlib.h>


int main32位与64位区别(int argc, char* argv[])
{
    {
        //32位和64位系统的区别
        int num = 12; //从代码区读取，并在寄存器中产生12，再赋值给内存里的变量num
        int *px = &num;
        printf("sizeof(int *) = %d\n", sizeof(int*));//64位是8个字节；32位是4个字节
        //指针大小，是有编译器决定的
    }
    {
        //32位， 进程最大内存2G
        //64位， 进程最大内存1024G
    }
    {
        //栈和堆
        auto int num = 90;  //栈， 而这个栈的大小是由编译器来决定的
        void *p = malloc(1024); //堆
        int a[1024 * 1024] = {0};
        printf("%d", a[100]);
        // 局部变量都在栈上
        // 每一个线程都有独立的栈， 但堆是线程共享的
    }
    {
        // 内存的数据区： 栈 ， 堆  和  静态区
    }

    return 0;
}

