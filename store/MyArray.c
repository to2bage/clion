//
// Created by apple on 2017/3/27.
//

#include "MyArray.h"

//初始化
void init(MyArray *parr)
{
    if(parr == NULL)
    {
        printf("数组库对象为空\n");
        return;
    }
    parr->pstart = NULL;
    parr->length = 0;
    parr->sortState = 0;
}
void initWithData(MyArray *parr, datatype data)
{
    if(parr == NULL)
    {
        printf("数组库对象为空\n");
        return;
    }
    parr->length = 1;
    parr->sortState = 1;
    parr->pstart = (datatype *)malloc(parr->length * sizeof(datatype));
    memset(parr->pstart, 0, parr->length * sizeof(datatype));

    parr->pstart[0] = data;
}
void initWithArray(MyArray *parr, datatype *arr, datatype len)
{
    if(parr == NULL)
    {
        printf("数组库对象为空\n");
        return;
    }
    parr->length = len;
    parr->sortState = 0;
    parr->pstart = (datatype *)malloc(parr->length * sizeof(datatype));
    memset(parr->pstart, 0, parr->length * sizeof(datatype));
    memcpy(parr->pstart, arr, len * sizeof(datatype));
}

//显示
void showMyArray(MyArray *parr)
{
    if(parr == NULL || parr->pstart == NULL || parr->length == 0)
    {
        printf("数组库是空的\n");
        return;
    }
    else
    {
        printf("数组库的数组:\n");
        for(int i = 0; i < parr->length; i++)
        {
            printf("%5d", parr->pstart[i]);
        }
        printf("\n");
    }
}

//查找
datatype *findfirst(MyArray *parr, datatype data)
{
    if(parr == NULL || parr->pstart == NULL || parr->length == 0)
    {
        printf("数组库为空\n");
        return NULL;
    }

    for(int i = 0; i < parr->length; i++)
    {
        if(parr->pstart[i] == data)
        {
            return parr->pstart + i;
        }
    }

    return NULL;
}
Rect findall(MyArray *parr, datatype data)
{
    Rect rect;
    rect.len = 0;
    rect.ppstart = NULL;


    if(parr == NULL || parr->pstart == NULL || parr->length == 0)
    {
        printf("数组库为空\n");
        return rect;
    }

    datatype *p1 = parr->pstart;
    datatype *pend = parr->pstart + parr->length - 1;
    while(p1 <= pend)
    {
        if(*p1 == data)
        {
            if(rect.len == 0)
            {
                rect.len = 1;
                rect.ppstart = (datatype **)malloc(rect.len * sizeof(datatype *));
                memset(rect.ppstart, 0, rect.len * sizeof(datatype *));
                rect.ppstart[0] = p1;
            }
            else
            {
                rect.len += 1;
                rect.ppstart = (datatype **)realloc(rect.ppstart, rect.len * sizeof(datatype *));
                rect.ppstart[rect.len - 1] = p1;
            }
        }
        p1++;
    }


    return rect;
}

//尾部插入
void addobject(MyArray *parr, datatype data)
{
    if(parr == NULL)
    {
        printf("数组库对象为空\n");
        return;
    }
    else if(parr->pstart == NULL || parr->length == 0)
    {
        initWithData(parr, data);
    }
    else
    {
        parr->length += 1;
        parr->sortState = 0;
        parr->pstart = (datatype *)realloc(parr->pstart, parr->length * sizeof(datatype));
        parr->pstart[parr->length - 1] = data;
    }


}
void addobjects(MyArray *parr, datatype *pdata, int len)
{
    if(parr == NULL)
    {
        printf("数组库对象为空\n");
        return;
    }
    else if(parr->pstart == NULL || parr->length == 0)
    {
        initWithArray(parr, pdata, len);
    }
    else
    {
        parr->sortState = 0;
        parr->pstart = (datatype *)realloc(parr->pstart, (parr->length + len) * sizeof(datatype));
        memcpy(parr->pstart + parr->length, pdata, len * sizeof(datatype));
        parr->length += len;
    }

}
//任意位置前部插入
void insertobject(MyArray *parr, datatype findobj, datatype insertobj)
{
    if(parr == NULL || parr->pstart == NULL || parr->length == 0)
    {
        printf("数组库为空，不能插入数据\n");
        return;
    }

    datatype *pos = findfirst(parr, findobj);
    if(pos == NULL)
    {
        printf("没有找到%d, 不能插入%d\n", findobj, insertobj);
        return;
    }

    parr->pstart = (datatype *)realloc(parr->pstart, (parr->length + 1) * sizeof(datatype));
    datatype *pend = parr->pstart + parr->length - 1;
    while(pend >= pos)
    {
        *(pend + 1) = *pend;
        pend--;
    }
    parr->pstart[pos - parr->pstart] = insertobj;
    parr->length += 1;
    parr->sortState = 0;
}
void insertobjects(MyArray *parr, datatype findobj, datatype *pdata, int len)
{
    if(parr == NULL || parr->pstart == NULL || parr->length == 0)
    {
        printf("数组库为空，不能插入数据\n");
        return;
    }

    datatype *pos = findfirst(parr, findobj);
    if(pos == NULL)
    {
        printf("没有找到%d, 不能插入\n", findobj);
        return;
    }

    parr->pstart = (datatype *)realloc(parr->pstart, (parr->length + len) * sizeof(datatype));
    datatype *pend = parr->pstart + parr->length - 1;
    while(pend >= pos)
    {
        *(pend + len) = *pend;
        pend--;
    }

    memcpy(parr->pstart + (pos - parr->pstart), pdata, len * sizeof(datatype));
    parr->length += len;
    parr->sortState = 0;
}

//删除
void deletefirstobj(MyArray *parr, datatype deleteobj)
{
    if(parr == NULL || parr->pstart == NULL || parr->length == 0)
    {
        printf("数组库为空\n");
        return;
    }
    datatype *pos = findfirst(parr, deleteobj);
    if(pos == NULL)
    {
        printf("没有找到要删除的元素%d\n", deleteobj);
        return;
    }

    for(int i = pos - parr->pstart + 1; i < parr->length; i++)
    {
        parr->pstart[i - 1] = parr->pstart[i];
    }

    parr->length -= 1;
    parr->pstart = (datatype *)realloc(parr->pstart, parr->length * sizeof(datatype));
}
void deleteallobj(MyArray *parr, datatype deleteobj)
{
    if(parr == NULL || parr->pstart == NULL || parr->length == 0)
    {
        printf("数组库为空\n");
        return;
    }

    int count = 0;
    datatype *p1 = parr->pstart;
    datatype *p2 = parr->pstart;
    datatype *pend = parr->pstart + parr->length - 1;

    while(p2 <= pend)
    {
        if(*p2 == deleteobj)
        {
            p2++;
            count++;
        }
        else
        {
            p1++;
            p2++;
        }

        *p1 = *p2;
    }

    parr->length -= count;
    parr->pstart = (datatype *)realloc(parr->pstart, parr->length * sizeof(datatype));
}

//修改
void changefirstobj(MyArray *parr, datatype oldobj, datatype newobj)
{
    if(parr == NULL || parr->pstart == NULL || parr->length == 0)
    {
        printf("数组库为空\n");
        return;
    }
    datatype *pos = findfirst(parr, oldobj);
    if(pos == NULL)
    {
        printf("没有找到要删除的元素%d\n", oldobj);
        return;
    }

    parr->pstart[pos - parr->pstart] = newobj;
}
void changeallobj(MyArray *parr, datatype oldobj, datatype newobj)
{
    if(parr == NULL || parr->pstart == NULL || parr->length == 0)
    {
        printf("数组库为空\n");
        return;
    }

    datatype *p1 = parr->pstart;
    datatype *p2 = parr->pstart;
    datatype *pend = parr->pstart + parr->length - 1;

    while(pend >= p2)
    {
        if(*p2 == oldobj)
        {
            *p2 = newobj;
        }
        *p1++ = *p2++;
    }

}

//排序
void selectsortArray(MyArray *parr)
{
    {
        for(int i = 0; i < parr->length; i++)
        {
            int min = i;
            for(int j = i + 1; j < parr->length; j++)
            {
                if(parr->pstart[j] < parr->pstart[min])
                {
                    min = j;
                }
            }

            datatype temp = parr->pstart[min];
            parr->pstart[min] = parr->pstart[i];
            parr->pstart[i] = temp;
        }
    }
}
void bublesortArray(MyArray *parr)
{
    {
        for(int i = 0; i < parr->length - 1; i++)
        {
            for(int j = 0; j < parr->length - 1 - i; j++)
            {
                if(parr->pstart[j] > parr->pstart[j + 1])
                {
                    datatype temp = parr->pstart[j];
                    parr->pstart[j] = parr->pstart[j + 1];
                    parr->pstart[j + 1] = temp;
                }
            }
        }
    }
}
void insertsortArray(MyArray *parr)
{
    {
        for(int i = 0; i < parr->length - 1; i++)
        {
            for(int j = i + 1; j < parr->length; j++)
            {
                int k = j - 1;
                int temp = parr->pstart[j];

                while(k >= 0 && parr->pstart[k] > temp)
                {
                    k--;
                }
                k++;

                for(int m = j - 1; m >= k; m--)
                {
                    parr->pstart[m + 1] = parr->pstart[m];
                }

                parr->pstart[k] = temp;
            }
        }
    }
}
datatype *getArchor(datatype *pstart, datatype *pend)
{

        datatype archor = *pstart;
        datatype *pleft = pstart;
        datatype *pright = pend;

        while(pleft <= pright)
        {
            //从左向右找到比archor大的值
            while (*pleft <= archor && pleft <= pend)
            {
                pleft++;
            }//pleft指向比archor大的值

            //从右先左找到比archor小的值
            while(*pright >= archor && pright > pstart)
            {
                pright--;
            }//pright指向比archor小的值

            if(pleft <= pright)
            {
                datatype temp = *pleft;
                *pleft = *pright;
                *pright = temp;
            }
        }
        //pright始终指向<=archor的值
        datatype temp = *pstart;
        *pstart = *pright;
        *pright = temp;

        return pright;

}
void quicksortArray(datatype *pstart, datatype *pend)
{
    if(pstart <= pend)
    {
        datatype *parchor = getArchor(pstart, pend);
        quicksortArray(pstart, parchor - 1);
        quicksortArray(parchor + 1, pend);
    }
}

void heapsortAjust(datatype *parr, int curIndex, int endIndex)
{
    for(int i = 2 * curIndex + 1; i <= endIndex; i = 2 * i + 1)
    {
        if(i < endIndex && parr[i] < parr[i + 1])
        {
            i++;
        }

        if(parr[i] > parr[curIndex])
        {
            datatype temp = parr[i];
            parr[i] = parr[curIndex];
            parr[curIndex] = temp;
            //
            curIndex = i;
        }
    }
}
void heapsortArray(datatype *parr, int endIndex)
{
    for(int i = (endIndex - 1) / 2; i >= 0; i--)
    {
        heapsortAjust(parr, i, endIndex);
    }

    for(int i = endIndex; i >= 0; i--)
    {
        //
        datatype temp = parr[0];
        parr[0] = parr[i];
        parr[i] = temp;

        //
        heapsortAjust(parr, 0, i - 1);
    }
}

