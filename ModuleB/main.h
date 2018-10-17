#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED

typedef struct studentinformation
{
    char stu_id[10];
    char stu_name[10];
    char stu_class[3][10];
    int sum;
}stu;
typedef struct classinformation
{
    char class_id[10];
    char class_name[10];
    char class_quality[10];
    int class_time;
    int class_score;
    int class_number;
    int class_maxinum;
}class;

stu s[10];
class c[10];
//存信息的数组

int lens;
int lenc;
//存储信息的长度

char strs[10];
char strc[10];
//存储的文档

#endif // MAIN_H_INCLUDED

