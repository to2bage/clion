//
// Created by apple on 2017/3/1.
//
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

#define N 10

static void showSnake(int (*px)[N], int rows)
{
    for(int i = 0; i < N * N; i++)
    {
        printf("%5d", px[i / N][i % N]);
        (i + 1) % N == 0 ? printf("\n") : printf("");
    }
    printf("\n");
}

int main蛇和大数乘法(int argc, char* argv[])
{
    {
        //蛇
        int count = N;
//        printf("请输入方形矩阵的维度: ");
//        scanf("%d", &count);

        int cengshu = count % 2 == 0 ? count / 2 : (count + 1) / 2;
        int step = 0;
        int snake[N][N] = {0};

        int row, col;
        row = col = 0;
        int num = 1;

        int ceng = 0;

        while(ceng <= cengshu)
        {
//            {
//                //这是一层的数据
//                //第一行，从左至右
//                while(col < N)
//                {
//                    snake[row][col] = num;
//                    col++;
//                    num++;
//                }
//                col--;
//                row++;
//                //改变方向了， 从第二行开始，从上至下
//                while(row < N)
//                {
//                    snake[row][col] = num;
//                    row++;
//                    num++;
//                }
//                row--;
//                col--;
//                //改变方向了，从倒数第二列开始，从右至左
//                while(col >= 0)
//                {
//                    snake[row][col] = num;
//                    col--;
//                    num++;
//                }
//                col++;
//                row--;
//                //改变方向，从倒数第二行开始， 从下至上
//                while(row >= 1)                         //1 在这里表示层数,即第一层完了
//                {
//                    snake[row][col] = num;
//                    row--;
//                    num++;
//                }
//                row++;
//                col++;
//            }
            {
                {
                    //这是一层的数据
                    //第一行，从左至右
                    while(col < N - ceng)
                    {
                        snake[row][col] = num;
                        col++;
                        num++;
                    }
                    col--;
                    row++;
                    //改变方向了， 从第二行开始，从上至下
                    while(row < N - ceng)
                    {
                        snake[row][col] = num;
                        row++;
                        num++;
                    }
                    row--;
                    col--;
                    //改变方向了，从倒数第二列开始，从右至左
                    while(col >= ceng)
                    {
                        snake[row][col] = num;
                        col--;
                        num++;
                    }
                    col++;
                    row--;
                    //改变方向，从倒数第二行开始， 从下至上
                    while(row >= ceng + 1)                         //1 在这里表示层数,即第一层完了
                    {
                        snake[row][col] = num;
                        row--;
                        num++;
                    }
                    row++;
                    col++;
                    //
                    ceng++;
                }
            }
        }

        //显示蛇矩阵
        showSnake(snake, N);
    }
    {
        //大数相乘
        char snum1[20] = {0};
        int num1Len = 0;
        char snum2[20] = {0};
        int num2Len = 0;
        printf("请输入乘法的两个数字: ");
        scanf("%s%n%s%n", snum1, &num1Len, snum2, &num2Len);
        num2Len = num2Len - num1Len - 1;
        printf("你输入的num1 = %s, 位数是%d; num2 = %s, 位数是%d\n", snum1, num1Len, snum2, num2Len);

        //
        int *prect = (int*)malloc(num1Len * num2Len * sizeof(int));
        if(prect == NULL)
        {
            printf("分配内存出错!!!\n");
            return -1;
        }
        memset(prect, 0, num1Len * num2Len * sizeof(int));  //初始化动态数组为0
        //
        char *pnum1 = snum1 + num1Len - 1;
        char *pnum2 = snum2 + num2Len - 1;
        int *px = prect + num1Len * num2Len - 1;
        int i = 1;
        while(pnum1 >= snum1)
        {
            while(pnum2 >= snum2)
            {
                int num1 =*pnum1 - '0';
                int num2 = *pnum2 - '0';
                int temp = num1 * num2;
                *px += temp;
                px--;
                pnum2--;
            }
            pnum1--;
            px = prect + num1Len * num2Len - 1 - i;
            i++;
            pnum2 = snum2 + num2Len - 1;
        }
        //
//        px = prect;
//        while(px < prect + num1Len * num2Len)
//        {
//            printf("%5d", *px++);
//        }
//        printf("\n");
        //
        px = prect + num1Len * num2Len - 1;
        int sum = 0;
        while(px >= prect)
        {
            sum += *px;
            *px = sum % 10;
            sum /= 10;
            px--;
        }
        //
        while(px < prect + num1Len * num2Len)
        {
            printf("%5d", *px++);
        }
        printf("\n");
    }
    //
    {
//        char snum1[20] = {0};
//        int numlen1 = 0;
//        scanf("%s%n", snum1, &numlen1);
//        printf("num1 = %s, numlen1 = %d\n", snum1, numlen1);
//
//        char snum2[20] = {0};
//        int numlen2 = 0;
//        scanf("%s%n", snum2, &numlen2);
//        printf("num2 = %s, numlen2 = %d\n", snum2, numlen2);
        //

//        char snum1[20] = {0};
//        int numlen1 = 0;
//        char snum2[20] = {0};
//        int numlen2 = 0;
//
//        scanf("%s%n%s%n", snum1, &numlen1, snum2, &numlen2);
//        printf("num1 = %s, numlen1 = %d\n", snum1, numlen1);
//
//
//        printf("num2 = %s, numlen2 = %d\n", snum2, numlen2 - numlen1 - 1);
    }

    return 0;
}
