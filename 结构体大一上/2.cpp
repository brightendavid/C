#include<string.h>
#include <stdio.h>
#include<stdlib.h>
 struct stu
 {
 	char num[200];
 	char name[200];
 	int score[3];
 };
 struct stu student[2000];
main()
{
	  int i;
	  int j;
	  int n;
	  int  max=0;
	  int sum[3];
	   int  s=0;	
	    for(j=0;j<=2;j++)
		{
			sum[j]=0;
		}
	  int maxi=0;
	  scanf("%d",&n);
	for(i=0;i<=n-1;i++) 
	{
		s=0;
		 scanf("%s",student[i].num);
	  scanf("%s",student[i].name);
	  for(j=0;j<=2;j++)
	  { 
	     scanf("%d",&student[i].score[j]); 
	     s+=student[i].score[j];
	    sum[j]+=student[i].score[j];
	   }
		  if(s>max)
		  {
		  	maxi=i;
		  	max=s;
		  }
	}
	printf("%d %d %d\n",sum[0]/n,sum[1]/n,sum[2]/n); 
	printf("%s %s %d %d %d",student[maxi].num,student[maxi].name,student[maxi].score[0],student[maxi].score[1],student[maxi].score[2]);
}
