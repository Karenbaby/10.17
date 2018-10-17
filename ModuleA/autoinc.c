#include<stdio.h>
#include<string.h>
#include "main.h"
int autoinc()
{
    FILE *fp;
    int i=0,j;
    printf("\n请输入文件名：");
    scanf("%s",strc);
    if((fp=fopen(strc,"r"))==NULL)
    {
        printf("Open %s error!导入失败！\n",strc);
        choose();
        return 0;
    }
    while(!feof(fp))
    {
        fscanf(fp,"%s %s %s %d %d %d %d",c[i].class_id,c[i].class_name,c[i].class_quality,&c[i].class_time,&c[i].class_score,&c[i].class_number,&c[i].class_maxinum);
        i++;
    }
    lenc=i;
    printf("课程编号  课程名称  课程性质  授课学时  学分  课程已选人数 课程人数上限\n");
    for(j=0;j<i;j++)
    {
        printf("  %s\t   %-10s  %s\t %d\t %d\t %d\t \t%d\n",c[j].class_id,c[j].class_name,c[j].class_quality,c[j].class_time,c[j].class_score,c[j].class_number,c[j].class_maxinum);
    }
    printf("导入成功！\n");
    fclose(fp);
    return 0;
}

