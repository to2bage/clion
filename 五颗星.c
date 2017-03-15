//
// Created by apple on 2017/3/14.
//
#include <stdio.h>
#include <stdlib.h>

static void show1star()
{
    int *p = (int *)calloc(10,sizeof(int));
    for(int i = 0; i < 10; i++)
    {
        printf("%4d", p[i] = i);
    }
    printf("\n");
    free(p);
}

static void show2star()
{
    int **pp = (int **)calloc(10, sizeof(int *));
    for(int i = 0; i < 10; i++)
    {
        pp[i] = (int *)calloc(10, sizeof(int));
        for(int j = 0; j < 10; j++)
        {
            printf("%4d", pp[i][j] = i * 10 + j);
        }
        printf("\n");
    }
    //

}

static void show3star()
{
    int ***ppp = (int ***)calloc(10, sizeof(int **));
    for(int i = 0; i < 10; i++)
    {
        ppp[i] = (int **)calloc(10, sizeof(int *));
        for(int j = 0; j < 10; j++)
        {
            ppp[i][j] = (int *)calloc(10, sizeof(int));
            for(int k = 0; k < 10; k++)
            {
                printf("%4d", ppp[i][j][k] = i * 100 + j * 10 + k);
            }
            printf("\n");
        }
        printf("\n\n");
    }
    printf("\n");
}

int mainStar(int argc, char* argv[])
{
    show3star();

    return 0;
}
