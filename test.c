//
// Created by apple on 2017/2/16.
//
#include <stdio.h>
#include <math.h>

int maintest(int argc, char* argv[])
{
    {
//        int a, b;
//        scanf("%d, %d", &a, &b);
//        printf("a = %d, b = %d\n", a, b);
//        int a_abs, b_abs;
//        a_abs = a > 0 ? a : -a;
//        b_abs = b > 0 ? b : -b;
//        a_abs > b_abs ? printf("%d和%d中绝对值最大值是%d\n", a, b, a) : printf("%d和%d中绝对值最大值是%d\n", a, b, b);
    }
    {
        //y = a * x * x + b * x + c;
        double a, b, c;
        scanf("%lf%lf%lf", &a, &b, &c);

        if (a == 0)
        {
            //一元一次方程
            if (b == 0)
            {
                if (c == 0)
                {
                    printf("x可以为任意值\n");
                }
                else
                {
                    printf("无解！！！");
                }
            }
            else
            {
                printf("x = %.2f\n", -1 * c / b);
            }
        }
        else
        {
            double db = b * b - 4 * a * c;
            if (db == 0)
            {
                printf("x = %.2f\n", -1 * b / 2 / a);
            }
            else if (db > 0)
            {
                //实根
                printf("x1 = %.2f, x2 = %.2f\n", (-1 * b + sqrt(b * b - 4 * a * c)) / 2 / a, (-1 * b - sqrt(b * b - 4 * a * c)) / 2 / a);
            }
            else
            {
                //虚根
                double p = -1 * b / 2 / a;
                double q = sqrt(-1 * (b * b - 4 * a * c)) / 2 / a;
                char str1[100] = {0};
                char str2[100] = {0};
                sprintf(str1, "%.2f + %.2fi", p, q);
                sprintf(str2, "%.2f - %.2fi", p, q);
                printf("x1 = %s, x2 = %s\n", str1, str2);
            }
        }

    }
    return 0;
}
