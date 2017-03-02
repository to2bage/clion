//
// Created by apple on 2017/3/2.
//

#include <stdio.h>
#include "myStack.h"

int main走台阶(int argc, char* argv[])
{
    //1个台阶： 1           1种方法
    //2个台阶:  2, 1 1      2种方法
    //3个台阶:  3, 1 1 1, 1 2, 2 1    4中方法
    //4个台阶:  4, 1 1 1 1, 2 1 1, 1 2 1, 1 1 2, 3 1, 1 3   7中方法

    {
        int step1 = 1, step2 = 2, step3 = 4;
        int curStep = 4;
        int numberOfStep = 0;
        printf("请输入台阶的个数: ");
        scanf("%d", &numberOfStep);

        struct myStack Stack;
        initStack(&Stack);
        push(&Stack, step1);
        push(&Stack, step2);
        push(&Stack, step3);

        while(curStep <= numberOfStep)
        {
            int temp3 = getTop(&Stack);
            pop(&Stack);
            int temp2 = getTop(&Stack);
            pop(&Stack);
            int temp1 = getTop(&Stack);
            pop(&Stack);
            int sum = temp1 + temp2 + temp3;
            push(&Stack, temp2);
            push(&Stack, temp3);
            push(&Stack, sum);
            curStep++;
        }

        int rect = getTop(&Stack);
        pop(&Stack);
        printf("%d个台阶，共有%d种走法.\n", numberOfStep, rect);
    }
    {
        int step1 = 1, step2 = 2, step3 = 4;
        int curStep = 4;
        int numberOfStep = 0;
        printf("请输入台阶的个数: ");
        scanf("%d", &numberOfStep);

        int rect = 0;
        for(int i = 4; i <= numberOfStep; i++)
        {
            rect = step1 + step2 + step3;
            step1= step2;
            step2 = step3;
            step3 = rect;
        }
        printf("%d个台阶，共有%d种走法.\n", numberOfStep, rect);
    }

    return 0;
}