#include<malloc.h>
#include<string.h>
#include<stdlib.h>
#include <stdio.h>
struct s
{
	int ai;
	int bi;
	int w;
}lu[200001];
main()
{
  int i,j;
  int n,m;
  int bol=1;
  int t;
  int mini;
  int ai,bi,w;
  int bol2;
  int maxw=0;
  int count[1001];
  while(scanf("%d%d",&n,&m)!=EOF)
  {
	  bol=1;
	  bol2=0;
       for(i=1;i<=m;i++)
       {
          scanf("%d%d%d",&lu[i].ai,&lu[i].bi,&lu[i].w);
          count[lu[i].ai]++;
          count[lu[i].bi]++;
	   }
	   for(i=1;i<=n;i++)
	   {
	   	if(count[i]==0)
	   	{
	   		printf("-1\n");
	   		bol=0;
	   		break;
		}
		if(count[i]==1)
		{
			mini=i;
			for(j=0;j<=m;j++)
			{
				if(lu[j].ai==mini||lu[j].bi==mini)
				{
					if(lu[j].w>maxw)
					{
						t=j;
						maxw=lu[j].w;
					}
				}
			}
		}
		if(count[i]<=1)
		{
			bol2=1;
		}
	   }
	   if(bol2==0&&bol==1)
	   {
	   	printf("-1\n");
	   }
	   if(bol==1&&bol2!=0)
	   	printf("%d %d\n",lu[t].ai,lu[t].bi);
  }
  
}
