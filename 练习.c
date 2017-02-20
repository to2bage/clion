//
// Created by apple on 2017/2/16.
//
#include <stdio.h>

int main练习(int argc, char* argv[])
{
    {
        int num1, num2, num3;
        scanf("%d,%d,%d", &num1, &num2, &num3);
        printf("你输入的三个数字是: %d, %d, %d\n", num1, num2, num3);
        //排序
//        num1 > num2 ? (num1 > num3 ? printf("%d ", num1) : printf("%d ", num3)) : (num2 > num3 ? printf("%d ", num2) : printf("%d ", num3));
        int max = num1 > num2 ? (num1 > num3 ? num1 : num3) : (num2 > num3 ? num2 : num3);
        int mid = 0;
        int min = 0;
        if (num1 == max)
        {
            num2 > num3 ? (mid = num2, min = num3) : (mid = num3, min = num2);
        }
        if (num2 == max)
        {
            num1 > num3 ? (mid = num1, min = num3) : (mid = num3, min = num1);
        }
        if (num3 == max)
        {
            num1 > num2 ? (mid = num1, min = num2) : (mid = num2, min = num1);
        }


        printf("排序之后的顺序是: %d, %d, %d\n", max, mid, min);
    }

    return 0;
}

