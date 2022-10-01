#include<string.h>
#include <stdio.h>
#include<stdlib.h>
 struct zy
 {
 	int  d;
 	int v;
 };
 struct zy s[100];
main()
{
	int i,j;
	int t;
	int n;
	int sum=0;
	int sum0=0;
	int max=0;
	while(scanf("%d",&n)!=EOF)
	{
			max=0;
			sum=0;
			sum0=0;
			for(i=0;i<=n-1;i++)
			{
				scanf("%d",&s[i].d);
				if(max<s[i].d)
				{
					max=s[i].d;
				}
			}
			for(i=0;i<=n-1;i++)
			{
				scanf("%d",&s[i].v);
				sum0+=s[i].v;
			}
			for(j=0;j<=n-1;j++)
			{
				for(i=1;i<=n-1;i++)
			   {
				  if(s[i-1].d>s[i].d)
				  {
				  	t=s[i-1].d;
				  	s[i-1].d=s[i].d;
				  	s[i].d=t;
				  	t=s[i-1].v;
				  	s[i-1].v=s[i].v;
				  	s[i].v=t;
				  }
				  else if(s[i-1].d==s[i].d)
				  {
				  	if(s[i-1].v<s[i].v)
				  	{
				  	t=s[i-1].d;
				  	s[i-1].d=s[i].d;
				  	s[i].d=t;
				  	t=s[i-1].v;
				  	s[i-1].v=s[i].v;
				  	s[i].v=t;
					}
				  }
			   }
			}
			t=0;
		    for(i=1;i<=max;i++)
		    {
		        if(s[t].d>=i&&t<n)
				{ 
				   sum+=s[t].v;
				  // printf("  %d  ",sum);
				   t++;
				   while(s[t].d<i+1) 
				 	{
				 		t++;
				 		if(t==n)
				 		{
				 			break;
						}
					 }
				 }
			}
			/*printf("%d\n",max);
			for(i=0;i<=n-1;i++)
			{
				printf("%d %d\n",s[i].d,s[i].v);
			}*/
			printf("%d\n",sum0-sum);
	}
}
