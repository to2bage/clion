//
// Created by apple on 2017/3/21.
//
#include <stdio.h>

int main最长数字字符串(int argc, char *argv[])
{
    char *input = "abc12345hij1234321jl1237ol";
    char *output = NULL;
    int maxlength = 0;

    char *px = input;
    while(*px != '\0')
    {
        char *p1 = px;
        int num = 0;
        while(*p1 >= '0' && *p1 <= '9')
        {
            num++;
            p1++;
        }

        if(num > maxlength)
        {
            maxlength = num;
            output = px;
        }
        px = p1 + 1;
    }

    for(int i = 0; i < maxlength; i++)
    {
        printf("%c", output[i]);
    }
    printf("\n");

    return 0;
}
