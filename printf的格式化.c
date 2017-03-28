//
// Created by apple on 2017/2/14.
//
#include <stdio.h>
#include <string.h>

int main03(int argc, char* argv[])
{
    printf("hello world\n");

    printf("%d\n", 10); //有多宽，分配多宽
    printf("%10d\n", 10); //宽度是10， 右对齐（默认）
    printf("%-10d\n", 10); //左对齐
    printf("%010d\n", 10);
    printf("%3d\n", 45610);

    printf("%.2f\n", 1.2345);
    char str[100] = "calc1";
    printf("%.4s\n", str);

    long long l1 = 1234567890;
    long l2 = 2345678901;
    printf("%ld\n", l1);
    printf("%ld\n", l2);

    int num = 12345678;
    printf("%d\n", num);
    printf("%i\n", num);
    printf("%u\n", num);
    printf("%o\n", num);
    printf("%x\n", num);

    char ch = 'A';
    printf("%c\n", ch);
    putchar(ch);
    putchar('\n');

    char sstr[100] = "include <stdio.h>";
    printf("%s\n", sstr);

    char str1[10] = "task";
    char str2[10] = "list";
    char str3[50] = {0};
    sprintf(str3, "%s%s", str1, str2);
    printf("%s\n", str3);

    char str4[20] = "123list123";
    printf("%.4s\n", str4 + 3);

    double  db = 109.7896616253;
    printf("%f\n", db);
    printf("%.10f\n", db);
    printf("%30.10f\n", db);
    printf("%-30.10f\n", db);

    double db1 = 10000000000000;
    printf("%e\n", db1);
    double db2 = 0.00000000000045;
    printf("%e\n", db2);

}
