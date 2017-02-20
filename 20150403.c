//
// Created by apple on 2017/2/16.
//
#include <stdio.h>

//递归实现阶乘
double jieceng(double number)
{
    if(number == 1)
    {
        return 1.0;
    }
    else
    {
        return number * jieceng(number - 1.0);
    }
}

void sumAndMuti(int dstart, int dsum, double dmul)
{
    if(dstart == 100)
    {
        printf("从%d开始的，100之内的偶数之积是%.3f, 奇数之和是%d\n", dstart, dmul, dsum);
        return;
    }
    else
    {
        if(dstart % 2 == 0)
        {
            dsum += dstart;
        }
        else
        {
            dmul *= dstart;
        }
        sumAndMuti(dstart + 1, dsum, dmul);
    }
}

int main0403(int argc, char* argv[])
{
    {
//        while(1)
//        {
//            char ch = 0;
//            scanf("%c", &ch);
//            getchar(); //取出回车
//
//            printf("你输入的字符是: %c\n", ch);
//
//            if(ch >= 'a' && ch <= 'z')
//            {
//                printf("输出： %c\n", ch - 32);
//            }
//            else if(ch >= 'A' && ch <= 'Z')
//            {
//                printf("输出： %c\n", ch + 32);
//            }
//            else if(ch >= '0' && ch <= '9')
//            {
//                printf("输出： %d\n", ch - '0');
//            }
//            else if(ch == ' ')
//            {
//                printf("输出： %s\n", "space");
//            }
//            else
//            {
//                printf("输出: other");
//            }

//            int num = 1;
//            AAA:
//            printf("请输入1-7之间的整数:");
//            scanf("%d", &num);
//            if(num < 1 || num > 7)
//            {
//                printf("输入错误！！！\n");
//                goto AAA;
//            }
//            printf("你输入的整数是: %d\n", num);
//            switch(num)
//            {
//                case 1:
//                    printf("星期一\n");
//                    break;
//                case 2:
//                    printf("星期二\n");
//                    break;
//                case 3:
//                    printf("星期三\n");
//                    break;
//                case 4:
//                    printf("星期四\n");
//                    break;
//                case 5:
//                    printf("星期五\n");
//                    break;
//                case 6:
//                    printf("星期六\n");
//                    break;
//                case 7:
//                    printf("星期日\n");
//                    break;
//                default:
//                    goto AAA;
//            }
//        }
    }
    {
        //阶乘
//        double dnumber = 0.0;
//        scanf("%lf", &dnumber);
//        double rect = jieceng(dnumber);
//        printf("%.2f的阶乘的结果是: %.2f\n", dnumber, rect);
    }
    {
        //100之内的奇数之和，偶数之积
        sumAndMuti(1, 0, 1.0);
        //
        int sum = 0;
        double mul = 1.0;
        for(int i = 1; i < 100; i++)
        {
            i % 2 == 0 ? (mul *= i) : (sum += i);
        }
        printf("偶数之积是：%.3f, 奇数之和是: %d\n", mul, sum);
    }
    {
        char str[100] = {0};
        int number = 0;
        scanf("%[^\n]%n", str, &number);
        printf("你输入的字符串是: %s, 共有%d个字符\n", str, number);
        int i = 0;
        int alpha = 0;
        int num = 0;
        int space = 0;
        int other = 0;
        do
        {
            if((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))
            {
                alpha++;
            }
            else if(str[i] >= '0' && str[i] <= '9')
            {
                num++;
            }
            else if(str[i] == ' ')
            {
                space++;
            }
            else
            {
                other++;
            }
//            i++;
        }
        while(++i < number);
        printf("%s中字母有%d个, 数字有%d个, 空格有%d个, 其他字符有%d个\n", str, alpha, num, space, other);
    }


    return 0;
}
