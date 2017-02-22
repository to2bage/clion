//
// Created by apple on 2017/2/22.
//
//  num1和num2的最大公约数(假设num1 > num2): int mod1 = num1 % num2;  mod2 = num2 % mod1...直到mod == 0
//  num1和num2的最小公倍数： num1 * num2 / (num1和num2的最大公约数)

#include <stdio.h>

//最大公约数
static int maxGongBeiNumber(int num1, int num2)
{
    int number1 = num1;
    int number2 = num2;
    //num1 > num2 ? (number1 = num1, number2 = num2):(number1 = num2, number2 = num1);
    int temp = 0;

    do
    {
        temp = number1 % number2;
        number1 = number2;
        number2 = temp;
    }while(temp);

    return number1;
}
//最大公约数的递归实现
static int maxGongyueNuberDigui(int num1, int num2)
{
    if(num2 == 0)
    {
        return num1;
    }
    else
    {
        return maxGongyueNuberDigui(num2, num1 % num2);
    }
}

int main最大公约数(int argc, char* argv[])
{
    {
        int num1 = 10;
        int num2 = 25;
        int rect = maxGongBeiNumber(num1, num2);
        //int rect = maxGongyueNuberDigui(num1, num2);
        printf("%d 和 %d的最大公约数是: %d\n", num1, num2, rect);
        printf("%d 和 %d的最小公倍数是：%d\n", num1, num2, num1 * num2 / rect);
    }

    return 0;
}