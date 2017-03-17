//
// Created by apple on 2017/3/17.
//
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

struct words
{
    char *pstr;
    char *pqian;
};
typedef struct words Words;


//获取字符串的函数
static int getRowsOfContent(char *pstr, char ch)
{
    int rows = 0;
    char *px = pstr;
    while(*px != '\0')
    {
        if(*px++ == ch)
        {
            rows++;
        }

    }
    return rows;
}

int main字符串分割(int argc, char *argv[])
{
    char str[2018] = "我们还是当朋友好了(其实你还有可以利用的价值)\n\
我想我真的不适合你(我根本就不喜欢你!)\n\
其实你人真的很好(可是我不想和你在一起)\n\
你人真的很好(我是真的不想和你在一起)\n\
你人真的真的很好....真的(猪头,离我远一点!) \n\
我暂时不想交男朋友(闪边啦!你还不到我心中帅哥标准的一半)\n\
我不想伤害我们之间的友谊(我们之间也只会有友谊)\n\
我心中牵挂着一个人(那个人是我专门为你这种人虚构的)\n\
我从来没想过这个问题(这是根本不可能的.还用想吗?)\n\
我不适合当个情人(废话,没人会适合当你的情人的)\n\
你给我一段时间考虑(不给我时间,我怎么溜啊)\n\
你的条件真的很好(可是还没好到我想要的地步)\n\
可是这样的感觉好怪(你这丑八怪,怪到这样还想吃天鹅肉?)\n\
你的温柔我会铭记在心的(拜托,情圣!光温柔是没用的,还要有钱!)\n\
其实我一直没勇气接受你(看到你差点吓死,哪还有勇气?)\n\
你真的很可爱(你真的很幼稚)\n\
你真的是超级可爱啦(猪头,不要象小孩那样缠着我! )\n\
遇到你,总会让我重温童年的快乐(就象阿姨遇到小弟弟那样)\n\
我们应该给彼此一点缓冲时间(给你时间快滚,再不走我要翻脸啦!)\n\
别人都说你条件不错啊(可我从来没这样认为!)\n\
如果我们早点认识就好了(可以让你早点觉悟!)\n\
别急嘛,我们可以做朋友(趁这个时候我要找到我的白马王子啊~)\n";


    {
        char *p1 = str;
        char *p2 = str;

        //获得长字符串的行数
        int rows = getRowsOfContent(str, '(');
//        printf("共有%d行数据\n", rows);  //22

        //将长字符串读入内存
        char **ppstr = (char **)malloc(rows * sizeof(char *));
        int i = 0;
        while(*p2 != '\0')
        {
            while(*p2 != '\n')
            {
                p2++;
            }
            //此时p2指向字符串的某行的字符'\n'
            int len = p2 - p1;
            ppstr[i] = (char *)malloc((len + 1) * sizeof(char));
            memset(ppstr[i], 0, (len + 1) * sizeof(char));
            memcpy(ppstr[i], p1, len * sizeof(char));

//            printf("%s\n", ppstr[i]); //测试

            //移动指针p1和p2
            p1 = ++p2;
            i++;
        }

        //分离获得的数据
        Words *pwords = (Words *)malloc(rows * sizeof(Words));
        for(int i = 0; i < rows; i++)
        {
//            for(char *px = strtok(ppstr[i], "("); px != NULL; px = strtok(px + strlen(px) + 1, "("))
//            {
//                pwords[i].pstr = (char *)malloc((strlen(px) + 1) * sizeof(char));
//            }

            char *px = strtok(ppstr[i], "(");
            pwords[i].pstr = (char *)malloc((strlen(px) + 1) * sizeof(char));
            memset(pwords[i].pstr, 0, (strlen(px) + 1) * sizeof(char));
            memcpy(pwords[i].pstr, px, strlen(px) * sizeof(char));

            px = strtok(px + strlen(px) + 1, "(");
            pwords[i].pqian = (char *)malloc((strlen(px) + 1) * sizeof(char));
            memset(pwords[i].pqian, 0, (strlen(px) + 1) * sizeof(char));
            memcpy(pwords[i].pqian, px, (strlen(px) - 1) * sizeof(char));
        }

        //显示
        for(int i = 0; i < rows; i++)
        {
            printf("问: %s\n", pwords[i].pstr);
            printf("答: %s\n\n", pwords[i].pqian);
        }
        printf("\n");
    }
    return 0;
}
