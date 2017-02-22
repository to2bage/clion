//
// Created by apple on 2017/2/21.
//
#include <stdio.h>

//定义全局的二维数组
static int a[10][3] = {0};

static swap(int* num1, int* num2)
{
    (*num1) = (*num1) ^ (*num2);
    (*num2) = (*num1) ^ (*num2);
    (*num1) = (*num1) ^ (*num2);
}

static int initHanno(int (*px)[3])
{
    //布局
    int n = 0;
    scanf("%d", &n);
    int cengshu = n;
    for(int i = 9; i >= 0; i--)
    {
        if(n >= 0)
        {
            px[i][0] = n--;
        }
        else
        {
            break;
        }
    }
    return cengshu;
}

static void showHanno(int (*px)[3])
{
    //显示
    printf("%5c%5c%5c\n", 'A', 'B', 'C');
    printf("%15s\n", "-----------");
    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            printf("%5d", px[i][j]);
        }
        printf("\n");
    }
}
//移动，连接数据
static void move(int (*px)[3], char X, char Y)
{
    //找到起始杆的第一个非0元素
    int sourceid = 0;
    while(px[sourceid++][X - 'A'] == 0)
    {
        if(sourceid >= 10)
            break;
    }
    sourceid--;

    //找到目标杆的最后一个0元素
    int targetid = 0;
    {
//        while(px[targetid][Y - 'A'] == 0)
//        {
//            targetid++;
//            if(targetid >= 10)
//            {
//                break;
//            }
//        }
//        targetid -= 1;
    }
    {
        while(px[targetid++][Y - 'A'] == 0)
        {
            if(targetid > 10)
            {
                break;
            }
        }
        targetid -= 2;
    }

    printf("source = %d, target = %d\n", sourceid, targetid);

    //交换 找到的这两个值
    swap(&(px[sourceid][X - 'A']), &(px[targetid][Y - 'A']));

    //显示 汉诺塔
    showHanno(px);

}

static void hanno(int n, char A, char B, char C)
{
    if(n < 1)
    {
        return;
    }
    else if(n == 1)
    {
        //printf("%c => %c\n", A, C);
        move(a, A, C);
    }
    else
    {
        {
//            hanno(n - 1, A, C, B);
//            printf("%c => %c\n", A, C);
//            hanno(n - 1, B, A, C);
        }
        {
            hanno(n - 1, A, C, B);
            move(a, A, C);
            hanno(n - 1, B, A, C);
        }
    }
}


int main汉诺塔(int argc, char* argv[])
{
    {
        //汉诺塔
        int cengshu = initHanno(a);
        showHanno(a);
        printf("=========>\n");
        hanno(cengshu, 'A', 'B', 'C');

    }
    return 0;
}

