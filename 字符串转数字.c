//
// Created by apple on 2017/3/15.
//
#include <stdio.h>
#include <stdlib.h>

static int myatoi(char *parr)
{
    char *px = parr;
    int rect = 0;
    while(*px != '\0')
    {
        if(*px < '0' || *px > '9')
        {
            break;
        }

        rect *= 10;
        int num = *px - '0';
        rect += num;
        px++;
    }
    return rect;
}

static char *myitoa(int number, char **pparr)
{
    int num = number;
    //获得num的位数
    int weishu = 0;
    while(num /= 10)
    {
        weishu++;
    }

    *pparr = (char *)calloc(weishu + 1, sizeof(char));
    char *pend = *pparr + weishu;
    num = number;
    while(num)
    {
        *pend-- = (num % 10) + '0';
        num /= 10;
    }

    return *pparr;
}

static double myatof(char *parr)
{
    char *px = parr;
    double db = 0.0;
    int sign = 1;

    //处理符号
    if(*px == '-')
    {
        sign *= -1;
        px++;
    }
    else if(*px == '+')
    {
        sign *= 1;
        px++;
    }
    else if(*px < '0' || *px > '9')
    {
        return db;
    }

    //处理整数部分
    while(*px != '.')
    {
        db *= 10;
        db += *px - '0';
        px++;
    }
    //printf("整数部分是: %f\n", db);
    px++;   //跳过小数点部分

    //处理小数部分
    double t = 1;
    while(*px != '\0')
    {
        t *= 0.1;
        db += t * (*px - '0');
        px++;
    }


    //返回
    db *= sign;
    return db;
}

//-1234.5678
static void myftoa(double db, char *parr)
{
    char *px = parr;

    //处理符号
    if(db < 0)
    {
        *px = '-';
        db *= -1;
        px++;
    }

    //分离出double数据的整数部分和小数部分
    int zhengshu = (int)db;
    double xiaoshu = db - (int)db;      //注意：这里是db-(int)db;

    //处理整数部分
    ////获得整数的位数
    int zhengshuweishu = 0;
    int z = zhengshu;
    while(z)
    {
        zhengshuweishu++;
        z /= 10;
    }
    //printf("%d\n", zhengshuweishu);
    ////将整数部分填入字符串数组
    char *pend = px + zhengshuweishu - 1;
    while(zhengshu)
    {
        *pend-- = (zhengshu % 10) + '0';
        zhengshu /= 10;
    }
    //printf("字符串的整数部分: %s\n", parr);

    //处理小数点部分
    px += zhengshuweishu;
    *px = '.';
    px++;       //px指针后移一位，指向小数部分的第一位
    //printf("字符串的整数部分和小数点部分: %s\n", parr);

    //处理小数部分0.5678
    ////因为浮点数据只能处理小数点6位，所以这里设小数位数为6
    int xiaoshuweishu = 6;
    while(xiaoshuweishu > 0)
    {
        int temp = (int)(xiaoshu * 10);
        *px++ = temp + '0';
        xiaoshu = xiaoshu * 10 - temp;
        xiaoshuweishu--;
    }

}


int main字符串转数字(int argc, char* argv[])
{
    {
        char str[10] = "12345";
        //int num = atoi(str);        //只能转换10进制
        int num = myatoi(str);
        printf("%4d\n", num);

        char *p = NULL;
        char *px = myitoa(num, &p);
        printf("%s\n", px);
        printf("%s\n", p);

    }
    {
        //atof
        char str[20] = "-1278.345678";
        double rect = myatof(str);
        printf("%f\n", rect);
    }
    {
        //ftoa
        char str[20] = {0};
        double db = -1234.5678;
        myftoa(db, str);
        printf("%s\n", str);
    }

    return 0;
}

