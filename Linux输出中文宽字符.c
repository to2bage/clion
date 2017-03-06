//
// Created by apple on 2017/3/6.
//
#include <stdio.h>
#include <stddef.h>
#include <wchar.h>
#include <locale.h>

int mainLinux输出中文宽字符(int argc, char* argv[])
{

    {
        setlocale(LC_ALL, "zh_CN.UTF-8");

        char ch = 'a';
        putchar(ch);
        putchar('\n');
        wchar_t wch = L'a';
        putwchar(wch);
        putwchar('\n');
        //1, 4
        printf("sizeof(char) = %lu, sizeof(wchar_t) = %lu\n", sizeof(char), sizeof(wchar_t));


        wchar_t gch = L'我';
        putwchar(gch);

        wchar_t strx[100] = L"你好天朝";
        wchar_t *pstrx = L"你好天朝";
        printf("sizeof(strx) = %lu\n", sizeof(strx)); //400
        printf("sizeof(L\"你好天朝\") = %lu\n", sizeof(L"你好天朝")); //20
        wprintf(L"strx = %ls\n", strx);
        wprintf(L"pstrx = %ls\n", pstrx);
        wprintf(L"output = %ls\n", L"你好天朝");
    }

    return 0;
}
