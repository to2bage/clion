//
// Created by apple on 2017/3/14.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int *increamArray(int *parr, int count)
{
    parr = (int *)realloc(parr, count * sizeof(int));
    return parr;
}

static void increamArrayBy(int **pparr, int count)
{
    *pparr = realloc(*pparr, count * sizeof(int));
}

static deleteData(int **ppa, int *plen, int delNum)
{
    int *p1 = *ppa;
    int *p2 = *ppa;
    int count = 0;

    while(p2 < *ppa + *plen)
    {
        if(*p2 != delNum)
        {
            *p1++ = *p2++;
        }
        else
        {
            p2++;
            count++;
        }
    }

    *plen -= count;
    *ppa = realloc(*ppa, (*plen) * sizeof(int));
}

int main内存动态分配实例
        (int argc, char* argv[])
{
    {
        int *p = (int *)calloc(25, sizeof(int));    //100个字节
        for(int i = 0; i < 25; i++)
        {

            printf("%4d", p[i] = i);
        }
        printf("\n");

        //p = increamArray(p, 26);
        increamArrayBy(&p, 26);

        for(int i = 0; i < 26; i++)
        {
            printf("%4d", p[i] = i);
        }
        printf("\n");
    }
    {
        //动态数组删除数据
        int *p = (int *)calloc(25, sizeof(int));
        for(int i = 0; i < 25; i++)
        {
            p[i] = i % 2 == 0 ? 4 : i;
            printf("%4d", p[i]);
        }
        printf("\n");

        int len = 25;
        deleteData(&p, &len, 4);

        for(int i = 0; i < len; i++)
        {
            printf("%4d", p[i]);
        }
        printf("\n");
    }
    {
        //
        unsigned int num = 0;
        printf("请输入字符串数组的个数:");
        scanf("%d", &num);
        char **ppstr = (char **)calloc(num, sizeof(char *));
        for(int i = 0; i < num; i++)
        {
            char str[1024] = {0};
            scanf("%s", str);
            ppstr[i] = (char *)calloc(strlen(str) + 1, sizeof(char));
            strcpy(ppstr[i], str);
        }

    }

    return 0;
}
