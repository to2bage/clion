//
// Created by apple on 2017/2/17.
//
#include <stdio.h>
#include <math.h>
#include <stdbool.h>

_Bool isZhiShu(int num)
{
    if(num <= 1)
    {
        return false;
    }
    else if(num == 2 || num == 3)
    {
        return true;
    }
    else
    {
        _Bool bo = true;
        for(int i = 2; i < (int)(sqrt(num)) + 1; i++)
        {
            if (num % i == 0)
            {
                bo = false;
                break;
            }
        }
        return bo;
    }
}

int main分离和穷举(int argc, char* argv[])
{
    {
        //
        int i = 100;
        while(i++ <= 999)
        {
            int baiwei = i / 100;
            int shiwei = i /10 % 10;
            int gewei = i % 10;
            if (pow(baiwei, 3) + pow(shiwei, 3) + pow(gewei, 3) == i)
            {
                printf("%d\n", i);
            }
        }
    }
    {
        //1，1，2，3，5，8，13.。。
        int f1 = 1, f2 = 1;
        int i = 3;
        printf("%10d%10d ", f1, f2);
        while(i++ <= 40)
        {
            int temp = f1 + f2;
            f1 = f2;
            f2 = temp;
            printf("%10d ", f2);
            if (i % 5 == 0)
            {
                printf("\n");
            }
        }
        printf("\n");
    }
    {
        //质数
        int i = 0;
        while(++i <= 100)
        {
            if (i == 1)
            {
                continue; //1不是质数
            }
            if (i == 2 || i == 3)
            {
                printf("%d是质数\n", i); //2，3都是质数
                continue;
            }
            _Bool bo = true;
            for(int j = 2; j < (int)(sqrt(i)) + 1; j++)
            {
                if (i % j == 0)
                {
                    bo = false;
                    break;
                }
            }
            if (bo == true)
            {
                printf("%d是质数\n", i);
            }
        }
    }
    {
        //判断人任意一个偶数，都可以拆解为2个质数的和
//        int num = 0;
//        printf("请输入一个偶数:");
//        scanf("%d", &num);
////        if(isZhiShu(num))
////        {
////            printf("%d是质数\n", num);
////        }
////        else
////        {
////            printf("%d不是质数\n", num);
////        }
//        for(int i = 1; i < num / 2; i++)
//        {
//            if(isZhiShu(i) && isZhiShu(num - i))
//            {
//                printf("%d + %d = %d\n", i, num - i, num);
//            }
//        }

    }
    {
        //任何一个奇数可以拆解为3个质数之和
//        int num = 0;
//        Error:
//        printf("请输入一个奇数: ");
//        scanf("%d", &num);
//        if(num % 2 == 0)
//        {
//            printf("请输入一个奇数哦！！！！\n");
//            goto Error;
//        }
//
//        for(int i = 1; i < (int)(num / 3) + 1; i++)
//        {
//            for(int j = 1; j < (int)(num / 3) + 1; j++)
//            {
//                if(isZhiShu(i) && isZhiShu(j) && isZhiShu(num - i - j))
//                {
//                    printf("%d + %d + %d = %d\n", i, j, num - i - j, num);
//                }
//            }
//        }
    }
    {
        int num = 0;
        printf("请输入一个整数: ");
        scanf("%d", &num);

        int number = num;
        int rect = 0;
//        while(number)
//        {
//            rect *= 10;
//            rect += number % 10;
//            number /= 10;
//        }
        //
        do
        {
            rect *= 10;
            rect += number % 10;
            number /= 10;
        }
        while (number);
        printf("逆序后的结果是: %d\n", rect);
    }


    return 0;
}

