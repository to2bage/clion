//
// Created by apple on 2017/3/8.
//
#include <stdio.h>

static void runmsg()
{
    printf("%s\n", "你好天朝");
}
static void print()
{
    printf("%s\n", "你好王八朝");
}
static int add(int a, int b)
{
    return a + b;
}
static int sub(int a, int b)
{
    return a - b;
}
static void oper(int (*fp)(int, int), int num1, int num2)  //函数指针作为函数的参数
{
    printf("%3d\n", fp(num1, num2));
}

//返回一个函数指针
//函数指针 int (*fp)(int, int)
//函数指针类型 int (*)(int, int)
//一个函数getOper， 参数为空，返回值是函数指针 int (* getOper(void)  )(int, int)
int (*getOper())(int , int)
{
    return add;
}

int main函数指针(int argc, char* argv[])
{
    {
        //函数指针表
        //函数指针有类型，
        //runmsg , &runmsg, *runmsg是完全等价的, 没有类型的差别
        //runmsg 和 &runmsg： 函数地址 等于 取函数指针的地址
        // *runmsg = *（&runmsg) = runmsg;
    }
    {
        //函数指针调用
        void (*fp)(void) = runmsg;
        fp();       //你好天朝
        fp = print;
        fp();       //你好王八朝
    }
    {
        //函数指针作为函数的参数, 起到固化接口的作用
        oper(add, 10, 34);
        oper(sub, 45, 23);
    }
    {
        //函数返回函数指针
        printf("%4d", getOper()(23, 45));
        //
        // int (* get(int (*y)(int, int), double) (int, int)
        // 函数get 的返回值是一个函数指针， 函数指针的类型是 int (*)(int, int)
        // 函数get的参数是： 一个是函数指针，类型是int(*)(int, int); 一个是double类型的数据
    }


    return 0;
}
