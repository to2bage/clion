//
// Created by apple on 2017/2/22.
//

#include <stdio.h>
#include <math.h>



//加法的异或实现
static int add(int num1, int num2)
{
    int number1 = num1;
    int number2 = num2;
    int str[32] = {0};

    int jinwei = 0; //初始化进位=0， 因为0异或（1或0）， 都保持(1或0)不改变
    int temp1 = 0;
    int temp2 = 0;
    int i = 31;
    do
    {
        if(number1 & 1)
        {
            temp1 = 1;
        }
        else
        {
            temp1 = 0;
        }

        if(number2 & 1)
        {
            temp2 = 1;
        }
        else
        {
            temp2 = 0;
        }

        int rect = temp1 ^ temp2 ^ jinwei;
        str[i--] = rect;

        if((temp1 == 1 && temp2 == 1) || (temp1 == 1 && jinwei == 1) || (temp2 ==1 && jinwei == 1))
        {
            jinwei = 1;
        }
        else
        {
            jinwei = 0;
        }

        number1 >>= 1;
        number2 >>= 1;
    }
    while(i >= 0);
    //
    int sum = 0;
    for(int i = 0; i < 32; i++)
    {
        printf("%d", str[i]);
        (i + 1) % 4 == 0 ? printf(" ") : printf("");
        sum += str[i] * pow(2, 31 - i);
    }
    printf("\n");
    //printf("sum = %d\n", sum);
    return sum;
}

//加法的异或实现（更新版）
static int addPlus(int num1, int num2)
{
    int rect = 0;
    int jingwei = 0;

    do
    {
        rect = num1 ^ num2;
        jingwei = (num1 & num2) << 1;

        num1 = rect;
        num2 = jingwei;
    }
    while(jingwei);

    return rect;
}

//加法的异或实现（递归版）
static int addDiGui(int num1, int num2)
{
    if(num2 == 0)
    {
        return num1;
    }
    else
    {
//        int rect = num1 ^ num2;
//        int jinwei = (num1 & num2) << 1;
//
//        num1 = rect;
//        num2 = jinwei;
//        return addDiGui(num1, num2);
        return addDiGui(num1 ^ num2, (num1 & num2) << 1);
    }
}

//减法的位运算实现
static int sub(int num1, int num2)
{
    int rect = 0;
    int jiewei = 0;

    do
    {
        rect = num1 ^ num2;
        jiewei = (num1 ^ num2) << 1;
        num1 = rect;
        num2 = jiewei;
    }while(jiewei);
    return rect;
}
//乘法的位运算实现
static int mul(int num1, int num2)
{
    int rect = 0;

    rect = num1 & num2;
    return rect;
}

int main加减法的位运算(int argc, char* argv[])
{
    {
        printf("请输入要相加的两个数字(使用都好隔开):");
        int num1 = 0, num2 = 0;
        scanf("%d,%d", &num1, &num2);
        //加法
        //int rect = add(num1, num2);
        //int rect = addPlus(num1, num2);
        int rect = addDiGui(num1, num2);
        printf("%d + %d = %d\n", num1, num2, rect);
//        //减法
//        rect = sub(num1, num2);
//        printf("%d - %d = %d\n", num1, num2, rect);
        //乘法
        rect = mul(num1, num2);
        printf("%d * %d = %d\n", num1, num2, rect);
    }

    return 0;
}

