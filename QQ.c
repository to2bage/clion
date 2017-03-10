//
// Created by apple on 2017/3/9.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

static char **g_pp;
static int rowsOfQQ = 40000000;  //文件有多少行 84313498
static unsigned long widthOfRow = 51;      //最大的行宽

static unsigned long getWidthOfRow()
{
    unsigned long width = 0;

    FILE *pfr = fopen("/Volumes/Samsung_T3/test/qqGood.txt", "r");
    if(pfr == NULL)
    {
        printf("文件打开错误!!!\n");
        return -1;
    }

    while(!feof(pfr))
    {
        char str[1024] = {0};
        fgets(str, 1023, pfr);
        unsigned long temp = strlen(str);
        width = temp > width ? temp : width;
    }

    fclose(pfr);
    return width;
}

static int getRowsOfQQ()
{
    int rows = 0;
    FILE *pfr = fopen("/Volumes/Samsung_T3/test/qqGood.txt", "r");
    if(pfr == NULL)
    {
        printf("文件打开错误!!!\n");
        return -1;
    }

    while(!feof(pfr))
    {
        char str[1024] = {0};
        fgets(str, 1023, pfr);
        rows++;
    }

    fclose(pfr);
    return rows;
}

static void loadfileToMem()
{
    printf("开始分配内存......\n");
    g_pp = (char **)calloc((size_t)rowsOfQQ, sizeof(char *));
    if(g_pp == NULL)
    {
        printf("分配内存失败\n");
        return;
    }

    FILE *pfr = fopen("/Volumes/Samsung_T3/test/qqGood.txt", "r");
    if(pfr == NULL)
    {
        printf("打开文件失败!!!\n");
        free(g_pp);
        return;
    }
    printf("开始装载文件......\n");
    for(int i = 0; i < rowsOfQQ; i++)
    {
        char str[52] = {0};
        fgets(str, 51, pfr);
        unsigned long len = strlen(str) + 1;

        g_pp[i] = (char*)calloc(len, sizeof(char));
        strcpy(g_pp[i], str);
    }

    fclose(pfr);
    printf("文件装入内存完成!!!!!\n");
    return;
}

static void searchMem(char *pstr)
{
    if(pstr == NULL)
    {
        printf("请输入查询字符串!!!\n");
        return;
    }

    for(int i = 0; i < rowsOfQQ; i++)
    {
//        if(strcmp(g_pp[i], pstr) == 0)
//        {
//            printf("查询到的内容是： %s\n", g_pp[i]);
//            break;
//        }
        char *px = strstr(g_pp[i], pstr);
        if(px)
        {
            printf("%s\n", g_pp[i]);
        }
    }
}

int mainQQ(int argc, char* argv[])
{
    //printf("共有%d行\n", getRowsOfQQ());
    //printf("最宽的行有%lu个字节\n", getWidthOfRow());
    loadfileToMem();

    while (1)
    {
        printf("输入要查找的内容: ");
        char searchStr[100] = {0};
        scanf("%s", searchStr);

        searchMem(searchStr);
    }

    return 0;
}
