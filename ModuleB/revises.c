#include <stdio.h>
#include <string.h>
#include "revises.h"
#include "main.h"
int revises()
{
    char name[10];
    char oldstr[10];
    FILE *fp,*fl;
    int i=0,j,flag;
    printf("\n请输入想修改的学生的姓名：");
    scanf("%s",name);
    printf(" -请输入修改的项目- \n");
    printf("|     1、学号      |\n");
    printf("|     2、选课1     |\n");
    printf("|     3、选课2     |\n");
    printf("|     4、选课3     |\n");
    printf("|     5、总学分    |\n");
    printf(" ------------------ \n");
    printf("输入：");
    scanf("%d",&flag);
    while(flag<1||flag>5)
    {
        printf("\n输入错误数字，请重新输入：");
        scanf("%d",&flag);
    }
    for(j=0;j<lens;j++)
    {
        if(strcmp(s[j].stu_name,name)==0)
        {
            fl=fopen("log.log","a+");
            fprintf(fl,"student revise :%s %s %s %s %s %d\n",s[j].stu_id,s[j].stu_name,s[j].stu_class[0],s[j].stu_class[1],s[j].stu_class[2],s[j].sum);
            fclose(fl);
            switch(flag)
            {
                case 1:
                    printf("\n请输入学生学号：");
                    scanf("%s",s[j].stu_id);
                    break;
                case 2:
                    strcpy(oldstr,s[j].stu_class[0]);
                    printf("\n请输入学生选课1：");
                    scanf("%s",s[j].stu_class[0]);
                    break;
                case 3:
                    strcpy(oldstr,s[j].stu_class[1]);
                    printf("\n请输入学生选课2：");
                    scanf("%s",s[j].stu_class[1]);
                    break;
                case 4:
                    strcpy(oldstr,s[j].stu_class[2]);
                    printf("\n请输入学生选课3：");
                    scanf("%s",s[j].stu_class[2]);
                    break;
                default:
                    printf("\n请输入学生总学分：");
                    scanf("%d",&s[j].sum);
                    break;
            }
            if(flag==2||flag==3||flag==4)
            {
                if(strcmp(oldstr,"NULL\0")==0);
                else
                {
                    for(i=0;i<lenc;i++)
                    if(strcmp(oldstr,c[i].class_name)==0)
                        {
                            s[j].sum-=c[i].class_score;
                            c[i].class_number-=1;
                        }
                }

                if(strcmp(s[j].stu_class[flag-2],"NULL\0")==0);
                else
                {
                    for(i=0;i<lenc;i++)
                    if(strcmp(s[j].stu_class[flag-2],c[i].class_name)==0)
                        {
                            s[j].sum+=c[i].class_score;
                            c[i].class_number+=1;
                        }
                }
            }
        }
    }
    printf("学号    学生姓名    选课1    选课2    选课3    总学分\n");
    fp=fopen(strs,"w");
    for(j=0;j<lens;j++)
    {
        printf("%-4s %8s\t    %-8s %-8s %-8s %4d\n",s[j].stu_id,s[j].stu_name,s[j].stu_class[0],s[j].stu_class[1],s[j].stu_class[2],s[j].sum);
        fprintf(fp,"%s %s %s %s %s %d",s[j].stu_id,s[j].stu_name,s[j].stu_class[0],s[j].stu_class[1],s[j].stu_class[2],s[j].sum);
        if(j!=lens-1)
            fprintf(fp,"\n");
    }
    fclose(fp);
    operates();
    return 0;
}

