//
// Created by apple on 2017/3/13.
//
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

static int comp(const void *p1, const void *p2);
static void bubleSort(char **ppstr, int size);

unsigned long mystrlen(const char* pstr)
{
    unsigned long len = 0;
    const char *p = pstr;
    while(*p++ != '\0')
    {
        len++;
    }
    return len;
}

static char* mystrcpy(char *pdest, const char *psource)
{
    char *pd = pdest;
    const char *ps = psource;

    while((*pd++ = *ps++) != '\0');

    return pdest;
}

static char* mystrstr(const char* big, const char* litter)
{
    const char *pbig = big;

    while(*pbig != '\0')
    {
        _Bool isFind = true;
        const char *plitter = litter;
        const char *px = pbig;

        while(*px != '\0' && *plitter != '\0')
        {
            if(*px++ != *plitter++)
            {
                isFind = false;
                break;
            }
        }
        if(isFind)
        {
            return (char *)pbig;
        }
        else
        {
            pbig++;
        }
    }
    return NULL;
}

static int mystrcmp(const char *pstr1, const char *pstr2)
{
    while(*pstr1++ == *pstr2++ && *pstr1 != '\0' && *pstr2 != '\0');

    if(*pstr1 == '\0' && *pstr2 != '\0')
    {
        return -1;
    }
    if(*pstr2 == '\0' && *pstr1 != '\0')
    {
        return 1;
    }

    return *--pstr1 - *--pstr2;
}


int main字符串的常用函数(int argc, char*argv[])
{
    {
        //strlen 不包含\0
        char str[100] = "calc";
        unsigned long length = strlen(str);
        printf("%lu\n", length);
        printf("%lu\n", mystrlen(str));
    }
    {
        //strcpy
        char str[100] = {0};
        char *p = "你好天朝";
        char *prect = strcpy(str, p);
        printf("%s\n", str);
        printf("%s\n", prect);
        char str1[100] = {0};
        printf("%s\n", mystrcpy(str1, p));
        printf("str = %s\n", str1);
    }
    {
        //strstr
        char big[100] = "abcdefghijklmnopqrstuvwxyz";
        char litter[20] = "fghi";
        printf("%s\n", strstr(big, litter));
        printf("%s\n", mystrstr(big, litter));
    }
    {
        //strcmp
        char str1[100] = "hello world";
        char str2[100] = "hello world";
        printf("%d\n", strcmp(str1, str2));
        printf("%d\n", mystrcmp(str1, str2));
    }
    {
        //字符串数组的排序
        char *pstr[10] = (char*[]){"notepad", "hello", "echo", "edit", "help", "world", "run", "view", "abs", "file"};
        //qsort(pstr, 10, sizeof(char *), comp);
        bubleSort(pstr, 10);
        for(int i = 0; i < 10; i++)
        {
            printf("%s ", pstr[i]);
        }
        printf("\n");
    }

    return 0;
}

static int comp(const void *p1, const void *p2)    //传递的是数组元素的地址
{
    char **ppstr1 = (char **)p1;  //也就是字符串hello的地址，char*的地址，使用二级指针char**来接受
    char **ppstr2 = (char **)p2;

//    return strcmp(*ppstr1, *ppstr2);
    return mystrcmp(*ppstr1, *ppstr2);
}

static void bubleSort(char **ppstr, int size)
{
    for(int i = 0; i < size - 1; i++)
    {
        for(int j = 0; j < size - i - 1; j++)
        {
            if(mystrcmp(ppstr[j], ppstr[j + 1]) >= 0)
            {
                //交换的是地址
                char *ptemp = ppstr[j];
                ppstr[j] = ppstr[j + 1];
                ppstr[j + 1] = ptemp;
            }
        }
    }
}