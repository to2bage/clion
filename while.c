//
// Created by apple on 2017/2/16.
//
#include <stdio.h>

int mainwhile(int argc, char* argv[])
{
    {
        int i = 0;
        int j = 0;

        while(i++ < 5 && ++j < 6)
        {
            printf("hello");
        }
        printf("\n");
    }
    {
        int num = 0;
        //scanf("%d", &num);

        int i = 0;
        int rect = 1;
        while(i++ < num)
        {
            rect *= 2;
        }
        printf("rect = %d\n", rect);
    }
    {
        int i = 5;
        do{
            printf("world\n");
            i--;
        }while (i); //循环5次
    }
    {
        // hello i--=5; hello i--=4; hello i--=3; hello i--=2; hello i--=1; hello
        int i = 5;
        do{
            printf("hello\n");
        }while (i--); //循环6次
    }
    {
        int i = 4;
        int j = 5;
        do
        {
            printf("to2bage\n");
        }
        while (j-- && --i); //循环4次
    }
    {
        int i = 0;
        while(i++ < 4)
        {
            printf("test\n");
        }
    }
    {
        char ch = 0;
        do
        {
            scanf("%c", &ch);
            if (ch >= 'A' && ch <= 'Z')
            {
                ch += 32;
            }
            putchar(ch);
        }
        while(ch != 'Q' && ch != 'q');
    }

    return 0;
}

