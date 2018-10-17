#include <stdio.h>
#include <string.h>
#include "deletes.h"
#include "main.h"
int deletes()
{
    char name[10];
    FILE *fp,*fl;
    int i,j,k,flag;
    printf("\n请输入要删除的学生的姓名：");
    scanf("%s",name);
    flag=0;
    for(j=0;j<lens;j++)
    {
        if(strcmp(s[j].stu_name,name)==0)
        {
            fl=fopen("log.log","a+");
            fprintf(fl,"student delete :%s %s %s %s %s %d\n",s[j].stu_id,s[j].stu_name,s[j].stu_class[0],s[j].stu_class[1],s[j].stu_class[2],s[j].sum);
            fclose(fl);
            for(i=0;i<3;i++)
            {
                for(k=0;k<lenc;k++)
                    if(strcmp(s[j].stu_class[i],c[k].class_name)==0)
                    {
                        c[k].class_number-=1;
                        break;
                    }
            }
            flag=1;
            lens-=1;
        }
        if(flag)
        {
            s[j]=s[j+1];
        }
    }
    if(flag==0)
    {
        printf("未找到要删除的学生！\n");
        operates();
    }
    printf("\n删除后学生的信息为：\n");
    printf("学号    学生姓名    选课1    选课2    选课3    总学分\n");
    fp=fopen(strs,"w");
    for(j=0;j<lens;j++)
    {
        printf("%4s %8s\t    %-8s %-8s %-8s %4d\n",s[j].stu_id,s[j].stu_name,s[j].stu_class[0],s[j].stu_class[1],s[j].stu_class[2],s[j].sum);
        fprintf(fp,"%s %s %s %s %s %d",s[j].stu_id,s[j].stu_name,s[j].stu_class[0],s[j].stu_class[1],s[j].stu_class[2],s[j].sum);
        if(j!=lens-1)
            fprintf(fp,"\n");
    }
    fclose(fp);
    operates();
    return 0;
}

