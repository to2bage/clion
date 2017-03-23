//
// Created by apple on 2017/3/23.
//
#include <stdio.h>

struct info
{
    char name[10];
    int age;
};

static void changeInfo(struct info *pinfo)
{

}


int main结构体数组的副本机制(int argc, char *argv[])
{
    {
        //结构体中的数组 有副本机制，
    }

    {
        //结构体数组, 作为参数拷贝的是地址
        struct info infos[3] = {{"hello", 23}, {"world", 12}, {"pog", 34}};

        for(int i = 0; i < 3; i++)
        {
            printf("%s, %d\n", infos[i].name, infos[i].age);
        }
    }

    return 0;
}
