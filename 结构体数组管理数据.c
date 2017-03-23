//
// Created by apple on 2017/3/23.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

char str[1024] = "521276402----hanlei@19940403 \
286738260----WEIPEI559720 \
501223616----feng66532008 \
851400824----shuidongwo520 \
1340382355----huang.512yang. \
1061817115----fz62wangyong1983 \
347232860----20080811 \
1028181591----7404850554 \
120539543----0.0123456789 \
754229005----460228214 \
819781633----zmt1993826 \
1319148052----YNU1500621032 \
904972448----zhouxiaowen.520 \
750134133----1292857988 \
438905700----320675 \
379644978----7758521tao \
346083956----devl1017 \
562193724----5361a749 \
286124126----xuqiang1988 \
4008167599----234567 \
937350113----MAWENcxn1020 \
873589635----qqco1341HUA \
853249795----5385939d ";

struct info
{
    long long qq;
    char pwd[20];
};

typedef struct info Info;

struct infos
{
    Info *pinfo;    //数组的首地址
    int length;     //数组的长度
};

typedef struct infos Infos;

Infos myinfos;  //全局变量，结构体数组

//获得数据的行数
static int getRows(char *pstr)
{
    int rows = 0;

    for(char *px = strstr(pstr, "----"); px != NULL; px = strstr(px + strlen("----"), "----"))
    {
        rows++;
    }

    return rows;
}
//字符串转longlong 数据类型
static long long strToLong(char *pstr)
{
    long long llnum = 0;

    char *str = pstr;
    while(*str != '\0')
    {
        llnum *= 10;
        llnum += *str - '0';
        str++;
    }
    return llnum;
}

//解析字符串 853249795----5385939d
static Info* parseStr(char *pstr)
{
    if(pstr == NULL)
    {
        return NULL;
    }

    char *str = pstr;

    Info *pinfo = (Info *)malloc(1 * sizeof(Info));
    char *px = strtok(str, "-");
    pinfo->qq = strToLong(px);

    px += strlen(px) + strlen("----");
    strcpy(pinfo->pwd, px);

    return pinfo;
}

//初始化结构体数组
static void initInfos()
{
    int rows = getRows(str);

    myinfos.pinfo = (Info *)malloc(rows * sizeof(Info));
    memset(myinfos.pinfo, 0, rows * sizeof(Info));
    myinfos.length = rows;
}

//读入数据
static void readData(char *pstr)
{
    char *px = pstr;
    char stemp[100] = {0};
    for(int i = 0; i < getRows(pstr); i++)
    {
        sscanf(px, "%[^ ]", stemp);
        //printf("%s\n", stemp);

        char *ps = (char *)malloc((strlen(stemp) + 1) * sizeof(char));
        memset(ps, 0, (strlen(stemp) + 1) * sizeof(char));
        strcpy(ps, stemp);

        Info *pinfo = parseStr(ps);
        myinfos.pinfo[i].qq = pinfo->qq;
        strcpy(myinfos.pinfo[i].pwd, pinfo->pwd);

        px += strlen(stemp) + 1;
    }
}

//显示数据
static void showInfos(Infos *pinfos)
{
    for(int i = 0; i < pinfos->length; i++)
    {
        printf("%lld, %s\n", pinfos->pinfo[i].qq, pinfos->pinfo[i].pwd);
    }
    printf("\n");
}



int main结构体数组管理数据(int argc, char *argv[])
{
    initInfos();

    readData(str);

    showInfos(&myinfos);

    return 0;
}
