#include<malloc.h>
#include<string.h>
#include<stdlib.h>
#include <stdio.h>
struct s
{
	int score;
}a[10];
main()
{
	int count=0;
	int maxi=0;
  int i,j;
  int t=0;
   for(i=0;i<=9;i++)
   {
	   	scanf("%d",&a[i].score);
	   	if(a[i].score>a[maxi].score)
	   	{
	   		maxi=i;
		}
   }
   for(i=0;i<=9;i++)
   {
   	if(a[i].score==a[maxi].score)
   	{
   		count++;
    }
   }
    for(i=0;i<=9;i++)
   {
   	if(a[i].score==a[maxi].score)
   	{
   		t++;
   		if(t!=count)
   		{
   			printf("%d\n",i);
		}
		else
		{
			printf("%d",i);
		}
    }
   }
   
}
