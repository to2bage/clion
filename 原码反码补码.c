//
// Created by apple on 2017/2/21.
//
#include <stdio.h>

char strym[64] = {0};
char strfm[64] = {0};
char strbm[64] = {0};

static void show(char *px, int weishu)
{
    int i = 0;
    while(i < weishu)
    {
        printf("%c", px[i]);
        (i + 1) % 4 == 0 ? printf(" ") : printf("");
        i++;
    }
    printf("\n");
}
//求补码
static void bmcode(int num)
{
    for(int i = 63; i >= 0; i--)
    {
        if(num & 1)
        {
            strbm[i] = '1';
        }
        else
        {
            strbm[i] = '0';
        }
        num >>= 1;
    }
}
//求反码
static void fmcode(int num)
{
    if(num < 0)
    {
        num -= 1;   //补码-1等于反码
    }
    //将反码按位写入数组
    for(int i = 63; i >= 0; i--)
    {
        if(num & 1)
        {
            strfm[i] = '1';
        }
        else
        {
            strfm[i] = '0';
        }
        num >>= 1;
    }
}
//求原码
static void ymcode(int num)
{
    if(num < 0)
    {
        num -= 1; //获得反码
    }
    for(int i = 63; i >= 0; i--)
    {
        if(num & 1)
        {
            strym[i] = '1';
        }
        else
        {
            strym[i] = '0';
        }
        num >>= 1;
    }
    //对于64位系统，1<<63会越界的，所以使用如下的方法求原码
    for(int i = 1; i < 64; i++)
    {
        strym[i] == '1' ? (strym[i] = '0') : (strym[i] = '1');
    }
}

int main原码反码补码(int argc, char* argv[])
{
    int number = 0;
    printf("请输入要转码的数字:");
    scanf("%d", &number);
    //补码
    bmcode(number);
    show(strbm, 64);
    //反码
    fmcode(number);
    show(strfm, 64);
    //原码
    ymcode(number);
    show(strym, 64);

//    {
//        long n = 1;
//        n <<= 32;
//        bmcode(n);
//        show(strbm, 64);
//    }


    return 0;
}