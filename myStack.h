//
// Created by apple on 2017/3/1.
//

#ifndef CLION_MYSTACK_H
#define CLION_MYSTACK_H

#include <stdbool.h>

#define N 100

struct myStack
{
    int data[N];
    int top;    //标识栈顶, 在数组data中的索引
};

typedef struct myStack MyStack;

void initStack(MyStack *pStack);    //初始化栈，清空栈
_Bool isEmpty(MyStack *pStack);  //判断栈是否为空
_Bool isFull(MyStack *pStack);  //判断栈是否已满
int getTop(MyStack *pStack);    //获取栈顶元素
void push(MyStack *pStack, int key);     //入栈
void pop(MyStack *pStack);      //出栈
void showStack(MyStack *pStack);    //显示栈

#endif //CLION_MYSTACK_H
