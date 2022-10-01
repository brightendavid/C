#include<malloc.h>
#include<string.h>
#include<stdlib.h>
#include <stdio.h>
#include<math.h>
int a[2000];
int  sear(int x,int y);
int zai(int x,int y,int z);
int su(int x);
main()
{
  int i,j;
  int n,m;
  int c,d;
  int num;
  int s;
  int x,y;
  int count=0;
   scanf("%d,%d",&c,&d);
   num=sear(c,d);
   for(i=0;i<=num;i++)
   {
   	  n=a[i];
   	  s=n*3;
   	  for(y=2;y<=n-1;y++)
   	   {
   	  	 for(x=y+2;x<=n-3;x++)
   	  	 {
   	  	 	if(x!=2*y)
   	  	 	{	
				if(zai(c,d,y+n)&&zai(c,d,n-y)&&zai(c,d,n+x)&&zai(c,d,n-x)&&zai(c,d,n+x+y)&&zai(c,d,n-x-y)&&zai(c,d,n-x+y)&&zai(c,d,n+x-y))
	   	  	    {
					 if(su(y+n)&&su(n-y)&&su(n+x)&&su(n-x)&&su(n+x+y)&&su(n-x-y)&&su(n-x+y)&&su(x+n-y))
					{
						//printf(" %3d %3d %3d\n %3d %3d %3d \n %3d %3d %3d \n\n",n-x,n+x+y,n-y,n+x-y,n,n-x+y,n+y,n-x-y,n+x);
						count++;
					}	
				}    
			}
   	  	 
		  }
		}
   }
   
   printf("共%d个素数幻方",count);
}
int  sear(int x,int y)
{
	int i,j;
	j=0;
	for(i=x;i<=y;i++)
	{
		if(su(i))
		{
			a[j]=i;
			j++;
		}
	}
	return j-1;
}
int su(int x)
{
	int i,j;
	for(i=2;i<=x/2;i++)
	{
		if(x%i==0)
		{
			return 0;
		}
	}
	return 1;
}
int zai(int x,int y,int z)
{
	if(z>=x&&z<=y)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
