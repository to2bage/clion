//
// Created by apple on 2017/3/21.
//
//  删除所有，插入所有，替换所有，都使用到双指针
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <stdbool.h>

static void replaceAll(char **ppx, char *pold, char *pnew)
{
    char *px = *ppx;
    unsigned long oldlen = strlen(pold);
    unsigned long newlen = strlen(pnew);

    if(oldlen == newlen)
    {
        {
//            while(*px != '\0')
//            {
//                char *psrc = px;
//                char *old = pold;
//                _Bool isFind = true;
//
//                while(*old != '\0')
//                {
//                    if(*old != *psrc)
//                    {
//                        isFind = false;
//                        break;
//                    }
//                    old++;
//                    psrc++;
//                }
//
//                if(isFind)
//                {
//                    //找到了
//                    //开始替换，此时px指向要替换的字符串的开始位置
//                    char *new = pnew;
//                    while(*new != '\0')
//                    {
//                        *px++ = *new++;
//                    }
//                }
//                else
//                {
//                    //没有找到
//                    px++;
//                }
//            }
        }

        {
            char *p1 = *ppx;
            char *p2 = *ppx;

            while((*p1 = *p2))
            {
                char *p3 = p2;
                char *old = pold;
                _Bool isfind = true;

                while(*old != '\0')
                {
                    if(*p3 != *old)
                    {
                        isfind = false;
                        break;
                    }
                    p3++;
                    old++;
                }

                if(isfind)
                {
                    //找到了，此时p1和p2都指向原字符串中被替换的字符串的首位置
                    char *new = pnew;
                    while(*new != '\0')
                    {
                        *p2++ = *new++;
                    }
                    p1 = p2;
                }
                else
                {
                    p1++;
                    p2++;
                }
            }
        }
    }
    else if(oldlen > newlen)
    {
        //被替换的字符串的长度 大于 新字符串的长度
        char *p1 = *ppx;
        char *p2 = *ppx;

        while((*p1 = *p2))
        {
            char *p3 = p2;
            char *old = pold;
            _Bool isfind = true;

            while(*old != '\0')
            {
                if(*p3 != *old)
                {
                    isfind = false;
                    break;
                }
                p3++;
                old++;
            }

            if(isfind)
            {
                //找到了，此时p1和p2都指向原字符串中被替换的字符串的首位置
                //p3指向被替换的字符串的最后一个有效的位置的下一个位置
                //printf("%c, %d\n", *p3, p3 - px);
                //被替换的字符串的长度 大于 新字符串的长度
                char *new = pnew;
                while(*new != '\0')
                {
                    *p1++ = *new++;
                }

                p2 = p3;

            }
            else
            {
                p1++;
                p2++;
            }
        }
    }
    else
    {
        //被替换的字符串的长度 小于 新字符串的长度
        char *p1 = *ppx;
        char *p2 = *ppx;

        while((*p1 = *p2))
        {
            char *p3 = p2;
            char *old = pold;
            _Bool isFind = true;

            while(*old != '\0')
            {
                if(*old != *p3)
                {
                    isFind = false;
                    break;
                }
                old++;
                p3++;
            }

            if(isFind)
            {
                int len = newlen - oldlen;
                //记录指针p1 p2 p3相对于ppx 的位置
                int curP1 = p1 - *ppx;
                int curP2 = p2 - *ppx;
                int curP3 = p3 - *ppx;

                //重新分配内存
                //realloc不会初始化数据,+1表示末尾要带字符\0
                *ppx = (char *)realloc(*ppx, (strlen(*ppx) + len + 1) * sizeof(char));

                //根据相对位置，获得重新分配内存后的地址
                p1 = *ppx + curP1;
                p2 = *ppx + curP2;
                p3 = *ppx + curP3;

                char *pend = *ppx + strlen(*ppx);   //顺带把\0也给拷贝到字符串的末尾
                //从后向前移动
                while(pend >= p3)
                {
                    *(pend + len) = *pend;
                    pend--;
                }
                p3 += len;

                //拷贝新的字符串
                char *new = pnew;
                while(*new != '\0')
                {
                    *p1++ = *new++;
                }
                p2 = p3;
            }
            else
            {
                p1++;
                p2++;
            }
        }
    }
}

int main字符串替换(int argc, char* argv[])
{
    char *pstr = "12345543211234554321";
    int length = strlen(pstr);
    char *px = (char *)malloc((length + 1) * sizeof(char));
    memset(px, 0, (length + 1) * sizeof(char));
    strcpy(px, pstr);
    {
//        printf("替换之前的字符串:%s\n", px);
//
//        replaceAll(&px, "12345", "abcde");
//
//        printf("替换之后的字符串:%s\n\n", px);
    }
    {
//        printf("替换之前的字符串:%s\n", px);
//
//        replaceAll(&px, "1234", "ab");
//
//        printf("替换之后的字符串:%s\n\n", px);
    }
    {
        printf("替换之前的字符串:%s\n", px);

        replaceAll(&px, "123", "abcde");

        printf("替换之后的字符串:%s\n\n", px);
    }

    return 0;
}
