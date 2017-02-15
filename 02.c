//
// Created by apple on 2017/2/14.
//

#include <stdio.h>
#include <math.h>
#include <string.h>

float getNewNumber(int pos, int pass, double number)
{
    double frect = 0.0;
    //小数点后的第pos位，pass舍pass+1入
    if (number >= 0.0)
    {
        double temp = number * pow(10, pos - 1); //123.6
        double val = 1.0 - (pass + 1 ) * 0.1; //0.4
        frect = (int)(temp + val) / pow(10, pos - 1);
        return frect;
    }
    else
    {

    }

}

void getThirtyPercent(int chs, double chd, int wos, double wod)
{
    int i = 1;
    while(1)
    {
        // 10 * 1.07
        // 10 * 1.07  * 1.07
        // 10 * 1.07 * 1.07 * 1.07
        double chw = chs * pow(chd, i);
        double wow = wos * pow(wod, i);

        if (chw / wow >= 0.3)
        {
            printf("中国花了%d年, 使得GDP达到了世界的30%%", i);
            break;
        }

        i++;
    }
}

int reverseNumber(int number)
{
    int rect = 0;
    int num = number;
    while(num)
    {
        rect *= 10;
        rect += num % 10;
        num /= 10;
        printf("num => %d\n", num);
    }
    return rect;
}

void itoa(int number, char *pstr, int per)
{
    int num = number;
    int weishu = 0;
    char *pstart = pstr;
    while (num)
    {
        *pstr++ = num % per + '0';
        num /= per;
        weishu++;
    }
//    for(int i = 0; i < weishu; i++)
//    {
//        char chtemp = 0;
//        chtemp = pstr[i];
//        pstr[i] = pstr[weishu - 1 - i];
//        pstr[weishu - 1 - i] = chtemp;
//    }
    printf("转换后的结果是:");
    pstr--;
    while(pstr >= pstart)
    {
        printf("%c", *pstr--);
    }
    printf("\n");
    printf("位数是:%d\n", weishu);
}

void persion(int number, int per)
{
    char str[100] = {0};
    itoa(number, str, per);
    printf("str = %s\n", str);
}

int main02(int argc, char* argv[])
{
    //类似于4舍5入
//    while(1)
//    {
//        printf("请输入数字: ");
//        double dnum = 0.0;
//        scanf("%lf", &dnum); //double类型时， %lf
//        printf("你输入的数字是: %f\n", dnum);
//        double rect = getNewNumber(3, 5, dnum);
//        printf("结果是: %f\n", rect);
//
//    }

    //gdp
//    getThirtyPercent(10, 1.07, 50, 1.02);

    //逆置
//    while (1)
//    {
//        printf("请输入正整数:");
//        int num = 0;
//        scanf("%d", &num);
//        if (num < 0)
//        {
//            printf("必须输入一个正整数!!!!\n");
//            continue;
//        }
//        printf("逆置后的数字是: %d\n", reverseNumber(num));
//    }

    //二进制， 八进制， 16进制
    while (1)
    {
        int number = 0;
        int per = 0;
        printf("请输入数字:");
        scanf("%d", &number);
        printf("请输入要转换的进制数:");
        scanf("%d", &per);
        printf("你输入的内容是: %d:%d\n", number, per);
        persion(number, per);

    }

    return 0;
}
