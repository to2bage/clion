//
// Created by apple on 2017/2/21.
//
#include <stdio.h>
#include <stdlib.h>
#include <zconf.h>

void goo(int num)
{
    if(num == 0)
    {
        return;
    }
    else
    {
        system("ps aux");
        goo(num - 1);
    }
}

static int add(int num)
{
    if(num > 100)
    {
        return 0;
    }
    else
    {
        return num + add(num + 1); //返回值的叠加
    }
}

static void to2(int num)
{
    if(num == 0)
    {
        return;
    }
    else
    {
        {
//            //逆序打印: 1010
//            to2(num / 2);
//            printf("%d", num % 2);
        }
        {
            //逆序打印: 1010
//            num /= 2;
//            printf("%d", num % 2);
//            to2(num);
        }
        {
            //顺序打印: 0101
//            printf("%d", num % 2);
//            to2(num / 2);
        }
        {
            //顺序打印: 0101
            num /= 2;
            to2(num);
            printf("%d", num % 2);
        }
    }
}

int main线性递归(int argc, char* argv[])
{
    {
//        system("ps aux");
//        sleep(1);
//        main(argc, argv);
    }
    {
        int rect = add(1);
        printf("rect = %d\n", rect);
    }
    {
        to2(10);
    }

    return 0;
}


