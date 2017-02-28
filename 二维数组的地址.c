//
// Created by apple on 2017/2/28.
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main二维数组的操作(int argc, char* argv[])
{
    {
        srand(time(NULL));

        int a[3][4] = {0};
        for(int i = 0; i < 3; i++)
        {
            for(int j = 0; j < 4; j++)
            {
                printf("%5d(%p)", a[i][j] = rand() % 300, &a[i][j]);
            }
            printf("\n");
        }

        printf("二维数组&a[1][2]的地址是: %p\n", a[1] + 2);
    }
    {
        //方阵
        /*
         *  1   2   3
         *  4   5   6
         *  7   8   9
         * */
#define N 10
        int a[N][N] = {0};
        for(int i = 0; i < N; i++)
        {
            for(int j = 0; j < N; j++)
            {
                printf("%5d", a[i][j] = N * i + 1 + j);
            }
            printf("\n");
        }

        int sum = 0;
        //求正对角线 i = j;
//        for(int i = 0; i < N; i++)
//        {
//            for(int j = 0; j < N; j++)
//            {
//                if(i == j)
//                {
//                    sum += a[i][j];
//                    break;
//                }
//            }
//        }
        for(int i = 0; i < N; i++)
        {
            sum += a[i][i];
        }
        printf("正对角线的元素之和是: %d\n", sum);
        //求反对角线 i + j = N - 1;
        sum = 0;
        for(int i = 0; i < N; i++)
        {
            sum += a[i][N - 1 - i];
        }
        printf("反对角线的元素之和是: %d\n", sum);
    }
    {
        //矩阵的转置
        /*
         * 矩阵的顺时针旋转
         *
         *  1   2  3  4            9  5  1
         *  5   6  7  8      =>   10  6  2
         *  9  10 11 12           11  7  3
         *                        12  8  4
         *
         * */
        int a[3][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
        int b[4][3] = {0};

        for(int i = 0; i < 3; i++)
        {
            for(int j = 0; j < 4; j++)
            {
               b[j][2 - i] = a[i][j]; //原来的行索引最大值2 减去原来行的索引 得到现在行的索引
            }
        }
        //print b
        for(int i = 0; i < 4; i++)
        {
            for(int j = 0; j < 3; j++)
            {
                printf("%5d", b[i][j]);
            }
            printf("\n");
        }
        printf("\n");

        /*
         * 矩阵的逆时针旋转
         *
         *  1   2  3  4            4  8  12
         *  5   6  7  8      =>    3  7  11
         *  9  10 11 12            2  6  10
         *                         1  5   9
         *
         * */
        for(int i = 0; i < 3; i++)
        {
            for(int j = 0; j < 4; j++)
            {
                b[3 - j][i] = a[i][j];
            }
        }
        for(int i = 0; i < 4; i++)
        {
            for(int j = 0; j < 3; j++)
            {
               printf("%5d", b[i][j]);
            }
            printf("\n");
        }
        printf("\n");
    }

    return 0;
}


