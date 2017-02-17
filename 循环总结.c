//
// Created by apple on 2017/2/17.
//
#include <stdio.h>

int main(int argc, char* argv[])
{
    {
//        int num = 0;
//        scanf("%d", &num);
//        int i = 0;
//        while(num && ++i)
//        {
//            num /= 10;
//        }
//        printf("数字的位数是: %d\n", i);
    }
    {
//        int num = 0;
//        scanf("%d", &num);
//        int i = 0;
//        for(;num;i++)
//        {
//            num /= 10;
//        }
//        printf("数字的位数是: %d\n", i);
    }
    {
//        int num = 0;
//        scanf("%d", &num);
//        int i = 0;
//        if(num == 0)    //处理dowhile的先执行一次的行为
//        {
//            i = 0;
//        }
//        else
//        {
//            do
//            {
//                num /= 10;
//            }
//            while(++i && num);
//        }
//        printf("数字的位数是: %d\n", i);
    }
    {
//        for(int i = 1; i <= 9; i++)
//        {
//            for(int j = 1; j <= 9; j++)
//            {
//                printf("%2d * %2d = %2d ", i, j, i * j);
//                if (j == i)
//                {
//                    printf("\n");
//                    break;
//                }
//            }
//        }
    }
    {
        //
        for(int i = 0; i < 10; i++)
        {
            for(int j = 0; j < 10; j++)
            {
                printf("(%d%d) ", i, j);
            }
            printf("\n");
        }
        printf("\n");
    }
    {
        //左下角
        for(int i = 0; i < 10; i++)
        {
            for(int j = 0; j < 10; j++)
            {
                if(i >= j)
                {
                    printf("(%d%d) ", i, j);
                }
            }
            printf("\n");
        }
        printf("\n");
    }
    {
        //右上角
        for(int i = 0; i < 10; i++)
        {
            for(int j = 0; j < 10; j++)
            {
                if(i <= j)
                {
                    printf("(%d%d) ", i, j);
                }
                else
                {
                    printf("     ");    //必须有，否则上面打印的会掉下来
                }
            }
            printf("\n");
        }
        printf("\n");
    }
    {
        //左上角
        for(int i = 0; i < 10; i++)
        {
            for(int j = 0; j < 10; j++)
            {
                printf("(%d%d) ", i, j);
                if (i + j == 9)
                {
                    break;
                }
            }
            printf("\n");
        }
        printf("\n");
    }
    {
        //右下角
        for(int i = 0; i < 10; i++)
        {
            for(int j = 0; j < 9 - i; j++)
            {
                printf("     ");
            }
            for(int j =  9 - i; j < 10; j++)
            {
                printf("(%d%d) ", i, j);
            }
            printf("\n");
        }
        printf("\n");
    }
    {
        //316 = 11 * i + 13 * j;
        for(int i = 0; i < 316 / 11; i++)
        {
            if ((316 - 11 * i) % 13 == 0 && 316 - 11 * i >= 0)
            {
                printf("i = %d, j = %d\n", i, (316 - 11 * i) / 13);
                //break;
            }
        }
    }
    {
        //百鸡百钱
        // 5 * gong + 3 * mu  + 1/3 * xiao = 100;
        // gong + mu + xiao = 100;
        for(int gong = 0; gong <= 20; gong++)
        {
            for(int mu = 0; mu <= 34; mu++)
            {
                if ((100 - gong - mu) % 3  == 0 && (100 - 5 * gong - 3 *mu) * 3 == 100 - gong - mu)
                {
                    printf("公鸡有%d只, 母鸡有%d只, 小鸡有%d只\n", gong, mu, 100 - gong - mu);
//                    break;
                }
            }
        }
    }


    return 0;
}
