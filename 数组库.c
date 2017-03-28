//
// Created by apple on 2017/3/27.
//
#include "store/MyArray.h"
#include "store/MyArrStr.h"
#include "store/MyString.h"
#include <time.h>


int main(int argc, char *argv[])
{
    {
        //int double char
        MyArray mydata;
        srand(time(NULL));
        int num = 0;
        int a[10] = {-1, 1, 2, 3,4,5,6,7,8,9};
        for(int i = 0; i < 10; i++)
        {
            back:
            num = rand() % 100;
            if(num == 0)
            {
                goto back;
            }
            a[i] = num;
        }
        initWithArray(&mydata, a, 10);
        showMyArray(&mydata);

        int b[5] = {11,12,13,14,99};
        addobject(&mydata, 200);
        addobjects(&mydata, b, 5);
        showMyArray(&mydata);

        insertobject(&mydata, 12, 66);
        showMyArray(&mydata);

        insertobjects(&mydata, 14, b, 3);
        showMyArray(&mydata);

        deletefirstobj(&mydata, 11);
        showMyArray(&mydata);

        deleteallobj(&mydata, 12);
        showMyArray(&mydata);

        //changefirstobj(&mydata, 13, 33);
        changeallobj(&mydata, 13, 33);
        showMyArray(&mydata);

        Rect rec = findall(&mydata, 33);
        for(int i = 0; i < rec.len; i++)
        {
            printf("%p, %d\n", rec.ppstart[i], *rec.ppstart[i]);
        }
        printf("\n");

        //sort
        //selectsortArray(&mydata);
        //bublesortArray(&mydata);
        //insertsortArray(&mydata);
        //quicksortArray(mydata.pstart, mydata.pstart + mydata.length - 1);
        heapsortArray(mydata.pstart, mydata.length - 1);

        showMyArray(&mydata);

    }

    {
        //char*

    }

    return 0;
}
