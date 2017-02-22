//
// Created by apple on 2017/2/21.
//
#include <stdio.h>

static void jingzhi(int number, int per)
{
    if(number == 0)
    {
        if(per == 8)
        {
            printf("0");
        }
        else if(per == 16)
        {
            printf("0x");
        }
        return;
    }
    else
    {
        jingzhi(number / per, per);
        if(per == 2)
        {
            printf("%d", number % per);
        }
        else if(per == 8)
        {
            printf("%d", number % per);
        }
        else if(per == 16)
        {
            int temp = number % per;
            switch(temp)
            {
                case 10:
                    printf("A");
                    break;
                case 11:
                    printf("B");
                    break;
                case 12:
                    printf("C");
                    break;
                case 13:
                    printf("D");
                    break;
                case 14:
                    printf("E");
                    break;
                case 15:
                    printf("F");
                    break;
                default:
                    printf("%d", temp);
                    break;
            }
        }
    }
}

int main进制转换(int argc, char* argv[])
{
    {
        jingzhi(234, 16);
        printf("\n");
        jingzhi(234, 8);
        printf("\n");
        jingzhi(234, 2);
        printf("\n");
    }
    return 0;
}

