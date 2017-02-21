//
// Created by apple on 2017/2/21.
//
#include <stdio.h>
#include <time.h>

//斐波那契递归实现
int getNumberDigui(int number)
{
    if(number == 1 || number == 2)
    {
        return 1;
    }
    else
    {
        return getNumberDigui(number - 1) + getNumberDigui(number - 2);
    }
}
//斐波那契循环实现
int getNumberXunhuan(int number)
{
    int num1 = 1, num2 = 1;
    int i = 3;
    while(i++ <= number)
    {
        int temp = num1 + num2;
        num1 = num2;
        num2 = temp;
    }
    return num2;
}


int main树状递归(int argc, char* argv[])
{
    {
        time_t tstart, tend;
        time(&tstart);
        printf("%d\n", getNumberDigui(40));
        time(&tend);
        printf("递归共耗时: %d秒\n", tend - tstart);
        //
        time(&tstart);
        printf("%d\n", getNumberXunhuan(40));
        time(&tend);
        printf("循环共耗时: %d秒\n", tend - tstart);
    }

    return 0;
}
