//
// Created by apple on 2017/3/20.
//
#include <stdio.h>
#include <stdlib.h>

int mainstr高级(int argc, char* argv[])
{
    //数字 转 字符串
    {
        //ecvt 自动分配内存
        double data = -123.456789;
        int decimal = 0;    //小数点的位置， 可以理解为整数的位数
        int sign = 0;       //符号 1表示负数，0表示正数
        int precision = 6; //数字的宽度 123457 强行指定宽度
        char *pbuffer = NULL;
        pbuffer = ecvt(data, precision, &decimal, &sign);
        printf("pbuffer = %s\n", pbuffer);
        printf("decimal = %d\n", decimal);
        printf("sign = %d\n", sign);
        printf("precision = %d\n\n", precision);
    }
    {
        //fcvt 自动分配内存
        double data = -123.456789;
        int decimal = 0;    //小数点的位置， 可以理解为整数的位数
        int sign = 0;       //符号 1表示负数，0表示正数
        int precision = 6; //数字的宽度 123456789 不强行指定跨度
        char *pbuffer = NULL;
        pbuffer = fcvt(data, precision, &decimal, &sign);
        printf("pbuffer = %s\n", pbuffer);
        printf("decimal = %d\n", decimal);
        printf("sign = %d\n", sign);
        printf("precision = %d\n\n", precision);
    }
    {
        //gcvt 不会自动分配内存
        double data = -123.456789;
        int decimal = 0;    //小数点的位置， 可以理解为整数的位数
        int sign = 0;       //符号 1表示负数，0表示正数
        int precision = 12; //数字的宽度
        char pbuffer[100] = {0};
        gcvt(data, precision, pbuffer);
        printf("pbuffer = %s\n", pbuffer);  //-123.456789
        printf("decimal = %d\n", decimal);
        printf("sign = %d\n", sign);
        printf("precision = %d\n\n", precision);
    }

    //字符串 转 数字
    {
        unsigned int num = 32;
        char str[32] = {0};

    }

    return 0;
}
