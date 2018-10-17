#include<stdio.h>
#include "choose.h"
#include "operates.h"
#include "operatec.h"

int choose()
{
    int t;
    printf(" -------------系统管理模块--------------\n");
    printf("|           1、学生管理系统             |\n");
    printf("|           2、课程管理系统             |\n");
    printf(" ---------------------------------------\n");
    printf("\n请输入你的选择：");
    scanf("%d",&t);
    while(t<1||t>2)
    {
        printf("输入不合法，请重新输入：");
        scanf("%d",&t);
    }
    switch(t)
    {
        case 1:
            operates();
            break;//进入学生管理系统
        default:
            operatec();
            break;//进入课程管理系统
    }
    return 0;
}

