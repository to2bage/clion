//
// Created by apple on 2017/2/16.
//
#include <stdio.h>
#include <stdbool.h> //可以使用_Bool

int mainBool(int argc, char* argv[])
{
    _Bool bl = true; //取值true或false ; 或者是非0和0作为其值
    printf("sizeof(_Bool) = %d\n", sizeof(_Bool)); //1个字节
    bl ? printf("我是色狼\n") : printf("你是色狼\n");

    return 0;
}

