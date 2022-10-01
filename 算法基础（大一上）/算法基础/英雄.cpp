#include<malloc.h>
#include<string.h>
#include<stdlib.h>
#include <stdio.h>
int b[20][20];
int n,m;
int c[20][20];
int t;
int bol=0;
int pan(int x,int y,int sum);
void search(int x,int y,int sum);
struct sp
{
	int x;
	int y;
}s,p;
main()
{
  int i,j;
  char a[20][20];
  while(scanf("%d%d%d",&n,&m,&t)!=EOF&&n!=0||m!=0||t!=0)
  {
  	bol=0;
		  	for(i=0;i<=m-1;i++)//i m
		  {    
		    scanf("%s",a[i]);
		    for(j=0;j<=n-1;j++)//j n
			{
				c[i][j]=1;
				if(a[i][j]=='S')//始点 
				{
					s.x=i;
					s.y=j;
					b[i][j]=-1;
				}
				if(a[i][j]=='P')//终点 
				{
					p.x=i;
					p.y=j;
					b[i][j]=1;
				}
				if(a[i][j]=='*')//墙壁 
				{
					b[i][j]=0;
				}
				if(a[i][j]=='.')//路 
				{
					b[i][j]=1;
				}
			 }
		   }
		 /*  for(i=0;i<=m-1;i++)
		   {
			   	for(j=0;j<=n-1;j++)
			   	{
			   		printf("%d",b[i][j]);
				}
				printf("\n");
		   }
		   printf("%d %d\n",p.x,p.y);
		   printf("%d %d\n",s.x,s.y);*/
		   search(s.x,s.y,0);
		   if(bol==1)
		   {
		   	printf("YES\n");
		   }
		   else
		   {
		   	 printf("NO\n");
		   }
  }
  
}
void search(int x,int y,int sum)
{
	c[x][y]=0;
	if(x==p.x&&y==p.y)
	{
		//printf("YES\n");
		bol=1;
		return;
	}
	else
	{
	    if(pan(x-1,y,sum+1))//shang不是第一行 
		{
		    search(x-1,y,++sum);
		}  
		if(pan(x+1,y,sum+1))//xia不是最后一行
		   search(x+1,y,++sum);
		if(pan(x,y+1,sum+1))//you
		   search(x,y+1,++sum);
		if(pan(x,y-1,sum+1))//zuo
		   search(x,y-1,++sum); 
	}
	c[x][y]=1;
	return;
}
int pan(int x,int y,int sum)
{
	if(sum>t)
	{
	/*	printf("NO");
		printf("%d %d\n",x,y);*/
		return 0;
	}
	if(x<0||x>m-1)
	{
	/*	printf("NO");
			printf("%d %d\n",x,y);*/
		return 0;
	}
	if(y<0||y>n-1)
	{
	/*	printf("NO");
			printf("%d %d\n",x,y);*/
		return 0;
	}
	if(b[x][y]==0)
	{
	/*	printf("NO");
		printf("%d %d\n",x,y);*/
		return 0;
	}
	if(c[x][y]==0)
	{
		return 0;
	}
	return 1;
}
