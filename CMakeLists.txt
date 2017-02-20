cmake_minimum_required(VERSION 3.6)
project(clion)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp 02.c 03.c 04.c 05.c 输入输出小结.c 位运算.c printscanf.c scanf正则表达式.c 内存实体以及运算符优先级.c 宽字符.c auto.c bool.c 赌博.c 练习.c 查找进程.c test.c enum.c while.c for.c 20150403.c 测试whiledo.c 循环总结.c 分离和穷举.c 基本数据类型.c 函数.c 可变参数.c)
add_executable(clion ${SOURCE_FILES})