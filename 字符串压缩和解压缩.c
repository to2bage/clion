//
// Created by apple on 2017/3/21.
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <memory.h>

//时间优先压缩
static char *timefirstzip(char *pstr)
{
    int length = strlen(pstr);

    char *str = (char *)malloc((length + 1) * sizeof(char));
    memset(str, 0, (length + 1) * sizeof(char));

    char *p1 = pstr;
    char *p2 = pstr;
    char *px = pstr;
    char *ps = str;

    while(*px != '\0')
    {
        p1 = px;
        int num = 0;
        while(*p1 == *p2)
        {
            num++;
            p2++;
        }//此时，p2指向不同于p1的第一个元素

        if(num > 1)
        {
            *ps = num + '0';
            *++ps = *(p2 - 1);
            ps++;
        }
        else
        {
            *ps = *(p2 - 1);
            ps++;
        }

        px = p2;
    }

    str = (char *)realloc(str, (strlen(str) + 1) * sizeof(char));
    return str;
}

//时间优先解压缩
static char *timefirstUnzip(char *pstr)
{
    char *str = (char *)malloc(1024 * sizeof(char));
    memset(str, 0, 1024 * sizeof(char));

    char *p1 = pstr;    //p1是压缩的字符串
    char *p2 = str;     //p2是新的字符串

    while(*p1 != '\0')
    {
        if(*p1 >= '0' && *p1 <= '9')
        {
            int len = *p1 - '0';
            for(int i = 0; i < len; i++)
            {
                *p2 = *(p1 + 1);
                p2++;
            }
            p1 += 2;    //后移2位，一位是是数字字符，一位字母字符
        }
        else
        {
            *p2++ = *p1++;
        }
    }

    str = (char *)realloc(str, (strlen(str) + 1) * sizeof(char));
    return str;
}

//空间优先压缩
static char *spacefirstzip(char *pstr)
{
    char *px = pstr;
    char *p1 = pstr;
    char *p2 = pstr;
    char *p3 = pstr;

    while(*px != '\0')
    {
        int num = 0;
        while(*p3 == *p2)
        {
            num++;
            p2++;
        }
        //此时p1指向相同元素的开始位置
        //此时p2指向相同元素的最后一个元素的下一个元素

        if(num > 1)
        {
            *p1 = num + '0';
            *++p1= *(p2 - 1);       //注意：这里不能使用*p3, 在只有一个字符的情况下，*p3的值可能已经被修改
            p1++;   //此时p1指向下一个待赋值的位置
        }
        else
        {
            *p1 = *(p2 - 1);
            p1++;
        }

        //
        px = p2;
        p3 = p2;
    }
    *p1 = '\0';

    return pstr;
}
//空间优先解压缩    5a3bhaihualovefangfang9o
static char *spacefirstUnzip(char **ppstr)
{
    //char *pstr = *ppstr;
    char *p1 = *ppstr;
    char *p2 = *ppstr;
    int num = 0;

    while(*p2 != '\0')
    {
        num = 0;
        if(*p1 >= '0' && *p1 <= '9')
        {
            num = *p1 - '0';
            p2 += 2;
        }//此时p2指向下一个要操作的字母字符或数字字符，比如刚开始时是3

        if(num == 0)
        {
            *p1++ = *p2++;
        }
        else
        {
            //向后移动数据
            int len = num - 2;
            int xpos1 = p1 - *ppstr;  //记录p1相对位置
            int xpos2 = p2 - *ppstr;  //记录p2相对位置

            ////重新分配内存
            *ppstr = (char *)realloc(*ppstr, (strlen(*ppstr) + len + 1) * sizeof(char));

            p1 = *ppstr + xpos1;
            p2 = *ppstr + xpos2;


            char *pend = p2 + strlen(*ppstr);   //包含字符'\0'
            while(pend >= p2)
            {
                *(pend + len) = *pend;
                pend--;
            }

            //拷贝字符
            for(int i = 0; i < num; i++)
            {
                *p1++ = *(p2 - 1);
            }//此时，p1指向下一个要操作的字母字符或数字字符

            p2 = p1;
        }
    }
}

int main字符串压缩和解压缩(int argc, char *argv[])
{
    char str[100] = "aaaaabbbhaihualovefangfangooooooooo";
    //char str[1000000] = "aabbccbbb";
    //5a3bhaihualovefangfang9o

    {
        //压缩之时间优先
        //spacefirstzip(str);
        //压缩之空间优先
        char *prect = timefirstzip(str);

        printf("%s\n", str);
        printf("%s\n", prect);

        //解压缩之时间优先
//        char *punzipstr = timefirstUnzip(prect);
//        printf("%s\n", punzipstr);

        //解压缩之空间优先
        spacefirstUnzip(&prect);
        printf("%s\n", prect);
    }


    return 0;
}
