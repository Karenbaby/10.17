#include <stdio.h>
#include <string.h>
#include "finds.h"
#include "main.h"
int finds()
{
    char name[10];
    int i=0,j,flag;
    FILE *fl;
    printf("\n请输入要查找的学生的姓名或学号：");
    scanf("%s",name);
    flag=0;
    for(j=0;j<lens;j++)
    {
        if(strcmp(s[j].stu_id,name)==0||strcmp(s[j].stu_name,name)==0)
        {
            flag=1;
            break;
        }
    }
    if(flag==0)
    {
        printf("未找到要查看的学生！\n");
        operates();
    }
    fl=fopen("log.log","a+");
    fprintf(fl,"student find :%s %s %s %s %s %d\n",s[j].stu_id,s[j].stu_name,s[j].stu_class[0],s[j].stu_class[1],s[j].stu_class[2],s[j].sum);
    fclose(fl);

    printf("\n该学生的信息为：\n");
    printf("学号    学生姓名    选课1    选课2    选课3    总学分\n");
    printf("%-4s %8s\t    %-8s %-8s %-8s %4d\n",s[j].stu_id,s[j].stu_name,s[j].stu_class[0],s[j].stu_class[1],s[j].stu_class[2],s[j].sum);
    operates();
    return 0;
}

