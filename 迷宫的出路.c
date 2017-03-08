//
// Created by apple on 2017/3/7.
//
#include <stdio.h>
#include <time.h>
#include <memory.h>
#include <stdbool.h>
#include <stdlib.h>

#define N 10

_Bool isfind = false;

static _Bool GetOut(int ***pppx, int scale, int xpos, int ypos);
static void showMaze(int **ppx, int scale);

int main迷宫的动态分配内存的实现(int argc, char *argv[])
{
    {
        //迷宫
//        srand(time(NULL));
//        printf("请输入迷宫的维度: ");
//        int scale = 0;
//        scanf("%d", &scale);
//        printf("请输入迷宫的入口坐标: ");
//        int start = 0;
//        scanf("%d", &start);
//        printf("请输入迷宫的出口坐标: ");
//        int end = 0;
//        scanf("%d", &end);
//        printf("你输入的迷宫的维度是 %d， 是一个%d * %d的二维数组\n", N, N, N);
//        printf("并且，你输入的迷宫的入口坐标是: (%d, %d), 出口坐标是: (%d, %d)\n", start, start, end, end);


        srand(time(NULL));
        //1. 初始化二维数组
        int **ppx = (int **)malloc(N * sizeof(int *));

        for(int i = 0; i < N; i++)
        {
            ppx[i] = (int *)malloc(N * sizeof(int));
            for(int j = 0; j < N; j++)
            {
                int temp = rand() % 1000;

                if((i == 0 || i == 9) && (j == 0 || j == 9))
                {
                    ppx[i][j] = 0;
                }
                else
                {
                    if(temp % 2 != 0 && temp < 500 )
                    {
                        ppx[i][j] = 2;
                    }
                    else
                    {
                        ppx[i][j] = 0;
                    }
                }
            }
        }

        //显示迷宫
        showMaze(ppx, N);

        //找到出路
        int xpos = 0;
        int ypos = 0;


        _Bool brect = GetOut(&ppx, N, xpos, ypos);
        if(brect)
        {
            printf("迷宫是有出路的\n");
        }
        else
        {
            printf("抱歉！！！没有找到出路哦\n");
        }

    }
    return 0;
}

static _Bool GetOut(int ***pppx, int scale, int xpos, int ypos)
{
    (*pppx)[xpos][ypos] = 3;
    showMaze(*pppx, scale);

    if(xpos == 9 && ypos == 9)
    {
        printf("终于找到出路呢!!!\n");
        isfind = true;
    }
    else
    {
        //右
        if(ypos + 1 < scale && (*pppx)[xpos][ypos + 1] < 2 && !isfind)
        {
            GetOut(pppx, scale, xpos, ypos + 1);
        }
        //下
        if(xpos + 1 < scale && (*pppx)[xpos + 1][ypos] < 2 && !isfind)
        {
            GetOut(pppx, scale, xpos + 1, ypos);
        }
        //上
        if(xpos - 1 >= 0 && (*pppx)[xpos - 1][ypos] < 2 && !isfind)
        {
            GetOut(pppx, scale, xpos - 1, ypos);
        }
        //左
        if(ypos - 1 >= 0 && (*pppx)[xpos][ypos - 1] < 2 && !isfind)
        {
            GetOut(pppx, scale, xpos, ypos - 1);
        }
    }

    return isfind;
}

static void showMaze(int **ppx, int scale)
{
    for(int i = 0; i < scale; i++)
    {
        for(int j = 0; j < scale; j++)
        {
            printf("%4d", ppx[i][j]);
        }
        printf("\n");
    }
    printf("===========================================\n");
}

