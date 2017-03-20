//
// Created by apple on 2017/3/20.
//
#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[])
{
    char str1[100] = "trump love money";
    char str2[50] = "USA than";

    {
        char *pstart = strstr(str1, "love");
        char *pend = str1 + strlen(str1);

        if(!pstart)
        {
            return -1;
        }
        pstart += strlen("love ");

        int str2len = strlen(str2);
        //后移
        for(;pend >= pstart; pend--)
        {
            *(pend + str2len + 1) = *pend;
        }

        //拷贝
        char *px = str2;
        while(*px != '\0' && (*pstart++ = *px++));


        printf("size = %lu\n", strlen(str1));
        printf("%s\n", str1);

    }

    return 0;
}

