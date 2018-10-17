#include<stdio.h>
#include "autoins.h"
#include "handins.h"
int inits()
{
    int a;
    printf(" ---初始化学生系统信息--- \n");
    printf("|      1、文档导入       |\n");
    printf("|      2、手动导入       |\n");
    printf(" ------------------------ \n\n");
    printf("请输入你的选择：");
    scanf("%d",&a);
    switch(a)
    {
        case 1:
            autoins();break;
        case 2:
            handins();break;
    }
    return 0;
}

