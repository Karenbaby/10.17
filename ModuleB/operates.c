#include <stdio.h>
#include "operates.h"
#include "adds.h"
#include "revises.h"
#include "deletes.h"
#include "finds.h"
#include "choose.h"
int operates()
{
    int a,flag=1;
    printf(" ----------欢迎进入学生管理系统---------\n");
    printf("|           1、新增学生信息             |\n");
    printf("|           2、修改学生信息             |\n");
    printf("|           3、删除学生信息             |\n");
    printf("|           4、查看学生信息             |\n");
    printf("|           5、返回主菜单               |\n");
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
                adds();break;
            case 2:
                revises();break;
            case 3:
                deletes();break;
            case 4:
                finds();break;
            default:
                choose();break;
        }
    }
    return 0;
}

