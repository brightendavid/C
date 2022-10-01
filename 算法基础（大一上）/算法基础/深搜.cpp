#include<malloc.h>
#include<string.h>
#include<stdlib.h>
#include <stdio.h> 
int path[10];
int b[10];
#define S 8  //0      1    		2			3				4		5			6		7		8		9
int a[10][10]={{0,-1},{2,3,-1},{1,4,3,9,-1},{8,1,4,7,2,-1},{2,3,-1},{6,8,-1},{5,8,-1},{8,-1},{3,5,6,-1},{2,-1}};
void dps(int x,int y); 
int min=10;
main()
{
	int i,j;
	for(i=0;i<=9;i++)
	{
	    b[i]=1;
	}
   dps(1,0);
}
void dps(int x,int y)
{
	int i,j;
	 if(x==S)
	 {
	 	path[y]=x;
	 		printf("depth %d\n",y);
		   	for(i=0;i<=y;i++)
		   	{
		   		printf("%d ",path[i]);
			}
			printf("\n");
			return ;
	 }
	 if(b[x]==0)
	 {
	 	return;
	 }
	 b[x]=0;
	 path[y]=x; 
	 ++y;
	 for(i=0;a[x][i]!=-1;i++)
	 {
	 	dps(a[x][i],y);
	 }
	 b[x]=1;
	 return;
}
