//
// Created by apple on 2017/2/16.
//
#include <stdio.h>
#include <wchar.h> //处理宽字符函数的头文件
#include <locale.h>

int main宽字符(int argc, char* argv[])
{
    {
        // linux下： 中文窄字符占3个字节，英文窄字符占1个字节；中文宽字符和英文宽字符都占4个字节
        //Windows下：中文窄字符占2个字节，英文窄字符占1个字节；中文宽字符和英文宽字符都占2个字节
//        printf(L"%ls\n", L"你好天朝");
        wprintf(L"%ls\n", L"你好天朝"); //没有本地化，所以不会有输出
        printf("%lu\n", sizeof("1我")); // 5 = 1字节 + 3个字节 + 1个字节；
        printf("%lu\n", sizeof(L"1我")); // 12 = 3 * 4个字节
    }
    {
        char str[10] = "我";
        printf("%s\n", str);
        printf("%c%c%c\n", str[0], str[1], str[2]); //中文窄字符占3个字节， 不能被当作一个字符处理

        wchar_t  wstr[10] = L"1234我是色狼";    //没有本地化，输出1234
        wprintf(L"%ls\n", wstr);
        printf("\n");
    }
    {
        // 本地化
        setlocale(LC_ALL, "zh-CN");
        wchar_t wstr[100] = L"abcdefg我是色狼";
        wprintf(L"%ls\n", wstr);
    }
    {
        //宽，窄字符的ascii码是不会改变的，只是占用内存的大小是不同的
    }

    return 0;
}
