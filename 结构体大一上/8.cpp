#include <stdio.h>
#include<stdlib.h>
typedef struct Student
{
 char num[10];
 char name[20];
 int score[3];
 float ave;
}STU;


 int main()
{
 STU stu[10],max;
 int i,j,n;
 int sum[3]={0,0,0};
 scanf("%d\n",&n);


for(i=0;i<n;i++)
{
 scanf("%s %s %d %d %d",stu[i].num,stu[i].name,&stu[i].score[0],&stu[i].score[1],&stu[i].score[2]);
 sum[0]+=stu[i].score[0];
sum[1]+=stu[i].score[1];
sum[2]+=stu[i].score[2];


 stu[i].ave=(stu[i].score[0]+stu[i].score[1]+stu[i].score[2])/3.0;

}
printf("%d %d %d\n",sum[0]/n,sum[1]/n,sum[2]/n);
 max=stu[0];
for(j=1;j<n;j++)
{
    if(stu[j].ave>max.ave)
    max=stu[j];
}
printf("%s %s %d %d %d\n",max.num,max.name,max.score[0],max.score[1],max.score[2]);


return 0;
}
