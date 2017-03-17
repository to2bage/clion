//
// Created by apple on 2017/3/17.
//
#include <stdio.h>
#include <stdbool.h>

//删除所有的指定字符
static void deleChar(char *pstr, char ch)
{
    char *p1 = pstr;
    char *p2 = pstr;

    while((*p1 = *p2))
    {
        if(*p2 == ch)
        {
            p2++;
        }
        else
        {
            p1++;
            p2++;
        }
    }
}

//删除所有的指定字符串
static void deleStr(char *pstr, char *substr)
{
    char *p1 = pstr;
    char *p2 = pstr;

    while((*p1 = *p2))
    {
        char *p3 = substr;
        _Bool isfind = true;
        while(*p3 != '\0')
        {
            if(*p2 != *p3)
            {
                isfind = false;
                break;
            }
            p3++;
            p2++;
        }
        if(isfind)
        {
            p2++;
        }
        else
        {
            p2 = p1;    //注意：没有找到需要删除的字符串,必须把p2回到p1的位置
            p1++;
            p2++;
        }
    }
}



int main字符串删除(int argc, char *argv[])
{
    {
        //删除字符串中所有的字符i
        char str[1024] = "i love china i love you i love money i love girl";
        printf("源字符串:%s\n", str);
        deleChar(str, 'i');
        printf("删除后的字符串:%s\n\n", str);
    }
    {
        //删除字符串中所有的字符串love
        char str[1024] = "i loeve china i love you i love money i love girl";
        printf("源字符串:%s\n", str);
        deleStr(str, "love");
        printf("删除后的字符串:%s\n\n", str);
    }

    return 0;
}
