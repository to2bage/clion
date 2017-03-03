//
// Created by apple on 2017/3/3.
//
#include <stdio.h>

static void change1(int *p1, int*p2)
{
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

static void change2(int *p1, int *p2)
{
    int *ptemp;     //野指针，没有初始化，没有具体指向一片内存空间
    *ptemp = *p1;   // 也即，没有地方存放内容
    *p1 = *p2;
    *p2 = *ptemp;
}

static void change3(int *p1, int *p2)
{
    // 交换的是指针的值，也即p1原本指向变量a, 交换后p1指向变量b
    // 而变量a和变量b并没有改变
    int *ptemp;
    ptemp = p1;
    p1 = p2;
    p2 = ptemp;
}

int main指针加强(int argc, char* argv[])
{
    {
        //指针传参的副本机制
        int a = 67;
        int b = 32;
        int *pa = &a, *pb = &b;
        //scanf("%d%d", pa, pb);

        if(*pa > *pb)
        {
            // 函数的参数传递数据是有副本机制的(除了数组), 指针也不例外
            // pa传递给p1的是pa值，也就是变量a的地址， 而不是传递pa的地址(&pa)
            //change1(pa, pb);
            //
            //change2(pa, pb);
            //
            change3(pa, pb);
        }

        printf("a = %d, b = %d\n", a, b);
    }
    {
        //指针的运算
        int num = 10;
        int *p = &num;
        // 指针和整数的加减运算，与指针的类型密切相关
        printf("%p, %p, %p\n", p - 1, p, p + 1);
        // 如果不在数组的内部， 指针和常量的加减没有任何意义
        // 指针的加法： 指针 + 整数
        // 指针的减法： 指针 - 整数， 指针 - 指针(等将于 (地址 - 地址) / sizeof(类型) )
        int a[10] = {1,2,3,4,5,6,7,8,9,10};
        int *p1 = a + 3;
        int *p2 = a + 6;
        printf("%lu\n", p2 - p1); //p2 和 p1之间 间隔多少个数组元素(包括p2指向的元素)

    }
    {
        int a[10] = {1,2,3,4,5,6,7,8,9,10};
        printf("a的地址是%p, &a的地址是%p\n", a, &a);
        printf("a + 1的地址是%p, &a+1的地址是%p\n", a + 1, &a + 1);
        // a的类型是int类型； &a的类型是int[10]类型
    }
    {
        //数组实战
        int a[10] = {1,2,3,4,5,6,7,8,9,10};
        int *p;
        printf("sizeof(a) = %lu\n", sizeof(a)); //40 等价于sizeof(*&a);
        printf("sizeof(p) = %lu\n", sizeof(p)); //8
        printf("sizeof(*p) = %lu\n", sizeof(*p)); //4
        // 一个指针加*， 可以取出指针的类型(指针指向的类型)
        printf("sizeof(*a) = %lu, sizeof(*&a) = %lu\n", sizeof(*a), sizeof(*&a));//4, 40

    }
    {
        //扫描内存
//        int num = 10;
//        char *pch = (char*)&num;
//        int i = 1000;
//        while(i >= 0)
//        {
//            printf("%d\n", *((int*)(pch)));
//            pch++;
//            i--;
//        }
    }

    return 0;
}
