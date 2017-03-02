//
// Created by apple on 2017/3/2.
//
#include <stdio.h>
#include <memory.h>

#define M 20
#define N 15

int main交集和并集(int argc, char* argv[])
{
    int a[M] = {1,2,3,4,5,6,7,8,9,0,11,12,13,14,15,16,17,18,19,20};
    int b[N] = {11,12,13,14,15,16,17,18,19,20,21,22,23,24,25};

    {
        //先去重复的数字
        //交集
        int c[N] = {0};     //个数是a和b中个数最少的数量
        int k = 0;
        for(int i = 0; i < N; i++)
        {
            for(int j = 0; j < M; j++)
            {
                if(b[i] == a[j])
                {
                    c[k++] = b[i];
                    break;
                }
            }
        }
        //
        for(int i = 0; i < N; i++)
        {
            c[i] != 0 ? printf("%5d", c[i]) : printf("");
        }
        printf("\n");
    }
    {
        //并集
        int c[M + N] = {0};
        //先将个数少的数字拷贝到c数组中
        int k = 0;
        for(; k < N; k++)
        {
            c[k] = b[k];
        }
        //再判断数组a中的元素不存在与数组b中，则插入数组c中
        for(int i = 0; i < M; i++)
        {
            int flag = 0;
            for(int j = 0; j < N; j++)
            {
                if(a[i] == b[j])
                {
                    flag = 1;
                    break;
                }
            }
            if(flag == 0)
            {
                c[k++] = a[i];
            }
        }
        //
        for(int i = 0; i < N + M; i++)
        {
            c[i] != 0 ? printf("%5d", c[i]) : printf("");
        }
        printf("\n");
    }

    return 0;
}

