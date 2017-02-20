//
// Created by apple on 2017/2/16.
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h> //时间

int main赌博的概率(int argc, char* argv[])
{
    {
        time_t tstart;
        unsigned int num = time(&tstart);
        srand(num);    //根据当前时间，产生随机数的种子
        int number = rand() % 100; //生成随机数
        printf("%d\n", number);
    }
    {
        time_t tstart;
        unsigned int num = time(&tstart);
        srand(num);
        int data = rand() % 100;
        data > 90 ? printf("你赢了哦啊！！！\n") : printf("你输钱了\n");
    }

    return 0;
}
