//
// Created by apple on 2017/3/16.
//
#include <stdio.h>
#include <string.h>
#include <memory.h>
#include <stdlib.h>

static void mystrcpy(char *pdest, const char *psrc)
{
    if(*psrc == '\0')
    {
        *pdest = *psrc;
        return;
    }
    else
    {
        *pdest = *psrc;
        return mystrcpy(pdest + 1, psrc + 1);
    }
}

static void mystrcpyNull(char **pdest, const char *psrc)
{
    *pdest = (char *)malloc((strlen(psrc) + 1) * sizeof(char));
    memset(*pdest, 0, (strlen(psrc) + 1) * sizeof(char));

    char *px = *pdest;

    while((*px++ = *psrc++));
    //while(( *(*pdest)++ = *psrc++));
}

static char* mystrcat(char *pdest, char *psrc)
{
    char *px = pdest;
    while(*px++ != '\0');
    px--;

    while((*px++ = *psrc++));
    return pdest;
}

static char* mystrchr(const char* pdest, const char ch)
{
    if(pdest == NULL || *pdest == '\0')
    {
        return NULL;
    }
    else if(*pdest == ch)
    {
        return pdest;
    }
    else
    {
        return mystrchr(pdest + 1, ch);
    }
}

int mainstr系列(int argc, char* argv[])
{
    {
        //strcat, strcpy
        char str1[] = "task";
        char str2[] = "list";
        //char dest[100] = {0};
        char *dest = NULL;

        //mystrcpy(dest, str1);
        mystrcpyNull(&dest, str1);
        mystrcat(dest, str2);
        puts(dest);
    }
    {
        //strchr
        char *px = mystrchr("calc", 'l');
        if (px == NULL) {
            printf("没有找到\n");
        }
        else
        {
            printf("%p, %c\n", px, *px);
        }
    }
    {
        //strset

    }

    return 0;
}
