//
// Created by apple on 2017/3/3.
//

#include <stdio.h>

int main二级指针(int argc, char* argv[])
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
        *   地址0x2ef00987是没有类型的， 如果要加上一个整数表示指针的位移多少位
        *   则，这个整数必须是类型的整数倍
        *   double **pp = 0x2ef00987
        *   double *p = 0x3e00fe087
        *   double *p1 = 0x3e00e087 + 0x50;
        *   p1向后移动10个元素（0x50 = 80)
        *
        *
        *   double *p1 = &db;
        *   int *p2 = p1; 指针p2的内容是指针p1的内容，即变量db的地址
        *   但并不会转换类型， 这也是赋值号唯一不会类型转换的情况
        *   也可以理解：指针的转换，只传递地址，不改变指针的类型 和指向变量的类型
        * */
    }

    return 0;
}

