cmake_minimum_required(VERSION 3.6)
project(clion)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp 02.c 03.c 04.c 05.c 输入输出小结.c 位运算.c printscanf.c scanf正则表达式.c 内存实体以及运算符优先级.c 宽字符.c auto.c bool.c 赌博.c 练习.c 查找进程.c test.c 枚举.c while.c for.c 20150403.c 测试whiledo.c 循环总结.c 分离和穷举.c 基本数据类型.c 函数.c 可变参数.c 全局变量.c 线性递归.c 树状递归.c 汉诺塔.c volatile.c 原码反码补码.c 进制转换.c 寄存器变量.c 加减法的位运算的实现.c 最小公倍数最大公约数.c typedef.c 20150409.c 数组.c 迷宫.c 二分查找法.c 小小递归.c 杨辉三角.c 二维数组的地址.c 高维数组.c 洗牌.c 指针.c 内存.c 栈.c myStack.h MyStack.c 蛇和大数相乘.c 交集和并集.c 出现次数问题.c 台阶.c 队列.c 队列.h 测试队列.c 指针加强.c 二级指针.c 指针数组强化.c 线程.c Linux输出中文宽字符.c 指针的算术运算.c 数组的指针和指针的数组.c 迷宫的出路.c 汉诺塔的动态分配内存的实现.c 指针数组.c 数组的三种形式.c 内存分配函数.c 二维数组.c 函数指针.c 函数指针数组.c 函数指针数组与多线程.c 函数返回值的副本机制.c 左值右值.c QQ.c 快速排序的数组实现.c 快速排序的指针实现.c 全排列.c 堆排序变异.c 堆排序.c 字符串.c 字符串常用函数.c 内存动态分配实例.c 五颗星.c 内存操作函数.c 字符串转数字.c 管道字符串.c MyPrintf.c str系列函数.c 宽字符字符串.c 表达式计算加减.c 表达式计算加减乘除.c 表达式计算加减乘除括号.c 字符串删除.c 字符串切割.c strtok练习.c sscanfsprintf.c str基础函数.c str高级.c 字符串插入.c 字符串替换.c 最长数字字符串.c 字符串对称.c 结构体.c 字符串压缩和解压缩.c 字符串哈希和查找.c 结构体嵌套.c)
add_executable(clion ${SOURCE_FILES})