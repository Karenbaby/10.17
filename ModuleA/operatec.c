#include <stdio.h>
#include "operatec.h"
#include "addc.h"
#include "revisec.h"
#include "deletec.h"
#include "findc.h"
#include "choose.h"
int operatec()
{
    int a,flag=1;
    printf(" ---------欢迎进入选课管理系统----------\n");
    printf("|             1、新增课程               |\n");
    printf("|             2、修改课程               |\n");
    printf("|             3、删除课程               |\n");
    printf("|             4、查看课程               |\n");
    printf("|             5、返回主菜单             |\n");
    printf(" --------------------------------------- \n");
    printf("请输入你想完成的操作：");
    while(flag)
    {
        scanf("%d",&a);
        printf("\n");
        if(a<1||a>5)
        {
            printf("输入错误，请重新输入：");
            continue;
        }
        switch(a)
        {
            case 1:
                addc();
                break;
            case 2:
                revisec();
                break;
            case 3:
                deletec();
                break;
            case 4:
                findc();
                break;
            default:
                choose();
                break;
        }
    }
    return 0;
}

