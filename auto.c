//
// Created by apple on 2017/2/16.
//  在函数内部使用auto int num修饰变量等价于 int num
//  换句话说： 在函数中定义的变量，默认就是auto的
//
#include <stdio.h>

void go()
{
    int num = 10;
    printf("%p\n", &num);
}

int mainAuto(int argc, char* argv[])
{
    {
        auto int num = 10; // auto自动分配， 自动释放

    }

    return 0;
}
