//
// Created by apple on 2017/3/22.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

static void spaceFirstUnzip(char **ppstr);

int main20150505(int argc, char *argv[])
{
    {
        //
    }
    {
        // 5 calc 4 4a  ==> calc  calc  calc  clac  calc  4a 4a 4a 4a
        // ==> calc calc calc calc calc aaaa aaaa aaaa aaaa
        char srcStr[25] = "5 calc 4 aa";    //产量字符串
        //因为会修改字符串的首地址和内容，所以不能用常量字符串，要使用堆上的字符串
        char *px = (char *)malloc((strlen(srcStr) + 1) * sizeof(char));
        memset(px, 0, (strlen(srcStr) + 1) * sizeof(char));
        strcpy(px, srcStr);
        {
            //解压缩之空间优先算法
            spaceFirstUnzip(&px);
            printf("解压缩之空间优先算法: %s\n", px);
        }
    }
    {
        //
    }
    return 0;
}

static int getNumberOfChar(char *pstr)
{
    int num = 0;

    while((*pstr < '0' || *pstr > '9') && *pstr != '\0')
    {
        num++;
        pstr++;
    }

    return num;
}

//空间优先算法
static void spaceFirstUnzip(char **ppstr)
{
    char *p1 = *ppstr;
    char *p2 = *ppstr;

    while((*p1 = *p2))
    {
        int number = 0;
        if(*p2 >= '0' && *p2 <= '9')
        {
            //如果指向的是数字字符
            number = *p2 - '0';
            printf("num = %d\n", number);
            p2++;   //p2指向下一个操作字母字符
            //获得要重复的字母字符的个数count和要扩容的空间大小totalSize
            int count = getNumberOfChar(p2);
            int totalSize = number * count - count; //减去count是因为已经有一个字符串了
            printf("count = %d, totalsize = %d\n", count, totalSize);
            //在分配内存之前，先记录当前p1和p2的相对位置
            int pos1 = p1 - *ppstr;
            int pos2 = p2 - *ppstr;
            //扩展内存
            *ppstr = (char *)realloc(*ppstr, (strlen(*ppstr) + totalSize + 1) * sizeof(char));

            //获得当前p1和p2的位置
            p1 = *ppstr + pos1;
            p2 = *ppstr + pos2;
            //从后向前移动元素
            char *pend = *ppstr + strlen(*ppstr);
            while(pend >= p2)
            {
                *(pend + totalSize) = *pend;
                pend--;
            }
            //拷贝数据
            char *p3 = p2;
            for(int i = 0; i < totalSize; i++)
            {
                p3[i] = p2[i % count];  //count是calc的长度
            }
        }
        else
        {
            //如果指向的不是数字字符
            *p1++ = *p2++;
        }
    }
}

