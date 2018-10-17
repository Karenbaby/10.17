#include<stdio.h>
#include "autoinc.h"
#include "handinc.h"
int initc()
{
    int a;
    printf(" ---初始化课程系统信息--- \n");
    printf("|      1、文档导入       |\n");
    printf("|      2、手动导入       |\n");
    printf(" ------------------------ \n\n");
    printf("请输入你的选择：");
    scanf("%d",&a);
    switch(a)
    {
        case 1:
            autoinc();break;
        case 2:
            handinc();break;
    }
    return 0;
}

