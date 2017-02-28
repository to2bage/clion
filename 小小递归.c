//
// Created by apple on 2017/2/27.
//
#include <stdio.h>
#include <stdbool.h>

static _Bool isCrease(int *px, int length)
{
    if(length == 1)
    {
        return true;
    }
    else
    {
        return *px < *(px + 1) && isCrease(px + 1, length - 1);
    }
}

static int addDigui(int num)
{
    if(num == 100)
    {
        return 100;
    }
    else
    {
        return num + addDigui(num + 1);
    }
}

static int subDigui(int num)
{
    if(num == 1)
    {
        return 5050 - 1;
    }
    else
    {
        return subDigui(num - 1) - num;
    }
}



int main小小递归(int argc, char* argv[])
{
    {
        //用递归判断数组是否是递增的
        int a[10] = {0,1,2,3,14,5,6,7,8,9};
        _Bool isC = isCrease(a, 10);
        isC == true ? printf("是递增的数组！！！\n") : printf("不是递增的数组...\n");
    }
    {
        //1 + ...+ 100 = 5050;
        int rect = addDigui(0);
        printf("从%d加到%d，最后的结果是: %d\n", 1, 100, rect);
        //f(99) = 5050 - 1 - 2 -... - 99
        //f(100) = 5050 - 1 - 2 -... - 99 - 100 = f(99) - 100
        rect = subDigui(99);
        printf("从%d开始，一直减到%d, 最后的结果是: %d\n", 5050, 99, rect);
    }
    {

    }

    return 0;
}

