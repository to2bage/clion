//
// Created by apple on 2017/3/2.
//
// 队列是从head这边入队， 从back这边出队
// head始终指向数组的第一个元素， back指向数组最后一个有效元素的下一个位置

#include "队列.h"

//初始化队列
void initQueue(Queue *pQueue)
{
    pQueue->head = pQueue->back = 0; //head始终指向索引为0的数组元素，back指向最后一个元素的下一个位置
    memset(pQueue->data, 0, sizeof(int) * N);
}
//队列是否为空
_Bool isEmptyOfQueue(Queue *pQueue)
{
    return pQueue->head == pQueue->back ? true : false;
}
//队列是否为满
_Bool isFullOfQueue(Queue *pQueue)
{
    return pQueue->back == N - 1 ? true : false;
}
//入队
void enQueue(Queue *pQueue, int key)
{
    //!isFullOfQueue(pQueue) ? pQueue->data[pQueue->back] = key, pQueue->back++ : printf("队列已满，不能入队\n");
    if(isFullOfQueue(pQueue))
    {
        printf("队列已满， 不能入队!!!\n");
    }
    else
    {
        if(isEmptyOfQueue(pQueue))
        {
            //队列为空
            pQueue->data[pQueue->back] = key;
            pQueue->back++;
        }
        else
        {
            //队列不为空
            //移动数组
            for(int i =  pQueue->back - 1; i >= pQueue->head; i--)
            {
                pQueue->data[i + 1] = pQueue->data[i];
            }
            pQueue->back++;
            pQueue->data[pQueue->head] = key;
        }
    }
}
//获取出队的数据
int getLast(Queue *pQueue)
{

    return !isEmptyOfQueue(pQueue) ? pQueue->data[pQueue->back - 1] : -1;

}
//出队
void deQueue(Queue *pQueue)
{
    if(!isEmptyOfQueue(pQueue))
    {
        pQueue->back--;
    }
}
//显示
void showQueue(Queue *pQueue)
{
    //pQueue->back指向数组最后一个元素的想一个位置
    for(int i = pQueue->head; i < pQueue->back; i++)
    {
        printf("%5d", pQueue->data[i]);
    }
    printf("\n");
}