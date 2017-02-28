//
// Created by apple on 2017/2/28.
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char* argv[])
{
    {
        //初始化数组
        int a[54] = {0};
        for(int i = 0; i < 54; i++)
        {
            printf("%3d", a[i] = i);
        }
        printf("\n");
        //打乱a[54]中元素值的次序
        srand(time(NULL));
        for(int i = 0; i < 54; i++)
        {
            int num = rand() % (54 - i);
            //交换索引i 和 num的值
            int temp = a[54 - 1 - i];
            a[54 - 1 - i] = a[num];
            a[num] = temp;
        }
        //show
        for(int i = 0; i < 54; i++)
        {
            printf("%3d", a[i]);
        }
        printf("\n");
    }

    return 0;
}
