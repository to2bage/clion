//
// Created by apple on 2017/3/15.
//
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

static void* mymemcpy(void *dst, const void *src, unsigned int size)
{
    char *pdst = (char *)dst;   //内存的最小单位是一个字节，也就是char类型
    char *psrc = (char *)src;

    {
//        for(int i = 0; i < size; i++)
//        {
//            *pdst++ = *psrc++;
//        }
    }

    {
        //不能使用下面的写法，因为*psrc按照字节读取的数据可能是0, 造成while语句结束；
//        int i = 0;
//        while(i++ < size && (*pdst++ = *psrc++));

        //应该写成下面的样子
        int i = 0;
        while(i++ < size)
        {
            *pdst++ = *psrc++;
        }
    }


    return dst;
}

static void * mymemset(void *dst, int val, unsigned int size)
{
    char *pdst = (char *)dst;
    int i = 0;
    while(i++ < size)
    {
        *pdst++ = (char)val;
    }

    return dst;
}

static void* mymemmove(void *dst, const void* src, unsigned int size)
{
    char *pdst = (char *)dst;
    char *psrc = (char *)src;
}

int main内存操作函数(int argc, char* argv[])
{
    {
        //memcpy
        int a[10] = {1,2,3,4,5,6,7,8,9,10};
        int *p = (int *)malloc(10 * sizeof(int));
        //memcpy(p, a, 40);   // 目的地址，源地址，拷贝的字节数
        mymemcpy(p, a, 40);
        for(int i = 0; i < 10; i++)
        {
            printf("%4d ", p[i]);
        }
        printf("\n");
    }
    {
        //memset
        int a[10] = {1,2,3,4,5,6,7,8,9,10};
        double db[5] = {1.1,2.2,3.3,4.4,5.5};
        char str[1024] = "hello world";
        //memset(a, 0, 10 * sizeof(int)); //源地址，每个字节要设置的值，多少个字节

    }
    {
        //memmove
        int a[10] = {1,2,3,4,5,6,7,8,9,10};
        int b[10] = {0};
        memmove(b, a, 12);  //12个字节

        char str1[] = "abcdefghijklmnopqrstuvwxyz";
        char str2[] = "**************************";

        printf("%s\n", str1);
        //printf("%s\n",(char *)memmove(str1, str1 + 2, 6));
        printf("%s\n",(char *)memmove(str1 + 2, str1, 6));
    }


    return 0;
}
