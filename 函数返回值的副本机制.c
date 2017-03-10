//
// Created by apple on 2017/3/9.
//
#include <stdio.h>
#include <string.h>

char* get();

int main函数的返回值(int argc, char* argv[])
{
    {
        char str[100] = {0};
        strcpy(str, "hello nimabi");
        printf("%s\n", str);
    }
    {
        char *pstr = get();
        printf("%s\n", pstr);   //error
    }
    {
        //函数的返回值 在cpu的缓存中，因此不能取地址
    }

    return 0;
}

char* get()
{
    char str[100] = {0};
    strcpy(str, "hello nimabi");
    return str;
}