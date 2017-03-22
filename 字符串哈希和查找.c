//
// Created by apple on 2017/3/21.
//
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

static char getOnce(char *pstr)
{
    char *p1 = pstr;
    char *p2 = pstr;
    int num = 0;


    while(*p1 != '\0')
    {
        num = 0;
        char *p3 = p1;
        while(*p2 != '\0')
        {
            if(*p2 == *p3)
            {
                num++;
            }
            p2++;
        }

        if(num == 1)
        {
            return *p3;
        }
        else
        {
            p1++;
            p2 = pstr;
        }
    }
    return 0;
}

static char getOnceByHash(char *pstr)
{
    //建立哈希表
    int hashtable[256] = {0};   //因为字符最多只有256个

    //给哈希表赋值
    while(*pstr != '\0')
    {
        hashtable[*pstr++]++;
    }

    for(int i = 0; i < 256; i++)
    {
        if(hashtable[i] == 1)
        {
            return (char)i;
        }
    }

    return 0;
}

int main字符串哈希查找(int argc, char* argv[])
{
    {
        //字符串中仅仅出现一次的字符
        char str[100] = "abcdfacvg";
        putchar(getOnce(str));
        putchar(getOnceByHash(str));
    }
    {
        //字符串的哈希
    }

    return 0;
}
