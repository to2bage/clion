//
// Created by apple on 2017/2/28.
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main二维数组的地址(int argc, char* argv[])
{
    printf("Content-type:text/html\n\n");
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
    {
        //输出二维数组的方法
        int a[3][5] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};

        for(int *p = &a[0][0]; p < &a[0][0] + 15; p++)
        {
            printf("%4d", *p);

        }
        printf("\n");
        for(int *p = *a; p < *a + 15; p++)
        {
            printf("%4d", *p);
        }
        printf("\n");
        for(int i = 0; i < 15; i++)
        {
            printf("%4d", a[i / 5][i % 5]);
        }
        printf("\n");
    }
    {
        //一维数组和二维数组的类型
        int b[5];
        int *p1 = b;
        int (*p2)[5] = &b;


        int a[3][5] = {0};
        //int **pp = a;   //类型不匹配
        //pp + 1是前进4个字节（pp指向的是int*类型）； 而a + 1是前进20个字节
        int (*p)[5] = a; //正确的
        int *px = *a; //正确的, *a一次前进4个字节
        int (*py)[3][5] = &a; //正确，
    }
    {
        //二维数组的行地址和列地址
        int a[3][5] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
        for(int i = 0; i < 3; i++)
        {
            for(int j = 0; j < 5; j++)
            {
                printf("%5d(%p)", a[i][j], &a[i][j]);
            }
            printf("\n");
        }

        //打印二维数组的行地址
        for(int i = 0; i < 3; i++)
        {
            printf("%p, %p\n", a + i, &a[i]);
        }
        printf("\n");
        //打印第一行每一列的地址
        for(int i = 0; i < 5; i++)
        {
            //a是行指针，步长是一行的长度； *a的步长是一个元素的长度
            printf("%p, %p\n", *(a + 0) + i, a[0] + i);
        }
    }

    return 0;
}


