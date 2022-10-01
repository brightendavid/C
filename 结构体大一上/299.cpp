#include<malloc.h>
#include<string.h>
#include<stdlib.h>
#include <stdio.h>
struct s
{
	char s[10];
	int v;
}sg[1000];
main()
{
  int i,j;
  int n,T;
  n=0;
  scanf("%d",&T);
  int rank[1000];

  int t;
  char str[100];
  while(T>0)
  {
  	T--;
  
    i=0;
  	scanf("%s",str);
  	while(scanf("%s%d",sg[i].s,&sg[i].v)!=EOF&&(strcmp(sg[i].s,"0")!=0||sg[i].v!=0))
	{
		i++;		
				
	}  	
  		n=i;
  		for(i=0;i<=n-1;i++)
  		{
  			rank[i]=n;
		}
     for(i=0;i<=n-1;i++)
	{
		for(j=0;j<=n-1;j++)
		{
			if(sg[i].v>=sg[j].v)
			{
	        	rank[i]--;
			}
		}
	}
	
	
	
	for(i=0;i<=n-1;i++)
	{
	 if(strcmp(str,sg[i].s)==0)
	 {
	 	printf("%d\n",1+rank[i]);
	 }
	}
  }
}
