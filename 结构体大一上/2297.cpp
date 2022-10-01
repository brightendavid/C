#include<malloc.h>
#include<string.h>
#include<stdlib.h>
#include <stdio.h>
struct s
{
	char s[10];
	int v;
}sg[100];
main()
{
  int i,j;
  int n,T;
  scanf("%d",&T);
  int t;
  char str[100];
  while(T>0)
  {
  	T--;
  	scanf("%d",&n);
  	for(i=0;i<=n-1;i++)
  	{
  		scanf("%s",sg[i].s);
  		scanf("%d",&sg[i].v);
	}
	for(i=0;i<=n-1;i++)
	{
		for(j=0;j<=n-2;j++)
		{
			if(sg[j].v>sg[j+1].v)
			{
				t=sg[j].v;
				sg[j].v=sg[j+1].v;
				sg[j+1].v=t;
			   strcpy(str,sg[j].s);
			    strcpy(sg[j].s,sg[j+1].s);
			       strcpy(sg[1+j].s,str);
			}
		}
	}
	for(i=0;i<=n-1;i++)
	{
		printf("%s ",sg[i].s);
		printf("%d\n",sg[i].v);
	}
  }
}
