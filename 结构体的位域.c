//
// Created by apple on 2017/3/23.
//
#include <stdio.h>

//位域，限定数据的位数，节约内存
struct mystruct
{
    unsigned int year:5;   //0-31 2^5
    unsigned int month:4;  //0-12 2^4
    unsigned int date:16;   //上下5000年 2^16
};

struct data
{
    unsigned int num1 : 1;
    unsigned int num2 : 1;
};

int main结构体的位域(int argc, char *argv[])
{
    {
        printf("%d\n", sizeof(struct mystruct));    //4个字节，
    }

    {
        //按照类型int来重合
        printf("%d\n", sizeof(struct data));    //4个字节，
    }

    {
        //按照类型char来重合
        struct data
        {
            unsigned char num1 : 1;
            unsigned char num2 : 1;
        };

        printf("%d\n", sizeof(struct data));    //1个字节
    }

    {
        //按照类型short来重合
        struct data
        {
            unsigned short num1 : 1;
            unsigned short num2 : 1;
        };

        printf("%d\n", sizeof(struct data));    //2个字节
    }

    {
        struct data
        {
            unsigned short num1 : 1;
            unsigned short num2 : 1;
        };

        struct data data1;
        data1.num1 = 1;
        data1.num2 = 2;
        //1, 0     data1.num2值越界了
        printf("num1 = %d, num2 = %d\n", data1.num1, data1.num2);
    }

    {
        //类型不一致时，遵循结构体对齐的规则
        struct data
        {
            unsigned int num1 : 32;
            unsigned short num2 : 1;
        };

        printf("%d\n", sizeof(struct data));  //8个字节
    }

    {
        //结构体位域的实战
        struct data
        {
            unsigned char ch1:1;    //分配内存在低字节
            unsigned char ch2:1;
            unsigned char ch3:1;
            unsigned char ch4:1;    //分配内存时， 根据先后顺序，从低字节到高字节的分配内存
            unsigned char ch5:1;
            unsigned char ch6:1;
            unsigned char ch7:1;
            unsigned char ch8:1;    //分配内存在高字节
        };                      //结构体struct data表示一个字节char类型

        int num = 1;
        int length = 4;     //表示是4个字节
        struct data *pdata = &num;

        while(length--)
        {
            printf("%d%d%d%d %d%d%d%d ",
                   (pdata + length)->ch8, (pdata + length)->ch7, (pdata + length)->ch6, (pdata + length)->ch5,
                   (pdata + length)->ch4, (pdata + length)->ch3, (pdata + length)->ch2, (pdata + length)->ch1
            );
        }
    }
    return 0;
}
