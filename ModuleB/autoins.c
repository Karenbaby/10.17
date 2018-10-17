#include<stdio.h>
#include<string.h>
#include "main.h"
int autoins()
{
    FILE *fp;
    int i=0,j,k,flag;
    printf("\n请输入文件名：");
    scanf("%s",strs);
    if((fp=fopen(strs,"r"))==NULL)
    {
        printf("Open %s error!导入失败！\n",strs);
        choose();
        return 0;
    }
    while(!feof(fp))
    {
        fscanf(fp,"%s %s %s %s %s %d",s[i].stu_id,s[i].stu_name,s[i].stu_class[0],s[i].stu_class[1],s[i].stu_class[2],&s[i].sum);
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
        i++;
    }
    lens=i;
    fclose(fp);
    fp=fopen(strs,"w");
    printf("学号    学生姓名    选课1    选课2    选课3    总学分\n");
    for(j=0;j<i;j++)
    {
        fprintf(fp,"%s %s %s %s %s %d",s[j].stu_id,s[j].stu_name,s[j].stu_class[0],s[j].stu_class[1],s[j].stu_class[2],s[j].sum);
        printf("%-4s %8s\t    %-8s %-8s %-8s %4d\n",s[j].stu_id,s[j].stu_name,s[j].stu_class[0],s[j].stu_class[1],s[j].stu_class[2],s[j].sum);
        if(j!=i-1)
            fprintf(fp,"\n");
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

