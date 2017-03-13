//
// Created by apple on 2017/3/13.
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

static int comint(const void *p1, const void *p2);

int main字符串初始化(int argc, char* argv[])
{
    {
        //字符串的定义
        char str[100] = "calc";
        char str1[5] = {'c','a','l','c'};
        char* p1 = (char[]){'m', 's', 'p', 'a', '\0'};  //\0不能忘
        char *p2 = "notepade";  //字符串常量notepad在代码区的常量表中，不能修改
        //字符数组的定义
        char* p3 = (char[]){'m', 's', 'p', 'a'};
        char p4[5] = {'m', 's', 'p', 'a', 'i'};

        printf("%lu\n", sizeof(str));    //100个字节
        printf("%lu\n", strlen(str));   //4个字节
    }
    {
        //字符串的初始化
        char str1[100] = {"calc"};
        char str2[100] = "calc";    // {}可以省略, 将代码区中的内容拷贝到字符数组中

        //char *p1 = (char[])"calc";    //{}不可以省略
        char *p2 = (char[]){"calc"};

        char str3[5][20] = {{"calc"}, {"paint"}, {"system"}, {"notepad"}, {"hello"}};
        char str4[5][20] = {"calc", "paint", "system", "notepad", "hello"};
        char *p[5] = {"calc", "paint", "system", "notepad", "hello"};

        printf("%lu\n", sizeof("calc"));    //5个字节 包含'\0'
        printf("%lu\n", strlen("calc"));    //4个字节 不包含'\0'
    }
    {
        char str[100];
        //str = "calc";   //错误 str是常量

        char *p1 = NULL;
        p1 = "calc";    //p是变量，可以接受地址的赋值
        //scanf("%s", &p1);
        //scanf("%s", p1);  错误的， 改变指针p指向的代码区的内容
        printf("%s\n", p1);
    }
    {
        char *p = NULL;
        //scanf("%s", p); //错误， 因为p只是一个4个字节的变量，没地址保存字符串
        //根据指针初始化字符串，必须开辟空间
        p = (char*)calloc(100, sizeof(char));
        scanf("%s", p);                         //这里要求输入
        printf("%s\n", p);
    }
    {
        //qsort
        srand(time(NULL));
        int arr[20] = {0};
        for(int i = 0; i < 20; i++)
        {
            printf("%4d", arr[i] = rand() % 100);
        }
        printf("\n");

        qsort(arr, 20, sizeof(int), comint);

        for(int i = 0; i < 20; i++)
        {
            printf("%4d", arr[i]);
        }
        printf("\n");
    }


    return 0;
}

static int comint(const void *p1, const void *p2)
{
    int *pint1 = (int*)p1;
    int *pint2 = (int*)p2;

    return (*pint1 - *pint2);
}