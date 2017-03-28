//
// Created by apple on 2017/2/15.
//
#include <stdio.h>
#define 中意的身高 172
#define 中意的年龄 30

int main05(int argc, char* argv[])
{
    {
//        int num = 0;
//        scanf("num=%d", &num);
//        printf("num = %d\n", num);
    }

    {
//        int a = 0, b = 0, c = 0;
//        scanf("a=%d,b=%*d,c=%d", &a, &c);
//        printf("a = %d, b = %d, c = %d\n", a, b, c);
    }

    {
//        char str[500] = "131610	陈小姐	女	40	165	高中	未婚	朝阳	双子座	在校学生	普通话	北京	面议元/天	有过几次	学生伴游	清纯漂亮 自信可爱的我独在北京上学.在这浪漫的季节偶尔来到这里寻找我的有缘人.愿我们的相聚能留下人生中最美好的回忆!	10:00—23:00		2264938779@qq.com		226493870779";
//        int age, tall;
//        sscanf(str, "%*d%*s%*s%d%d", &age, &tall);
//        printf("age = %d, tall = %d\n", age, tall);
    }

    {
//        char str[500] = "to2bage,420111197203024016,13600477059,nixiaodong@vip.sina.com";
//        char name[30] = {0};
//        long long int id = 0;
//        long long int phonenumber = 0;
//        char email[50] = {0};
//        sscanf(str, "%s,%lld,%lld,%s", name, &id, &phonenumber, email);
//        printf("name = %s\nid = %lld\nphone = %lld\nemail = %s\n", name, id, phonenumber, email);
    }

    {
//        int num1, num2, num3, num4, num5, num6;
//        scanf("%3d%3d%3d%3d%3d%3d", &num1, &num2, &num3, &num4, &num5, &num6);
//        printf("num1 = %d\nnum2 = %d\nnum3 = %d\nnum4 = %d\nnum5 = %d\nnum6 = %d\n", num1, num2, num3, num4, num5, num6);

    }

    {
//        char str1[100] = {0};
//        char str2[100] = {0};
//        scanf("%*3s%3s%s", str1, str2);
//        printf("str1 = %s\nstr2 = %s\n", str1, str2);

//        float fl = 0.0;
////        scanf("%7.2f", &fl);    //实数不可以指定输入的精度，这是错误的
//        scanf("%7f", &fl);  //实数可以指定位数， 但是没有任何的意义
//        printf("fl = %f\n", fl);

        int num1;
        int num2;
        int num3;
        char str[100];
        int n;
        scanf("%s%n%d%d%d", str, &n, &num1, &num2, &num3);
        printf("%s%d%d%d%d\n", str, n, num1, num2, num3);
    }

    return 0;
}
