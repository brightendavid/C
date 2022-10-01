//1230
#include<malloc.h>
#include<string.h>
#include<stdlib.h>
#include <stdio.h>
int search(int n);
main()
{
  int i,j;
  int n;
  int t,max=0;
  int maxi=1;
  int a;
  while(scanf("%d",&n)!=EOF)
  {
  	max=0;
  	maxi=1;
  	for(i=1;i<=n;i++)
  	{
  		scanf("%d",&a);
  		t=search(a);
  		if(t>max||t==max&&maxi>a)
  		{
  			max=t;
  			maxi=a;
		}
	}
	printf("%d\n",maxi);
   } 
}
int search(int n)
{
	int i;
	int s,t;
	int num=0;
	t=0;
	for(i=1,s=0;i<=n;i++)
	{
		s+=n/i;
	
	}
	for(i=1,t=0;i<n;i++)
	{
		t+=(n-1)/i;
	}
	num=s-t;
	return num;
}
