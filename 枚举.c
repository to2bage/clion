//
// Created by apple on 2017/2/16.
//
#include <stdio.h>

int main枚举(int argc, char* argv[])
{
    enum week{星期一, 星期二, 星期三, 星期四, 星期五, 星期六, 星期日};

    printf("%d\n", 星期一); //0
    printf("%d\n", 星期二); //1
    printf("%d\n", 星期三); //2
    printf("%d\n", 星期日); //6

    enum week week1 = 星期四; //enum week 是类型   week1是变量名
    enum week week2 = 5;
    printf("%d\n", week2); //5

    if (week1 == 3)
    {
        printf("星期四\n"); //
    }
    else
    {
        printf("error");
    }

    //枚举可以指定整型值(int)
    enum rank{司令 = 10, 军长 = 9};
    enum 编制{士兵=1, 班=12, 排=36, 连=108, 营=324, 团=972};

    //switch只能是整型和枚举类型
    enum 编制 bianzhi = 1;
    scanf("%d", &bianzhi);
    printf("你输入的编制是：%d\n", bianzhi);
    switch (bianzhi)
    {
        case 士兵:
            printf("一个士兵\n");
            break;
        case 班:
            printf("%d名士兵\n", 班);
            break;
        case 排:
            printf("%d名士兵\n", 排);
            break;
        case 连:
            printf("%d名士兵\n", 连);
            break;
        case 营:
            printf("%d名士兵\n", 营);
            break;
        case 团:
            printf("%d名士兵\n", 团);
            break;
        default:
            printf("i dont know....\n");
            break;


    }
    {
        enum level{one, two, three, four};//默认 0， 1， 2， 3
        double face[4] = {97.9, 23.67, 98.0, 60.5};

        for(enum level lev = one; lev <= four; lev++)
        {
            printf("%8.2f", face[lev]);
        }
        printf("\n");
    }


    return 0;
}
