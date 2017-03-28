//
// Created by apple on 2017/3/27.
//

#include "MyString.h"

void initStr(void *p, char ch)    //ch=a窄字符；ch=w宽字符
{
    if(ch == 'w')
    {
        StrW *pstrw = (StrW *)p;
        pstrw->pw = NULL;
        pstrw->memlength = 0;
    }
    else if(ch == 'a')
    {
        StrA *pstra = (StrA *)p;
        pstra->pa = NULL;
        pstra->memlength = 0;
    }
    else
    {
        abort();        //异常
    }
}
void initStrWithStr(void *p, char ch, void *pstr)
{
    if(ch == 'w')
    {
        StrW *pstrw = (StrW *)p;
        wchar_t  *pw = (wchar_t *)pstr;
        int len = wcslen(pw);   //字符的个数
        pstrw->pw = (wchar_t *)malloc((len + 1) * sizeof(wchar_t));
        memset(pstrw->pw, 0, (len + 1) * sizeof(wchar_t));
        wcscpy(pstrw->pw, pw);
        pstrw->memlength = (len + 1);
    }
    else if(ch == 'a')
    {
        StrA *pstra = (StrA *)p;
        char *pa = (char *)pstr;
        int len = strlen(pa);
        pstra->pa = (char *)malloc((len + 1) * sizeof(char));
        memset(pstra->pa, 0, (len + 1) * sizeof(char));
        strcpy(pstra->pa, pa);
        pstra->memlength = len + 1;
    }
    else
    {
        abort();        //异常
    }
}


void showMyStr(void *p, char ch)
{
    if(ch == 'w')
    {
        StrW *pstrw = (StrW *)p;
        if(pstrw->pw)
        {
            wprintf(L"%ls\n", pstrw->pw);
        }
    }
    else if(ch == 'a')
    {
        StrA *pstra = (StrA *)p;
        if(pstra->pa)
        {
            printf("%s\n", pstra->pa);
        }
    }
    else
    {
        abort();        //异常
    }
}