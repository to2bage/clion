//
// Created by apple on 2017/3/20.
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <memory.h>
#include <errno.h>
#include <locale.h>
#include <wchar.h>
#include <string.h>


static char *mystrdump(const char* pstr)
{
    char *px = (char *)malloc((strlen(pstr) + 1) * sizeof(char));
    memset(px, 0, (strlen(pstr) + 1) * sizeof(char));
    memcpy(px, pstr, (strlen(pstr) + 1) * sizeof(char));
    return px;
}

static char *mystrncpy(char *pdest, const char *psrc, int size)
{
    char *p = pdest;
    const char *px = psrc;
    int i = 0;

    {
//        while(*px != '\0')
//        {
//            *pdest++ = *px++;
//            i++;
//            if(i >= size)
//            {
//                break;
//            }
//        }
//        *pdest = '\0';
    }
    {
        while((*pdest++ = *psrc++))
        {
            i++;
            if(i >= size)
            {
                break;
            }
        }
    }
    return p;
}

static char *mystrrchr(const char *pstr1, const char ch)
{
    char *p1 = pstr1 + strlen(pstr1) - 1;

    while(p1 != pstr1)
    {
        if(*p1 == ch)
        {
            return p1;
        }
        p1--;
    }
    return NULL;
}

static char *mystrpbrk(const char *pstr1, const char *pstr2)
{
    const char *px1 = pstr1;
    const char *px2 = pstr2;

    while(*px1 != '\0')
    {
        px2 = pstr2;
        while(*px2 != '\0')
        {
            if(*px2 == *px1)
            {
                return px1;
            }
            px2++;
        }
        px1++;
    }

    return NULL;
}

int mainStr基础(int argc, char* argv[])
{
    {
        //strdup
        char *p1 = NULL;
        char *p2 = "calc";

        //p1 = strdup(p2);
        p1 = mystrdump(p2);
        printf("%s, %s\n", p1, p2);

        *p1 = 'A';
        printf("%s, %s\n", p1, p2);
    }
    {
        //stderr
        char *pbuffer = NULL;
        pbuffer = strerror(errno);
        printf("Error: %s\n", pbuffer);
    }
    {
        //strncpy
        char str1[10] = "task";
        char str2[10] = "list8848";

        //strncpy(str1 + 4, str2, 2 * sizeof(char));
        mystrncpy(str1 + 4, str2, 2 * sizeof(char));
        printf("%s\n", str1);
    }
    {
        //strpbrk 返回指向str2中第一个出现在str1中的字符的指针
        char str1[10] = "abcedefg";
        char str2[10] = "dglc";
        //char *p = strpbrk(str1, str2);
        char *p = mystrpbrk(str1, str2);
        printf("%s, %c\n", p, *p);
    }
    {
        //strrchr
        char str1[10] = "abcedefg";
        char str2[10] = "dglc";
        //char *p = strrchr(str1, 'e');
        char *p = mystrrchr(str1, 'e');
        printf("%s, %c\n", p, *p);
    }
    {
        //strrev
        setlocale(LC_ALL, "zh_CN");
        wchar_t wstr[10] = L"海华爱王芳";

        wprintf(L"%ls\n", wstr);    //wcs函数都是在wchar.h头文件中
    }
    {
        //strspn
        char str[100] = "fang fang love read book";
        char hh[130] = "lfang";
        size_t size = strspn(str, hh);
        printf("%d\n", size);
    }
    {
        //strupr strlwr
        char str1[100] = "asdFGH";
        //printf("%s, %s\n", strlwr(str1), strupr(str1));

    }
    {
        //strerror
        FILE *pfr = fopen("/Users/apple/Desktop/1.txt", "r");
        if(pfr == NULL)
        {
            char *pbuffer = strerror(errno);
            printf("%s\n", pbuffer);
            //abort();
        }
        char *pbuffer = strerror(errno);
        printf("%s\n", pbuffer);
    }
    {
        //strtod
        char str1[100] = "我有12.678元";
        char *p = NULL;
        double db = strtod(str1 + 6, &p);   //汉字在Linux内存中占3个字节
        printf("%f, %p, %s\n", db, p, p);

    }

    return 0;
}
