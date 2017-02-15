cmake_minimum_required(VERSION 3.6)
project(clion)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp 02.c 03.c 04.c 05.c 输入输出小结.c 位运算.c printscanf.c scanf正则表达式.c 内存实体以及运算符优先级.c)
add_executable(clion ${SOURCE_FILES})