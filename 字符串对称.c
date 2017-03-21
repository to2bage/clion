//
// Created by apple on 2017/3/21.
//
#include <stdio.h>
#include <stdbool.h>

static _Bool isBalance(char *pstart, char *pend)
{
    if(pstart == pend)
    {
        return true;
    }
    else if(pstart + 1 == pend)
    {
        return *(pstart + 1) == *pend;
    }
    else
    {
        return (*pstart == *pend) && isBalance(pstart + 1, pend - 1);
    }
}

int main字符串对称判断(int argc, char *argv[])
{
    char str[1024] = "";
    int length = 0;
    scanf("%s%n", str, &length);

    _Bool brect = isBalance(str, str + length - 1);
    if(brect)
    {
        printf("字符串是对称的\n");
    }
    else
    {
        printf("字符串不是对称的\n");
    }

    return 0;
}
