//
// Created by apple on 2017/3/8.
//

#include <stdio.h>
#include <stdlib.h>

int main指针数组(int argc, char* argv[])
{
    {
        //"echo", "notepad", "tasklist", "mspaint", "find"位于代码区的常量符号表
        char *pstr[5] = {"echo", "notepad", "tasklist", "mspaint", "find"};
        char **ppstr = pstr;    //指针数组的数组名是二级指针类型
    }
    {
        //一维的动态数组
        int *p1 = (int *)malloc(20 * sizeof(int));
        for(int i = 0; i < 20; i++)
        {
            printf("%4d", p1[i] = i);
        }
        printf("\n\n");

        //二维的动态数组
        //3行5列   列数必须是明确的，行数才可以任何动态生成
        int (*p2)[5] = (int (*)[5])malloc(15 * sizeof(int));
        for(int i = 0; i < 15; i++)
        {
            printf("%4d", p2[i / 5][i % 5] = i);
            (i + 1) % 5 == 0 ? printf("\n") : printf("");
        }
        printf("\n\n");

        //锯齿状的二维数组, 分块数组
        int num = 0;
        int **pp = (int **)malloc(5 * sizeof(int*)); //20个字节
        for(int i = 0; i < 5; i++)
        {
            *(pp + i) = (int *)malloc((i + 1) * sizeof(int));
            for(int j = 0; j < i + 1; j++)
            {
                *(*(pp + i) + j) = num++;
            }
        }
        for(int i = 0; i < 5; i++)
        {
            for(int j = 0; j < i + 1; j++)
            {
                printf("%4d", *(*(pp + i) + j));
            }
            printf("\n");
        }
        printf("\n\n");
    }

    return 0;
}
