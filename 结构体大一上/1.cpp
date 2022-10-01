#include<string.h>
#include <stdio.h>
#include<stdlib.h>
 struct stu
 {
 	char name[20];
 	char sex;
	 char num[11];
 	float score[3];
 };
 struct stu student ={"li",'f',"12",98,97,95};
main()
{
   char temp[20];
  int i;
  gets(student.name);
  //getchar();
  student.sex=getchar();
  getchar();
  gets(student.num);
  //getchar();
  for(i=0;i<3;i++)
  {
  	gets(temp);
  	student.score[i]=atoi(temp);
  }
  
  	printf("%s %c %s %f %f %f",student.name,student.sex,student.num,student.score[0],student.score[1],student.score[2]);
   
}
