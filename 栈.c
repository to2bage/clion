//
// Created by apple on 2017/3/1.
//
#include <stdio.h>
#include "myStack.h"
#include <time.h>
#include <stdlib.h>

//结构体
struct MyStruct
{
    int a[10];
    int i;
};


int main栈(int argc, char*argv[])
{
    {
        //结构体初步
        struct MyStruct my1 = {{1, 2, 3, 4, 5, 6}, 109};
        printf("%d\n", my1.i);
        for(int i = 0; i < sizeof(my1.a)/ sizeof(int); i++)
        {
            printf("%5d", my1.a[i]);
        }
        printf("\n");
    }
    {
        //栈myStack
        srand(time(NULL));

        struct myStack Stack;
        int a[10] = {1,2,3,4,5,6,7,8,9,10};
        initStack(&Stack);
        for(int i = 0; i < 20; i++)
        {
            push(&Stack, i);
        }
        showStack(&Stack);
        while(!isEmpty(&Stack))
        {
            printf("%4d", getTop(&Stack));
            pop(&Stack);
        }
        printf("\n");
    }
    {
        //栈模拟递归 :10进制转2进制
        int num = 0;
        printf("请输入要转换为二进制的数字: ");
        scanf("%d", &num);

        struct myStack MyStack;
        initStack(&MyStack);
        while(num)
        {
            push(&MyStack, num % 2);
            num /= 2;
        }

        while(!isEmpty(&MyStack))
        {
            printf("%d", getTop(&MyStack));
            pop(&MyStack);
        }
    }

    return 0;
}
