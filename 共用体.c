//
// Created by apple on 2017/3/23.
//
// 共用体的内存大小，要能整除最大的基本成员数据类型
//
//
#include <stdio.h>

int main共用体(int argc, char *argv[])
{
    {
        //共用体的定义, 和结构体一样，必须要有一个成员类型
        union myunion
        {
            int num;
            double db;
        };

        printf("%d\n", sizeof(union myunion));      //8个字节， 共用体内存大小 取决于 最大的基本成员数据类型

        union myunion my1;  //共用体任何时刻，都只有一个数据成员存在
        my1.db = 12823.887;
        printf("myunion.num = %d, myunion.db = %f\n", my1.num, my1.db); //乱码， 23.887000
        my1.num = 12;
        printf("myunion.num = %d, myunion.db = %f\n", my1.num, my1.db); //12， 乱码
    }

    {
        //共用体的初始化
        union myunion
        {
            int num;
            double db;
        };

        union myunion my1 = {12};
        union myunion my2 = {34.566};
    }


    return 0;
}
