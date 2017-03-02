//
// Created by apple on 2017/3/2.
//
#include <stdio.h>
#include <stdlib.h>

#define N 20

int main出现次数问题(int argc, char* argv[])
{
    {
        int a[N] = {1,2,3,1,2,9,9,10,11,12,1,2,1,2,2,2,1,10,11,98};
        struct password
        {
            int num; //数据值
            int count;//数据值出现的次数
        };

        struct password pass[N] = {0};
        struct password *pa = (struct password *)calloc(0, sizeof(struct password));

        //排序
        for(int i = 0; i < N - 1; i++)
        {
            for(int j = 0; j < N - i - 1; j++)
            {
                if(a[j] > a[j + 1])
                {
                    int temp = a[j];
                    a[j] = a[j + 1];
                    a[j + 1] = temp;
                }
            }
        }
        //
        for(int i = 0; i < N; i++)
        {
            printf("%5d", a[i]);
        }
        printf("\n");
        //统计数据
        {
            int *p1, *p2;
            p1 = p2 = a;
            int i = 0;

            while(p2 < a + N)
            {
                int cishu = 0;
                while(*p1 == *p2 && p2 <= a + N - 1)
                {
                    cishu++;
                    p2++;
                }
                pass[i].num = *p1;
                pass[i++].count = cishu;
                p1 = p2;
            }
            //
            for(int j = 0; j < i; j++)
            {
                printf("%3d(%d)", pass[j].num, pass[j].count);
            }
            printf("\n");
            //排序struct password数组
            for(int m = 0; m < i - 1; m++)
            {
                for(int n = 0; n < i - m - 1; n++)
                {
                    if(pass[n].count < pass[n + 1].count)
                    {
                        int tempcount = pass[n].count;
                        pass[n].count = pass[n + 1].count;
                        pass[n + 1].count = tempcount;

                        int tempnum = pass[n].num;
                        pass[n].num = pass[n + 1].num;
                        pass[n + 1].num = tempnum;
                    }
                }
            }
            for(int j = 0; j < i; j++)
            {
                printf("%3d(%d)", pass[j].num, pass[j].count);
            }
        }

    }

    return 0;
}

