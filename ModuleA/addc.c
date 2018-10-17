#include<stdio.h>
#include<string.h>
#include "main.h"
#include "addc.h"
int addc()
{
    class a;
    FILE *fp,*fl;
    if((fp=fopen(strc,"a+"))==NULL)
    {
        printf("Open %s error!添加失败！\n",strc);
        choose();
        return 0;
    }
    printf("\n请输入你要输入的课程信息：\n");
    printf("请输入课程编号：");
    scanf("%s",a.class_id);
    getchar();
    printf("\n请输入课程名称：");
    scanf("%s",a.class_name);
    getchar();
    printf("\n请输入课程性质：");
    scanf("%s",a.class_quality);
    getchar();
    printf("\n请输入授课学时：");
    scanf("%d",&a.class_time);
    getchar();
    printf("\n请输入该课学分：");
    scanf("%d",&a.class_score);
    getchar();
    printf("\n请输入课程已选人数：");
    scanf("%d",&a.class_number);
    getchar();
    printf("\n请输入课程人数上限：");
    scanf("%d",&a.class_maxinum);
    getchar();
    printf("%s %s %s %d %d %d %d\n",a.class_id,a.class_name,a.class_quality,a.class_time,a.class_score,a.class_number,a.class_maxinum);
    fprintf(fp,"\n%s %s %s %d %d %d %d",a.class_id,a.class_name,a.class_quality,a.class_time,a.class_score,a.class_number,a.class_maxinum);
    fl=fopen("log.log","a+");
    fprintf(fl,"class add :%s %s %s %d %d %d %d\n",a.class_id,a.class_name,a.class_quality,a.class_time,a.class_score,a.class_number,a.class_maxinum);
    fclose(fl);
    printf("\n添加成功！\n");
    lenc+=1;
    c[lenc-1]=a;
    fclose(fp);
    operatec();
    return 0;
}

