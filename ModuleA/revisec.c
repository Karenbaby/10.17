#include <stdio.h>
#include <string.h>
#include "revisec.h"
#include "main.h"
int revisec()
{
    char name[10];
    FILE *fp,*fl;
    int i,j,k,flag,old;
    printf("\n请输入想修改的课程名称：");
    scanf("%s",name);
    printf(" ----请输入修改的项目---- \n");
    printf("|     1、课程编号        |\n");
    printf("|     2、课程性质        |\n");
    printf("|     3、授课学时        |\n");
    printf("|     4、学分            |\n");
    printf("|     5、课程已选人数    |\n");
    printf("|     6、课程人数上限    |\n");
    printf(" ------------------------ \n");
    printf("输入：");
    scanf("%d",&flag);
    getchar();
    while(flag<1||flag>6)
    {
        printf("\n输入错误数字，请重新输入：");
        scanf("%d",&flag);
        getchar();
    }
    for(j=0;j<lenc;j++)
    {
        if(strcmp(c[j].class_name,name)==0)
        {
            fl=fopen("log.log","a+");
            fprintf(fl,"class find :%s %s %s %d %d %d %d\n",c[j].class_id,c[j].class_name,c[j].class_quality,c[j].class_time,c[j].class_score,c[j].class_number,c[j].class_maxinum); 
            fclose(fl); 
            switch(flag)
            {
                case 1:
                    printf("\n请输入课程编号：");
                    scanf("%s",c[j].class_id);
                    getchar();
                    break;
                case 2:
                    printf("\n请输入课程性质：");
                    scanf("%s",c[j].class_quality);
                    getchar();
                    break;
                case 3:
                    printf("\n请输入授课学时：");
                    scanf("%d",&c[j].class_time);
                    getchar();
                    break;
                case 4:
                    old=c[j].class_score;
                    printf("\n请输入学分：");
                    scanf("%d",&c[j].class_score);
                    getchar();
                    for(i=0;i<lens;i++)
                    {
                        for(k=0;k<3;k++)
                        {
                            if(strcmp(s[i].stu_class[k],name)==0)
                                s[i].sum=s[i].sum-old+c[j].class_score;
                        }
                    }
                    break;
                case 5:
                    printf("\n请输入课程已选人数：");
                    scanf("%d",&c[j].class_number);
                    getchar();
                    break;
                default:
                    printf("\n请输入课程人数上限：");
                    scanf("%d",&c[j].class_maxinum);
                    getchar();
                    break;
            }
        }
    }
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

