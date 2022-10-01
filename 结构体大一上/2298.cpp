#include<malloc.h>
#include<string.h>
#include<stdlib.h>
#include <stdio.h>
struct s
{
	int l;
	int v;
}sg[100];
main()
{
  int i,j;
  int n,T;
  scanf("%d",&T);
  int t;
  char str[100];
  int k;
  while(T>0)
  {
  	T--;
  	scanf("%d",&n);
  	for(i=0;i<=n-1;i++)
  	{
  		scanf("%d",&sg[i].l);
  		scanf("%d",&sg[i].v);
	}
	for(i=0;i<=n-1;i++)
	{
		for(j=0;j<=n-2;j++)
		{
			if(sg[j].l>sg[j+1].l)
			{
				t=sg[j].v;
				sg[j].v=sg[j+1].v;
				sg[j+1].v=t;
		        t=sg[j].l;
				sg[j].l=sg[j+1].l;
				sg[j+1].l=t;
			}
		}
	}
	for(i=0;i<=n-1;i++)
	{
		for(k=1;k<=sg[i].v;k++)
		{
					printf(">+");
				for(j=1;j<=sg[i].l-2;j++)
				{
					printf("-");
				}
				printf("+>\n");
			
		}
		printf("\n");
	
	}
	
  }
}
