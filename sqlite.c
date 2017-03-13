//
// Created by apple on 2017/3/13.
//
#include <stdio.h>

#include "sqlite3.h"

char path[100] = "/Users/apple/Desktop/to2bage.sqlite";

int main(int argc, char* argv[])
{
    {
        // 打开（创建）数据库
        sqlite3 *db = NULL;     //数据库指针
        int rect = sqlite3_open(path, &db); //打开数据库
        if(rect != SQLITE_OK)
        {
            printf("数据库打开失败\n");
            return -1;
        }

        // 执行sql


        char *sql = "insert into mytable(id, value) values(1, 'hello');";
        int status = sqlite3_exec(db, sql, NULL, NULL, NULL);
        if(status != SQLITE_OK)
        {
            printf("sql语句执行失败\n");
        }

        // 关闭数据库
        sqlite3_close(db);
    }

    return 0;
}
