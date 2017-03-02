//
// Created by apple on 2017/3/1.
//
#include "myStack.h"
#include <memory.h>
#include <stdio.h>

void initStack(MyStack *pStack)    //初始化栈，清空栈
{
    pStack->top = -1;
    memset(pStack->data, 0, sizeof(pStack->data)); //清除数组中元素(0)
}

_Bool isEmpty(MyStack *pStack)  //判断栈是否为空
{
    return pStack->top == -1 ? true : false;
}

_Bool isFull(MyStack *pStack)  //判断栈是否已满
{
    return pStack->top == sizeof(pStack->data) / sizeof(int) - 1 ? true : false;
}

int getTop(MyStack *pStack)    //获取栈顶元素
{
    int rect = 0;
    !isEmpty(pStack) ? (rect = pStack->data[pStack->top]) : (rect = -1);
    return rect;
}

void push(MyStack *pStack, int key)     //入栈
{
    !isFull(pStack) ? (pStack->top++, pStack->data[pStack->top] = key) : (printf("栈已满！！！\n"));
}

void pop(MyStack *pStack)      //出栈
{
    !isEmpty(pStack) ? (pStack->top--) : (printf("栈是空的...\n"));
}

void showStack(MyStack *pStack)    //显示栈
{
    if(isEmpty(pStack))
    {
        printf("当前栈为空!!!\n");
    }
    else
    {
        for(int i = 0; i <= pStack->top; i++)
        {
            printf("%4d", pStack->data[i]);
        }
        printf("\n");
    }
}
