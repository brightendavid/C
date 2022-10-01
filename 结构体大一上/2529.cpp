#include<malloc.h>
#include<string.h>
#include<stdlib.h>
#include <stdio.h>
void search(int x);
int num[1010];
int bol=0;
struct lu
{
	int fi;
	int la;
	int time;
}st[20010];  
int n,m;
int sum=0;
main()
{
  int i,j;
  
   int t;
  while(scanf("%d%d",&n,&m)!=EOF)
  {
  	bol=0;
  	for(i=1;i<=n;i++)
  	{
  		num[i]=0;
	}
  	for(i=0;i<=m-1;i++)
  	{
  		scanf("%d%d%d",&st[i].fi,&st[i].la,&st[i].time);
  		num[st[i].fi]++;
	}
	for(i=0;i<=m-1;i++)
	{
		for(j=0;j<=m-2;j++)
		{
			if(st[j].fi>st[j+1].fi)
			{
				t=st[j].fi;
				st[j].fi=st[j+1].fi;
				st[j+1].fi=t;
				
				t=st[j].la;
				st[j].la=st[j+1].la;
				st[j+1].la=t;
				
				t=st[j].time;
				st[j].time=st[j+1].time;
				st[j+1].time=t;
			 } 
		}
	}
	search(1);
   if(bol==0)
   {
   	printf("NO\n");
   }
  }
}
void search(int x)
{
	int i,j;
    if(x<n)
    {
			for(i=0;i<=m-1;i++)
		{
			if(st[i].fi==x)
			{
				for(j=0;j<=num[x]-1;j++)
				{
					sum+=st[i+j].time;	
			        search(st[i+j].la);
			        sum=sum-st[i+j].time;
				}
			     break;
			}
		} 
	}
	        if(x==n)
			{
			    if(sum<0&&bol==0)
				{
			        printf("YES\n");
			        bol=1;
				}
		
			}
		   
}

