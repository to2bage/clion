//
// Created by apple on 2017/2/23.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
 * 汉诺塔的演示实现
 * */
static void swap(int *num1, int *num2)
{
    *num1 = *num1 ^ *num2;
    *num2 = *num1 ^ *num2;
    *num1 = *num1 ^ *num2;
}
static void showHanoi(int (*px)[3], int row)
{
    printf("%5c%5c%5c\n", 'A', 'B', 'C');
    printf("%15s\n", "===========");
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            printf("%5d", px[i][j]);
        }
        printf("\n");
    }
    printf("****_____****\n");
}
static void initHanoi(int (*px)[3], int row, int hanoiLevel)
{
    for(int i = 0; i < row; i++)
    {
        px[row - hanoiLevel+ i][0] = i + 1;
        if(i > hanoiLevel)
        {
            break;
        }
    }
}
static void move(int (*px)[3], int row, char source, char target)
{
    //找到源头列中第一个非0值的位置
    int sourceIndex = 0;
    while(px[sourceIndex][source - 'A'] == 0)
    {
        sourceIndex++;
        if(sourceIndex >= row)
        {
            sourceIndex = -1; //表示没有找到哦
            break;
        }
    }

    //找到目标列中最后一个0值的位置
    int targetIndex = 0;
    while(px[targetIndex][target - 'A'] == 0)
    {
        targetIndex++;
        if (targetIndex >= row)
        {
            //targetIndex = -1;当列的值都为0时会报错的，所以去掉了
            break;
        }
    }
    targetIndex--;

    //如果 源头列中第一个非0值的位置 或者 目标列中最后一个0值的位置 没有找到
    if(sourceIndex < 0 || targetIndex < 0)
    {
        printf("汉诺塔初始化有误!!!!\n");
        return;
    }
    //交换 源头列中第一个非0值的位置 和 目标列中最后一个0值的位置 的值
    swap(&px[sourceIndex][source - 'A'], &px[targetIndex][target - 'A']);
    //显示
    showHanoi(px, row);
}
static void hanoi(int (*px)[3], int row, int hanoiLevel, char A, char B, char C)
{
    if(hanoiLevel == 1)
    {
        //printf("%c => %c\n", A, C);
        move(px, row, A, C);
    }
    else
    {
        hanoi(px, row, hanoiLevel - 1, A, C, B);
        //printf("%c => %c\n", A, C);
        move(px, row, A, C);
        hanoi(px, row, hanoiLevel - 1, B, A, C);
    }
}

/*
 * 整数的原码，反码和补码
 * 模拟实现32位的显示
 * */
static void showCode(int *px, int length)
{
    for(int i = 0; i < length; i++)
    {
        printf("%d", px[i]);
        (i + 1) % 4 == 0 ? printf(" ") : printf("");
    }
    printf("\n");
}

static void bmCode(int *px, int length, int number)
{
    unsigned int data = 1;
    int num = number;
    while(length--)
    {
        if(num & data)
        {
            px[length] = 1;
        }
        else
        {
            px[length] = 0;
        }
        num >>= 1;
    }
}

static void fmCode(int *px, int length, int number)
{
    int num = number;
    unsigned int data = 1;

    if(num < 0)
    {
        num -= 1;
    }


    for(int i = length - 1; i >= 0; i--)
    {
        if(num & data)
        {
            px[i] = 1;
        }
        else
        {
            px[i] = 0;
        }
        num >>= 1;
    }
}

static void ymCode(int *px, int length, int number)
{
    int num = number;
    unsigned int data = 1;

    if(num < 0)
    {
        num -= 1; //求反码
        num = ~num | 1 << 31; //求原码
    }

    do
    {
        if(num & data)
        {
            px[--length] = 1;
        }
        else
        {
            px[--length] = 0;
        }
        num >>= 1;

    }while(length >= 0);
}

/*
 * 进制转换（10, 2, 8, 16进制相互转换）
 * */
static void conversionOfNumber(int number, int scale)
{
    if(number == 0)
    {
        if(scale == 8)
        {
            printf("0");
        }
        else if(scale == 16)
        {
            printf("0x");
        }
        return;
    }
    else
    {
        conversionOfNumber(number / scale, scale);
        if(scale == 16)
        {
            printf("%x", number % scale);
        }
        else
        {
            printf("%d", number % scale);
        }
    }
}

//2进制转10进制 0001 1001
//length是输入的二进制数的位数， i是每调用一层就增加1, pnum是输出的结果
//i从1开始, pnum从0开始
static void binTo10(char *px, int length, int i, int *pnum)
{
    if(*px == '\0')
    {
        return;
    }
    else
    {
        binTo10(px + 1, length, i + 1, pnum);
        *pnum += (*px - '0') * pow(2, length - i);
    }
}

//2进制转8进制   11 001
static void binTo8(char *px, int length)
{
    //让数组逆序
    char *pstart = px;  //指向第一位
    char *pend = px + length - 1; //指向最后一个有效位
    do
    {
        char ctemp = *pstart;
        *pstart = *pend;
        *pend = ctemp;
    }while(++pstart < --pend);
    //显示二进制： 100 11
    // 11001010001
    // 100 010 100 11
//    for(int i = 0; i < length; i++)
//    {
//        printf("%c", px[i]);
//    }
//    printf("\n");
    //
    printf("0");
    int su = 0;
    //这里的3 是二进制每3位合成一个8进制位
    for(int j = 0; j < length % 3; j++) //这里处理分段后，剩余的不足3个的二进制位
    {
        su += (px[j + (length / 3) * 3] - '0') * pow(2, j);
    }
    printf("%d", su);
    for(int i = 0; i < length /3; i++) //把二进制序列以3个一组进行分段
    {
        int sum = 0;
        for(int j = 0; j < 3; j++)
        {
            //
            sum += (px[j + (length / 3 - 1 - i)  * 3] - '0') * pow(2, j);
        }
        printf("%d", sum);
    }
}
//2进制转16进制 11010011
static void binTo16(char *px, length)
{
    //逆序二进制序列
}


int main20150409(int argc, char* argv[])
{
    {
        //汉诺塔
//        int han[10][3] = {0};
//        int hanoiLevel = 0;
//        Loop:
//        printf("请输入汉诺塔的层数:");
//        scanf("%d", &hanoiLevel);
//        if (hanoiLevel < 0)
//        {
//            printf("汉诺塔的层数必须为正整数!!!\n");
//            goto Loop;
//        }
//        initHanoi(han, 10, hanoiLevel);
//        showHanoi(han, 10);
//        hanoi(han, 10, hanoiLevel, 'A', 'B', 'C');

    }
    {
        //整数的原码，反码和补码
//        int bm[32] = {0};
//        int fm[32] = {0};
//        int ym[32] = {0};
//        printf("请输入正整数:");
//        int value = 0;
//        scanf("%d", &value);
//        //补码
//        bmCode(bm, 32, value);
//        showCode(bm, 32);
//        //反码
//        fmCode(fm, 32, value);
//        showCode(fm, 32);
//        //原码
//        ymCode(ym, 32, value);
//        showCode(ym, 32);
    }
    {
        //10进制转换,2,8,16进制
//        int num = 0;
//        printf("请输入要转换的数字:");
//        scanf("%d", &num);
//        conversionOfNumber(num, 2);
//        printf("\n");
//        conversionOfNumber(num, 8);
//        printf("\n");
//        conversionOfNumber(num, 16);
        printf("\n");
    }
    {
        //2进制转10进制
        char str[32] = {0};
        int length = 0;
        printf("请输入2进制的数列:");
        scanf("%s%n", str, &length);
        printf("你输入的二进制序列是%s，共有%d位\n", str, length);
        int rect10 = 0;
        int rect8 = 0;
        int rect16 = 0;
        binTo10(str, length, 1, &rect10);
        printf("二进制%s转换为%d进制: %d\n", str, 10, rect10);
        //
        binTo8(str, length);

    }
    {
        //8进制转10进制
    }

    return 0;
}

