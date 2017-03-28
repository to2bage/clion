//
// Created by apple on 2017/3/27.
//

#ifndef CLION_MYSTRING_H
#define CLION_MYSTRING_H

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <locale.h>
#include <wchar.h>

struct stringA
{
    char *pa;
    int memlength;     //字符串的内存长度
};
typedef struct stringA StrA;

struct stringW
{
    wchar_t  *pw;
    int memlength;
};
typedef struct stringW StrW;

void initStr(void *p, char ch);     //ch=a窄字符；ch=w宽字符
void initStrWithStr(void *p, char ch, void *pstr);


void showMyStr(void *p, char ch);

#endif //CLION_MYSTRING_H
