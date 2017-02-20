//
// Created by apple on 2017/2/16.
//
#include <stdio.h>
#include <memory.h>
#include <stdlib.h>

int main查找进程(int argc, char* argv[])
{
    //将命令的结果写入文件
//    char cmd[100] = {0};
//    char cmd1[1024] = {0};
//    scanf("%[^\n]", cmd);
//    sprintf(cmd1, "%s > /Users/apple/Desktop/clion/cmake-build-debug/ps.txt", cmd);
//    printf("你输入的命令是： %s\n", cmd1);
//    system(cmd1);

    //从文件中读入内容到字符串
    char str[4096] = {0};
    scanf("%[^\n]", str);
    printf("%s\n", str);

//    char findstr[100] = {0};
//    printf("请输入要查找的进程名称:");
//    scanf("%s", findstr);
//
//    char *px = strstr(str, findstr);
//    if (px)
//    {
//
//    }
//    else
//    {
//        printf("当前进程%s不存在\n", findstr);
//    }
}
