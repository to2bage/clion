//
// Created by apple on 2017/3/17.
//
#include <stdio.h>
#include <stdbool.h>

//取出字符串的空格
static void eraseChar(char *pstr, char ch)
{
    char *p1 = pstr;
    char *p2 = pstr;

    {
        //第一种方法
//        while(*p2 != '\0')
//        {
//            if(*p2 == ch)
//            {
//                p2++;
//            }
//            else
//            {
//                *p1++ = *p2++;
//            }
//        }
//        *p1 = *p2;
    }
    {
        //第二种方法
//        while((*p1 = *p2))
//        {
//            if(*p2 == ch)
//            {
//                p2++;
//            }
//            else
//            {
//                p1++;
//                p2++;
//            }
//        }
    }
    {
        //第三种方法
        while((*p1++ = *p2++))
        {
            if(*p2 == ch)
            {
                p2++;
            }
        }
    }
}

//判断字符是不是数字
static _Bool isDigital(char ch)
{
    return ch >= '0' && ch <= '9' ? true : false;
}

//getNumber函数的作用是获得表达式1234 + 456 + 34中的操作数（1234，456，34）
//pindex限定从字符串的什么位置开始检索字符串
static double getNumber(char *pstr, int *pindex)
{
    double db = 0.0;
    int index = *pindex;
    //处理整数部分
    while(isDigital(pstr[index]))
    {
        db *= 10;
        db += pstr[index] - '0';
        index++;
    }
    //处理小数点和小数部分
    if(pstr[index] == '.')
    {
        index++;    //跳过小数点
        //
        //处理小数部分
        double xiaoshu = 1.0;
        while(isDigital(pstr[index]))
        {
            xiaoshu *= 0.1;
            db += xiaoshu * (pstr[index] - '0');
            index++;
        }
    }
    //
    *pindex = index;    //此时index指向表达式中的非数字字符
    return db;
}

static double priorityfenxi(char *pstr, int *pindex)
{
    //int index = *pindex;
    double value = getNumber(pstr, pindex);

    while(1)
    {
        char ch = pstr[*pindex];
        switch(ch)
        {
            case '*':
                (*pindex)++;
                value *= getNumber(pstr, pindex);
                break;
            case '/':
                (*pindex)++;
                value /= getNumber(pstr, pindex);
                break;
            default:
                return value;
        }
    }
}


static double fenxi(char *pstr)
{
    int index = 0;
    double value = priorityfenxi(pstr, &index);

    while(1)
    {
        char ch = pstr[index];
        switch(ch)
        {
            case '\0':
                return value;
            case '+':
                index++;
                value += priorityfenxi(pstr, &index);
                break;
            case '-':
                index++;
                value -= priorityfenxi(pstr, &index);
                break;
            default:
                break;
        }
    }
}

int main括号(int argc, char* argv[])
{
    {
        //123 + 45 + 56.89
        char str[1024] = {0};
        scanf("%[^\n]", str);
        printf("计算表达式是 %s\n", str);
        eraseChar(str, ' ');
        printf("去除空格后的计算表达式是 %s\n", str);


        {
            //函数调用
            double value = fenxi(str);
            printf("%s = %f\n", str, value);
        }

    }
    {
        //char *str = "1 + 2 * (3 + (1 * 2 + 4 * (1 + 3))) - 3 + 2 * (1 + 2)";
    }

    return 0;
}
