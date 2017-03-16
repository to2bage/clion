//
// Created by apple on 2017/3/16.
//
#include <stdio.h>
#include <locale.h>
#include <stddef.h>
#include <wchar.h>
#include <string.h>

static int mywcslen(wchar_t *pwstr)
{
    int len = 0;
    while(*pwstr != L'\0')
    {
        pwstr++;
        len++;
    }
    return len;
}

static wchar_t *mywcscpy(wchar_t *pwdest, const wchar_t *pwsrc)
{
    wchar_t *pwx = pwdest;
    while((*pwx++ = *pwsrc++));
    return pwdest;
}

int main宽字符字符串(int argc, char* argv[])
{
    {
        //宽字符
        setlocale(LC_ALL, "zh_CN");     //注意这里是zh_CN
        wchar_t wch = L'我';
        putwchar(wch);
        printf("\n");
    }
    {
        //宽字符串
        wchar_t wch[10] = L"我是男生，爱女神";

        //int length = wcslen(wch);
        int length = mywcslen(wch);
        printf("%d\n", length); //8个字符
    }
    {
        //输出宽字符串
        setlocale(LC_ALL, "zh_CN.UTF-8");
        wchar_t wch[10] = L"我是男生，爱女神";
        wprintf(L"%ls\n", wch);
    }
    {
        //宽窄字符的ASCII码是一样的
        wchar_t wch = L'A';
        char ch = 'A';
        printf("%d, %d\n", wch, ch);    //65, 65
    }
    {
        //宽字符串的拷贝函数
        setlocale(LC_ALL, "zh_CN");
        wchar_t wch[100] = L"我是混蛋，蛤蛤蛤";
        wchar_t *pwstr = (wchar_t[100]){0};
        //wcscpy(pwstr, wch);
        mywcscpy(pwstr, wch);
        wprintf(L"%ls\n", pwstr);
    }


    return 0;
}
