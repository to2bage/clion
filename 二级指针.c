//
// Created by apple on 2017/3/3.
//

#include <stdio.h>

int main(int argc, char* argv[])
{
    {
        double db = 10.8;
        printf("&db = %p,%d\n", &db, &db);
        double *p = &db;
        printf("p = %p, %d\n", p, p);   //打印变量p的内容
        printf("&p = %p, %d\n", &p, &p);  //变量p的地址&p = 0x7fff5a35ea50, 1513482832
        double **pp = &p;

        double *px = &p;    //变量px存贮了变量p的地址
        printf("px = %p, %d\n", px, px);//打印变量px的内容
        //printf("*px = %d\n", *px);
        //从变量p的地址(&p)开始，读取8个字节的数据(px指向的是double类型)
        //而这显然得不到10.8


       /*
        *  总结
         *  用一个一级指针(px)保存一个一级指针(p)的地址
         *  取*px的值，得到的是从p的地址(&p)开始的double类型的值(取8个字节的数据)
         *  而正确的操作是：   从p的内容(p) 开始的double类型的值(取8个字节的数据)
        *
        *
        *
        * */
    }

    return 0;
}

