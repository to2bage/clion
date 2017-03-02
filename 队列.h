//
// Created by apple on 2017/3/2.
//

#ifndef CLION_队列_H
#define CLION_队列_H

#include <stdio.h>
#include <stdbool.h>
#include <memory.h>

#define N 100   //队列的长度

struct queue
{
    int data[N];
    int head;   //数据开头
    int back;   //数据结尾
};

typedef struct queue Queue; //简写

//初始化队列
void initQueue(Queue *pQueue);
//队列是否为空
_Bool isEmptyOfQueue(Queue *pQueue);
//队列是否为满
_Bool isFullOfQueue(Queue *pQueue);
//入队
void enQueue(Queue *pQueue, int key);
//获取出队的数据
int getLast(Queue *pQueue);
//出队
void deQueue(Queue *pQueue);
//显示
void showQueue(Queue *pQueue);

#endif //CLION_队列_H
