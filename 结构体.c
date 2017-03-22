//
// Created by apple on 2017/3/21.
//
//  结构体类型声明应该放在头文件
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//C语言结构体内部变量不能有初始化值，C++是可以的
struct MyStruct
{
    int num;
    char str[100];
}m0 = {.str = "hello"};


struct MyStructX
{
    struct MyStruct my1;    //结构体是可以嵌套的
    int num;
    char str[10];
};

struct str
{
    char *p;
    char str[100];
    int num;
};


int main结构体(int argc, char* argv[])
{
    {
        struct MyStructX myx = {{10, "calc"}, 101, "notepad"};
        struct MyStructX myy = myx; //结构体变量可以直接赋值

        //C99结构体初始化
        struct MyStruct m1 = {.num = 1234};
        struct MyStruct m2 = {.str = "world", .num = 23};

        printf("m0.num = %d, m0.str = %s\n", m0.num, m0.str);
        printf("m1.num = %d, m1.str = %s\n", m1.num, m1.str);
        printf("m2.num = %d, m2.str = %s\n", m2.num, m2.str);
    }
    {
        //结构体变量拷贝的注意事项
        struct str mystr1;
        mystr1.num = 30;
        strcpy(mystr1.str, "deep copy");
        mystr1.p = (char *)malloc(30 * sizeof(char));
        strcpy(mystr1.p, "hello world");

        //结构体的非指针变量num和str都是深拷贝的，指针变量是浅拷贝的
        struct str mystr2 = mystr1;     //结构体拷贝底层是用memcpy实现的
        printf("str1.num = %p, str2.num = %p\n", &mystr1.num, &mystr2.num); //不相等
        printf("str1.str = %p, str2.str = %p\n", mystr1.str, mystr2.str);   //不相等
        printf("str2.str = %s\n", mystr2.str);  //结构体的数组成员赋值成功
        printf("str1.p = %p, str2.p = %p\n", mystr1.p, mystr2.p);   //相等
        ////修改指针变量的浅拷贝, 变成深拷贝
        mystr2.p = (char *)malloc(30 * sizeof(char));
        strcpy(mystr2.p, mystr1.p);
    }

    return 0;
}
