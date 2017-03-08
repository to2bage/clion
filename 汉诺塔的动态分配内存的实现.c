//
// Created by apple on 2017/3/7.
//
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

static void move(int ***pppx, int rows, int cols, char chsource, char chtarget);
static void showHanoi(int **ppx, int rows, int cols);
static void hanoi(int ***pppx, int rows, int cols, char A, char B, char C);

int mainhanuo(int argc, char* argv[])
{
    int rows = 0;
    printf("请输入汉诺塔的行数: ");
    scanf("%d", &rows);

    //动态创建二维数组
    int **ppx = (int **)malloc(rows * sizeof(int *));

    for(int i = 0; i < rows; i++)
    {
        ppx[i] = (int *)malloc(3 * sizeof(int));
        memset(ppx[i], 0, 3 * sizeof(int));
    }

    //赋值第一列的数据
    for(int i = 0; i < rows; i++)
    {
        ppx[rows - i - 1][0] = rows - i;
        if(rows - i <= 0)
        {
            break;
        }
    }
    showHanoi(ppx, rows, 3);

    //移动汉诺塔
    hanoi(&ppx, rows, 3, 'A', 'B', 'C');


    return 0;
}

static void move(int ***pppx, int rows, int cols, char chsource, char chtarget)
{
    //在源中(列)，查找第一个不为0的元素
    int isource = 0;
    while((*pppx)[isource++][chsource - 'A'] == 0)
    {

        if(isource >= rows)
        {
            break;
        }
    }
    isource--;
    printf("%d\n", isource);

    //在目的列中， 查找最后一个为0的元素
    int itarget = 0;
    while((*pppx)[itarget++][chtarget - 'A'] == 0)
    {

        if(itarget >= rows)
        {
            break;
        }
    }
    itarget -= 1;
    printf("%d\n", itarget);

    //交换
    int temp = (*pppx)[isource][chsource - 'A'];
    (*pppx)[isource][chsource - 'A'] = (*pppx)[itarget][chtarget - 'A'];
    (*pppx)[itarget][chtarget - 'A'] = temp;

    //显示二维数组
    showHanoi(*pppx, 3, cols);                      //这里的3，要和输入的rows一致
}

static void hanoi(int ***pppx, int rows, int cols, char A, char B, char C)
{
    if(rows == 1)
    {
        //printf("%c ==> %c\n", A, C);
        move(pppx, rows, cols, A, C);
    }
    else
    {
        hanoi(pppx, rows - 1, cols, A, C, B);
        //printf("%c ==> %c\n", A, C);
        move(pppx, rows, cols, A, C);
        hanoi(pppx, rows - 1, cols, B, A, C);
    }
}

static void showHanoi(int **ppx, int rows, int cols)
{
    printf("%10c%10c%10c\n", 'A', 'B', 'C');
    printf("======================================\n");
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            printf("%10d", ppx[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");
}

