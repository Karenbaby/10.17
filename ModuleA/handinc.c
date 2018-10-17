#include<stdio.h>
#include<string.h>
#include "main.h"
int handinc()
{
    int i;
    FILE *fp;
    printf("\n请输入你将要导入的文件名：");
    scanf("%s",strc);
    fp=fopen(strc,"w");
    printf("\n请输入要输入的课程信息个数：");
    scanf("%d",&lenc);
    for(i=0;i<lenc;i++)
    {
        scanf("%s %s %s %d %d %d %d",c[i].class_id,c[i].class_name,c[i].class_quality,&c[i].class_time,&c[i].class_score,&c[i].class_number,&c[i].class_maxinum);
    }
    printf("课程编号  课程名称  课程性质  授课学时  学分  课程已选人数 课程人数上限\n");
    for(i=0;i<lenc;i++)
    {
        printf("  %s\t   %-10s  %s\t %d\t %d\t %d\t \t%d\n",c[i].class_id,c[i].class_name,c[i].class_quality,c[i].class_time,c[i].class_score,c[i].class_number,c[i].class_maxinum);
        fprintf(fp,"%s %s %s %d %d %d %d\n",c[i].class_id,c[i].class_name,c[i].class_quality,c[i].class_time,c[i].class_score,c[i].class_number,c[i].class_maxinum);
    }
    printf("导入成功！\n");
    return 0;
}

