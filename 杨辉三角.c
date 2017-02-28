//
// Created by apple on 2017/2/27.
//
#include <stdio.h>

static void yanghuiAngle(int (*px)[5], int rows)
{
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < rows; j++)
        {
            if((i == 0 && j == 0) || (i == 1 && j == 1) || (i == 1 && j == 0))
            {
                printf("%4d", px[i][j]);
            }
            else if(i >= j)
            {
                if(j == 0 || i == j)
                {
                    printf("%4d", 1);
                    px[i][j] = 1;
                }
                else
                {
                    printf("%4d", px[i - 1][j] + px[i - 1][j - 1]);
                    px[i][j] = px[i - 1][j] + px[i - 1][j - 1];
                }

            }
            else
            {
                printf("");
            }
        }
        printf("\n");
    }
}

static void yanghuiAngleStar(int (*px)[5], int rows)
{
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < rows; j++)
        {
            if((i == 0 && j == 0) || (i == 1 && j == 1) || (i == 1 && j == 0))
            {
                printf("%4*d", 30 - i * 2, px[i][j]);
            }
            else if(i >= j)
            {
                if(j == 0 || i == j)
                {
                    printf("%4*d", 30 - i * 2, 1);
                    px[i][j] = 1;
                }
                else
                {
                    printf("%4*d", 30 - i * 2, px[i - 1][j] + px[i - 1][j - 1]);
                    px[i][j] = px[i - 1][j] + px[i - 1][j - 1];
                }

            }
            else
            {
                printf("");
            }
        }
        printf("\n");
    }
}

int main杨辉三角(int argc, char* argv[])
{
    {
        //杨辉三角
        int a[10][10] = {0};
        a[0][0] = a[1][0] = a[1][1] = 1;
        yanghuiAngleStar(a, 10);
    }


    return 0;
}
