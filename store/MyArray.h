//
// Created by apple on 2017/3/27.
//


#ifndef CLION_MYARRAY_H
#define CLION_MYARRAY_H

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

#define datatype int

struct myarray
{
    datatype *pstart;           //数组的首地址
    datatype length;            //数组的实际长度
    int sortState;              //有序1/无序0
};

typedef struct myarray MyArray;

struct rect
{
    datatype **ppstart;         //指针数组， 存贮找到的指针的地址
    int len;
};

typedef struct rect Rect;


//因为这里定义的形式参数是一级指针，所以实际参数只能是栈上的变量
void init(MyArray *parr);
void initWithData(MyArray *parr, datatype data);
void initWithArray(MyArray *parr, datatype *arr, datatype len);

void showMyArray(MyArray *parr);
//查找
datatype *findfirst(MyArray *parr, datatype data);
Rect findall(MyArray *parr, datatype data);

//尾部插入
void addobject(MyArray *parr, datatype data);
void addobjects(MyArray *parr, datatype *pdata, int len);
//任意位置前部插入
void insertobject(MyArray *parr, datatype findobj, datatype insertobj);
void insertobjects(MyArray *parr, datatype findobj, datatype *pdata, int len);

//删除
void deletefirstobj(MyArray *parr, datatype deleteobj);
void deleteallobj(MyArray *parr, datatype deleteobj);

//修改
void changefirstobj(MyArray *parr, datatype oldobj, datatype newobj);
void changeallobj(MyArray *parr, datatype oldobj, datatype newobj);

//排序
void selectsortArray(MyArray *parr);
void bublesortArray(MyArray *parr);
void insertsortArray(MyArray *parr);
datatype *getArchor(datatype *pstart, datatype *pend);
void quicksortArray(datatype *pstart, datatype *pend);
void heapsortAjust(datatype *parr, int curIndex, int endIndex);
void heapsortArray(datatype *parr, int endIndex);


#endif //CLION_MYARRAY_H
