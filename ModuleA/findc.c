#include <stdio.h>
#include <string.h>
#include "findc.h"
#include "main.h"
int findc()
{
    char name[10];
    int i=0,j,flag;
    FILE *fl;
    printf("\n请输入要查找的课程名称：");
    scanf("%s",name);
    flag=0;
    for(j=0;j<lenc;j++)
    {
        if(strcmp(c[j].class_name,name)==0)
        {
            flag=1;
            break;
        }
    }
    if(flag==0)
    {
        printf("未找到要查看的课程！\n");
        operates();
    }
    fl=fopen("log.log","a+");
    fprintf(fl,"class find :%s %s %s %d %d %d %d\n",c[j].class_id,c[j].class_name,c[j].class_quality,c[j].class_time,c[j].class_score,c[j].class_number,c[j].class_maxinum);
    fclose(fl);
    printf("\n该课程的具体信息为：\n");
    printf("课程编号  课程名称  课程性质  授课学时  学分  课程已选人数 课程人数上限\n");
    printf("  %s\t   %-10s  %s\t %d\t %d\t %d\t \t%d\n",c[j].class_id,c[j].class_name,c[j].class_quality,c[j].class_time,c[j].class_score,c[j].class_number,c[j].class_maxinum);
    operatec();
    return 0;
}

