//
// Created by apple on 2017/3/7.
//
#include <stdio.h>

int main指针的数组和数组的指针(int argc, char* argv[])
{
    {
        int *p1[10];    //指针数组  80字节
        int (*p2)[10];  //指向有10个元素的数组的指针 8个字节
        printf("sizeof(p1) = %lu, sizeof(p2) = %lu\n", sizeof(p1), sizeof(p2));
    }
    {
        //指针数组
        int a[10] = {0,9,2,8,3,7,4,6,5,10};
        int *p[10] = {NULL};
        for(int i = 0; i < 10; i++)
        {
            p[i] = a + i;
            printf("%4d", *p[i]);
        }
        printf("\n");
        //
        {
            for(int **px = p + 9; px >= p; px--)
            {
                //printf("%4d", **px);
                for(int **qx = p + 9; qx >= p + 1; qx--)
                {
                    if(**qx > **(qx - 1))
                    {
                        int *ptemp = *qx;
                        *qx = *(qx - 1);
                        *(qx - 1) = ptemp;
                    }
                }
            }

            for(int i = 0; i < 10; i++)
            {
                printf("%4d", *p[i]);
            }
        }

        //
        {
//            for(int **px = p; px < p + 10 - 1; px++)
//            {
//                for(int **qx = p; qx < p + 10 - 1; qx++)
//                {
//                    if(**qx < **(qx + 1))
//                    {
//                        int *ptemp = *qx;
//                        *qx = *(qx + 1);
//                        *(qx + 1) = ptemp;
//                    }
//                }
//            }
//            for(int i = 0; i < 10; i++)
//            {
//                printf("%4d", *p[i]);
//            }
//            printf("\n");
        }

    }
    {
        //数组指针
        int a[10] = {1,2,3,4,5,6,7,8,9,10};
        int (*p)[10] = NULL;
        p = &a;
    }

    return 0;
}
