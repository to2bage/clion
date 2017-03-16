//
// Created by apple on 2017/3/16.
//
#include <stdio.h>
#include <stdarg.h>

static void myPrintf(char *pformat, ...)
{
    va_list arg;    //char *
    va_start(arg, pformat);

    char *px = pformat;
    while(*px != '\0')
    {
        if(*px == '%')
        {
            px++;
        }

        switch(*px)
        {
            case 'd':
            {
                int inum = va_arg(arg, int);
                printf("%d", inum);
                break;
            }
            case 'c':
            {
                char ch = va_arg(arg, char);
                putchar(ch);
                break;
            }
            case 's':
            {
                char *pstr = va_arg(arg, char*);
                printf("%s", pstr);
                break;
            }
            case 'f':
            {
                double db = va_arg(arg, double);
                printf("%f", db);
                break;
            }
            default:
                putchar(*px);
                break;
        }
        px++;
    }

    va_end(arg);
}

static void myScanf(char *pformat,...)
{
    va_list ap;
    va_start(ap, pformat);

    //获得用户的输入
//    char ustr[1024] = {0};
//    gets(ustr);     //23 r hello 34.567
//    puts(ustr);
//    char *pu = ustr;

    //解析格式化字符串
    char *px = pformat;
    while(*px != '\0')
    {
        if(*px == '%')
        {
            px++;
        }

        switch(*px)
        {
            case 'd':
            {
                int *pnum = va_arg(ap, int*);
                scanf("%d", pnum);
                printf("%d\n", *pnum);
                break;
            }
            case 'c':
            {
                char *pch = va_arg(ap, char*);
                scanf("%c", pch);
                printf("%c\n", *pch);
                break;
            }
            case 's':
            {
                char *pstr = va_arg(ap, char*);
                scanf("%s", pstr);
                printf("%s\n", pstr);
                break;
            }
            case 'f':
            {
                double *pdb = va_arg(ap, double*);
                scanf("%lf", pdb);
                printf("%f\n", *pdb);
                break;
            }
            default:
                break;
        }

        px++;
    }

    va_end(ap);
}

int mainprintfscanf(int argc, char *argv[])
{
    myPrintf("1234%%%d%c%s%f\n", 123, 'a', "find . -type f", 23.456);

    //scanf
    int num = 0;
    double db = 0.0;
    char str[100]  = {0};
    char ch = 0;
    myScanf("%d%c%s%f", &num, &ch, str, &db);
    printf("num = %d\nch = %c\nstr = %s\ndb = %f\n", num, ch, str, db);

    return 0;
}
