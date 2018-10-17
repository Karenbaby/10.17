#include <stdio.h>
#include <string.h>
#include "deletec.h"
#include "main.h"
int deletec()
{
    char name[10];
    FILE *fp,*fl;
    int i,j,k,flag;
    printf("\n请输入要删除的课程名称：");
    scanf("%s",name);
    flag=0;
    for(j=0;j<lenc;j++)
    {
        if(strcmp(c[j].class_name,name)==0)
        {
            flag=1;
            lenc-=1;
            fl=fopen("log.log","a+");
            fprintf(fl,"class delete :%s %s %s %d %d %d %d\n",c[j].class_id,c[j].class_name,c[j].class_quality,c[j].class_time,c[j].class_score,c[j].class_number,c[j].class_maxinum);
            fclose(fl);
            for(i=0;i<lens;i++)
            {
                for(k=0;k<3;k++)
                {
                    if(strcmp(name,s[i].stu_class[k])==0)
                    {
                        strcpy(s[i].stu_class[k],"NULL\0");
                        s[i].sum-=c[j].class_score;
                    }
                }
            }
        }
        if(flag)
        {
            c[j]=c[j+1];
        }
    }
    if(flag==0)
    {
        printf("未找到要删除的课程！\n");
        operatec();
    }
    printf("\n删除后课程的信息为：\n");
    printf("课程编号  课程名称  课程性质  授课学时  学分  课程已选人数 课程人数上限\n");
    fp=fopen(strc,"w");
    for(j=0;j<lenc;j++)
    {
        printf("  %s\t   %-10s  %s\t %d\t %d\t %d\t \t%d\n",c[j].class_id,c[j].class_name,c[j].class_quality,c[j].class_time,c[j].class_score,c[j].class_number,c[j].class_maxinum);
        fprintf(fp,"%s %s %s %d %d %d %d",c[j].class_id,c[j].class_name,c[j].class_quality,c[j].class_time,c[j].class_score,c[j].class_number,c[j].class_maxinum);
        if(j!=lenc-1)
            fprintf(fp,"\n");
    }
    fclose(fp);
    operatec();
    return 0;
}

