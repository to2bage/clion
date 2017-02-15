//
// Created by apple on 2017/2/15.
//
#include <stdio.h>

int mainRex(int argc, char* argv[])
{
    {
//        char str[100] = {0};
//        int lenOfStr = 0;
//        scanf("%s%n", str, &lenOfStr);
//        printf("str = %s, 字符串的长度是%d\n", str, lenOfStr);
    }
    {
//        char str[100] = {0};
//        int lenOfStr = 0;
//        scanf("%[^\n]%n", str, &lenOfStr); //一直读取字符，直到\n停止
//        scanf("%[^=]%n", str, &lenOfStr); //一直读取字符，直到=停止
//        printf("str = %s, 字符串的长度是%d\n", str, lenOfStr);
    }
    {
        char str[100] = {0};
        int lenOfStr = 0;
        //scanf("%[1]%n", str, &lenOfStr);    //只接受1字符的输入，非1字符即刻停止
        scanf("%[A-Z]%n", str, &lenOfStr);    //只接受字符的输入，非1字符即刻停止

        printf("str = %s, 字符串的长度是%d\n", str, lenOfStr);
    }

    return 0;
}
