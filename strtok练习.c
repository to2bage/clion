//
// Created by apple on 2017/3/17.
//
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

static char* mystrtok(char *pstr, char *split)
{
    char *px = pstr;
    _Bool isfind = true;
    while(*px != '\0')
    {
        char *p1 = px;
        char *p2 = split;
        isfind = true;
        while(*p2 != '\0')
        {
            if(*p2 != *p1)
            {
                isfind = false;
                break;
            }
            p2++;
            p1++;
        }
        if(isfind)
        {
            //px指向字符串split在字符串pstr中开始的位置
            *px = '\0';
            break;
        }
        else
        {
            px++;
        }
    }
    if(isfind)      //找到了
    {
        return pstr;
    }
    return NULL;    //没有找到就返回NULL
}

int mainstrtok(int argc, char* argv[])
{
    {
        char str[100] = "123,qwr,hello,wrod";
//        char *px = strtok(str, ",");
//        printf("%s\n", px);

        for(char *px = strtok(str, ","); px != NULL; px = strtok(px + strlen(px) + strlen(","), ","))
        {
            printf("%s\n", px);
        }
        printf("\n");

        char str1[100] = "nihao hello one hello two hello three";
//        char *px = mystrtok(str1, "hello");
//        printf("%s\n", px);
        for(char *px = mystrtok(str1, "hello"); px != NULL; px = mystrtok(px + strlen(px) + strlen("hello"), "hello"))
        {
            printf("%s\n", px);
        }
        printf("\n");
    }

    return 0;
}
