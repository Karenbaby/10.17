#include<stdio.h>
#include<string.h>
#include "main.h"
int handins()
{
    int i,j,k,flag;
    FILE *fp;
    printf("\n请输入你将要导入的文件名：");
    scanf("%s",strs);
    fp=fopen(strs,"w");
    printf("\n请输入要输入的学生信息个数：");
    scanf("%d",&lens);
    printf("\n请依次输入学生的信息：包含学号，姓名，选课\n");
    for(i=0;i<lens;i++)
    {
        scanf("%s %s %s %s %s",s[i].stu_id,s[i].stu_name,s[i].stu_class[0],s[i].stu_class[1],s[i].stu_class[2]);
        s[i].sum=0;
        for(k=0;k<3;k++)
        {
            flag=0;
            for(j=0;j<lenc;j++)
                if(strcmp(s[i].stu_class[k],c[j].class_name)==0)
                {
                    flag=1;
                    if(c[j].class_number==c[j].class_maxinum)
                        flag=0;
                    else
                        {
                            c[j].class_number+=1;
                            s[i].sum+=c[j].class_score;
                        }
                    break;
                }
            if(flag==0)
            {
                strcpy(s[i].stu_class[k],"NULL\0");
            }
        }
    }
    printf("学号    学生姓名    选课1    选课2    选课3    总学分\n");
    for(i=0;i<lens;i++)
    {
        printf("%-4s %8s\t    %-8s %-8s %-8s %4d\n",s[i].stu_id,s[i].stu_name,s[i].stu_class[0],s[i].stu_class[1],s[i].stu_class[2],s[i].sum);
        fprintf(fp,"%s %s %s %s %s %d\n",s[i].stu_id,s[i].stu_name,s[i].stu_class[0],s[i].stu_class[1],s[i].stu_class[2],s[i].sum);
    }
    printf("导入成功！\n");
    fclose(fp);
    fp=fopen(strc,"w");
    printf("课程编号  课程名称  课程性质  授课学时  学分  课程已选人数 课程人数上限\n");
    for(j=0;j<lenc;j++)
    {
        printf("  %s\t   %-10s  %s\t %d\t %d\t %d\t \t%d\n",c[j].class_id,c[j].class_name,c[j].class_quality,c[j].class_time,c[j].class_score,c[j].class_number,c[j].class_maxinum);
        fprintf(fp,"%s %s %s %d %d %d %d",c[j].class_id,c[j].class_name,c[j].class_quality,c[j].class_time,c[j].class_score,c[j].class_number,c[j].class_maxinum);
        if(j!=lenc)
        fprintf(fp,"\n");
    }
    fclose(fp);
    return 0;
}

