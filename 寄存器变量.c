//
// Created by apple on 2017/2/22.
//
// 寄存器变量可以加速语句的执行， vs会自动优化非寄存器变量为寄存器变量， 而gcc不会
// 需要把频繁使用的对象， 声明为寄存器变量
// 全局变量最好不要声明为寄存器变量， 反而会影响程序的执行速度
// 静态变量不可以什么为寄存器变量
// c++和c语言不同， c++中寄存器变量在内存中会有副本，而c则没有这个副本

#include <stdio.h>
#include <time.h>

//register int g_inum = 0;    // 全局变量不能声明为寄存器变量
//register static int s_inum = 0; //静态变量不能什么为寄存器变量

int main寄存器变量(int argc, char* argv[])
{
    time_t tstart, tend;
    time(&tstart);

    register double sum = 0;
    //double sum = 0;
    for(int i = 0; i < 100000000; i++)
    {
        sum += i;
    }
    printf("sum = %f\n", sum);
    time(&tend);

    printf("耗时: %d秒\n", tend - tstart);

    return 0;
}

