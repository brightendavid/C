#include<malloc.h>
#include<string.h>
#include<stdlib.h>
#include <stdio.h>
int a[]={3,5,2,4,6,7,9,10,4,6};
int b[10];
void sort(int x,int y,int temp[]);
void bing(int a[],int x,int n,int y,int ss[]);
main()
{
	int i;
  sort(0,sizeof(a)/sizeof(int)-1,b);
  for(i=0;i<=sizeof(a)/sizeof(int)-1;i++)
  {
  	printf("%d",a[i]);
  }
}
void sort(int x,int y,int temp[])
{
	if(x<y)
	{
		sort(x,(x+y)/2,temp);
		sort((x+y)/2,y,temp);
		bing(a,x,(x+y)/2,y,temp);
	}
}
void bing(int a[],int x,int n,int y,int ss[])
{
	int i,j;
	int k;
	i=x;
	j=n;
	k=0;
	while(i<=n&&j<=y)
	{
		if(a[i])
	}
}
