#include<malloc.h>
#include<string.h>
#include<stdlib.h>
#include <stdio.h>
struct stu
{
	char num[10];
	char name[20];
	int score[3];
	
};
struct stu student[20];
main()
{
  int n;
  scanf("%d",&n);
  int i,j;
  int sum1=0;
  float sum2=0;
  float sum3=0;
  int s=0;
  int maxi;
  int max=0;
  for(i=0;i<=n-1;i++)
  {
	  	s=0;
	  
	  	scanf("%s",student[i].num);
	  	scanf("%s",student[i].name);
	  	for(j=0;j<=2;j++)
	  	{
	  		scanf("%d",&student[i].score[j]);
	  		s+=student[i].score[j];
	  		if(j==0)
	  		{
	  			sum1+=student[i].score[j];
			  }
			  if(j==1)
			{
				sum2+=student[i].score[j];
			}
			if(j==2)
			sum3+=student[i].score[j];
		}
		  if(s>max)
		  {
		  	max=s;
		  	maxi=i;
		  }
		 
  }
  printf("%.0f %.0f %.0f\n",1.0*sum1/n,1.0*sum2/n,1.0*sum3/n);
  printf("%s %s %d %d %d",student[maxi].num,student[maxi].name,student[maxi].score[0],student[maxi].score[1],student[maxi].score[2]);
}
