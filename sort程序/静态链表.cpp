#include<malloc.h>
#include<string.h>
#include<stdlib.h>
#include <stdio.h>
#include <math.h>
#define maxsize 30
typedef char elemtype;
typedef struct {
	int cur;
	elemtype data;
} slink,slinklist[maxsize];
void initspace_sl(slink *space){
	int i;
	for(i=0;i<maxsize-1l;i++)
	{
		space[i].cur=i+1;
	}
	space[maxsize-1].cur=0;
}
int malloc_sl(slink *space)
{
	int i;
	i=space[0].cur;
	if(space[0].cur)
	{
		space[0].cur=space[i].cur;
	}
	return i;
}
int free_sl(slink *space,int k)
{
	space[k].cur=space[0].cur;
	space[0].cur=k;
}
int difference_sl(slink *space,int *k)
{
	int q,w,r,t,y,u,a;
	elemtype ch;
	initspace_sl(space);
	*k=malloc_sl(space);
	q=*k;
	scanf("%d%d",&w,&r);
	for(int i=1;i<=w;i++)
	{
		t=malloc_sl(space);
		scanf("%c",&space[t].data);
		space[q].cur=t;
		q=t;
	}
	space[q].cur=0;
	for(int j=1;j<=r;j++)
	{
		scanf("%c",&ch);
		y=*k;
		u=y;
		while(space[y].data!=ch&&y!=space[q].cur)
		{
			u=y;
			y=space[y].cur;
		}
		if(y==space[q].cur)
		{
			a=malloc_sl(space);
			space[a].data=ch;
			space[a].cur=space[q].cur;
			space[q].cur=a;
			q=a;
		}
		else
		{
			space[u].cur=space[y].cur;
			free_sl(space,y);
			if(y==q){
				q=u;
			}
		}
	}
 } 
main()
{
	slinklist space;
  int x,y;
  difference_sl(space,&x);
  y=x;
  while(y)
  {
  	printf("%3d %c",y,space[y].data);
  	y=space[y].cur;
  }
}
