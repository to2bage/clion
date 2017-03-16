//
// Created by apple on 2017/3/16.
//
#include <stdio.h>
#include <string.h>

static int execShell(char *pcmd, char *rect)
{
    FILE *pfr = popen(pcmd, "r");
    if(pfr == NULL)
    {
        printf("读取命令行结果失败!!!\n");
        return -1;
    }

    while(!feof(pfr))
    {
        char str[256] = {0};
        if(fgets(str, 256, pfr))
        {
            //printf("%s\n", str);
            strcat(rect, str);
            //printf("%s\n", rect);
        }
    }

    //printf("%s\n", rect);
    pclose(pfr);
    return 0;
}

int main管道(int argc, char* argv[])
{
    char str[1024 * 800] = {0};
    char *cmd = "find /Users/apple/Desktop/clion -type f";
    if(execShell(cmd, str) == 0)
    {
        printf("%s\n", str);
    }
    printf("\n");


    return 0;
}
