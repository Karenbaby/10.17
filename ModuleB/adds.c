#include<stdio.h>
#include<string.h>
#include "main.h"
#include "adds.h"
int adds()
{
    FILE *fp,*fl;
    stu a;
    int i,j,flag;
    if((fp=fopen(strs,"a+"))==NULL)
    {
        printf("Open %s error!添加失败！\n",strs);
        choose();
        return 0;
    }
    printf("\n请输入你要输入的学生信息：\n");
    printf("请输入学生的学号：");
    scanf("%s",a.stu_id);
    getchar();
    printf("\n请输入学生的姓名：");
    scanf("%s",a.stu_name);
    getchar();
    printf("\n请输入学生的选课信息：");
    scanf("%s %s %s",a.stu_class[0],a.stu_class[1],a.stu_class[2]);
    getchar();
    a.sum=0;
    for(i=0;i<3;i++)
    {
        flag=0;
        for(j=0;j<lenc;j++)
            if(strcmp(a.stu_class[i],c[j].class_name)==0)
            {
                flag=1;
                if(c[j].class_number==c[j].class_maxinum)
                    flag=0;
                else
                    {
                        c[j].class_number+=1;
                        a.sum+=c[j].class_score;
                    }
                break;
            }
        if(flag==0)
        {
            strcpy(a.stu_class[i],"NULL\0");
        }
    }
    fl=fopen("log.log","a+");
    fprintf(fl,"student add :%s %s %s %s %s %d\n",a.stu_id,a.stu_name,a.stu_class[0],a.stu_class[1],a.stu_class[2],a.sum);
    fclose(fl);
    printf("%s %s %s %s %s %d",a.stu_id,a.stu_name,a.stu_class[0],a.stu_class[1],a.stu_class[2],a.sum);
    fprintf(fp,"\n%s %s %s %s %s %d",a.stu_id,a.stu_name,a.stu_class[0],a.stu_class[1],a.stu_class[2],a.sum);
    printf("\n添加成功！\n");
    lens+=1;
    s[lens-1]=a;
    fclose(fp);
    operates();
    return 0;
}

