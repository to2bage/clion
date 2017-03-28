//
// Created by apple on 2017/2/14.
//
#include <stdio.h>
#include <string.h>

int main04(int argc, char* argv[])
{
    unsigned short int unum1 = 10;
    short int num1 = 123;
    printf("%hd, %hu\n", num1, unum1);    //%hd:短整数 short类型

    unsigned  int unum2 = 10;
     int num2 = 123;
    printf("%d, %u\n", num2, unum2);    //%d:短整数 int类型

    {
        unsigned long int unum1 = 10;
        long int num1 = 123;
        printf("%ld, %lu\n", num1, unum1);    //%ld:短整数 long 类型
    }

    {
        unsigned long long int unum1 = 10;
        long long int num1 = 123;
        printf("%lld, %llu\n", num1, unum1);    //%lld:短整数 long long 类型
    }

    {
        int num = 0127;
        printf("%o\n", num);
        printf("%#o\n", num);

        int data = 0x1234;
        printf("%x\n", data);
        printf("%#x\n", data);  //#表示进制
    }

    {
        float fl = 10.8;
        double db = 10.9;
        printf("%#a\n", fl);    //a 16进制显示小数
        printf("%#a\n", db);
    }

    {
        double  db = 1.123456789123456789;
        for(int i = 0; i < 20; i++)
        {
//            printf("%.*f\n", i, db);
            printf("%*.*f\n", 2 * i, i, db);
        }
    }

    {
        char *pstr = "abcdefghijlmnopqrstuvwxyz";
        for(int i = 0; i < strlen(pstr); i++)
        {
            printf("%.*s\n", strlen(pstr) - i, pstr);
        }
    }


    return 0;
}
