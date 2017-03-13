//
// Created by apple on 2017/3/10.
//
#include <stdio.h>

static char str[10] = "abcdefg";
static int op = 1;

static void swap(char *p1, char *p2)
{
    char temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

static void createNumberPwd(char *pstr)
{
   if(*pstr == '\0')
   {
       printf("第%d) %s\n", op++, str);
   }

    for(char *p = pstr; *p != '\0'; p++)
    {
        swap(p, pstr);
        createNumberPwd(pstr + 1);
        swap(pstr, p);
    }
}

int main全排列(int argc, char* argv[])
{
    {
        createNumberPwd(str);
    }
    return 0;
}
