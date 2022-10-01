#include<malloc.h>
#include<string.h>
#include<stdlib.h>
#include <stdio.h>
	int a[10]={2,5,3,1,5,6,7,3,3,6};
	int b[10];
void bing(int a[],int x,int n,int y,int ss[]);
void sort(int a[],int x,int y,int temp[]);
main()
{
	int i,j;

  int size=sizeof(a)/sizeof(int);
  sort(a,0,size-1,b); 
  for(i=0;i<=9;i++)
  {
  	printf("%d,",a[i]);
  }
}
void sort(int a[],int x,int y,int temp[])
{
	int n,m;
	if(x<y)
	{
		n=(x+y)/2;
		sort(a,x,n,temp);
		sort(a,n+1,y,temp);
		bing(a,x,n,y,temp);
	}
}
void bing(int a[],int x,int n,int y,int ss[])
{
	int pb=0;
	int p1=x,p2=n+1;
	while(p1<=n&&p2<=y)
	{
		if(a[p1]<a[p2])
		{
			ss[pb++]=a[p1++];
		}
		else
		{
			ss[pb++]=a[p2++];
		}
	}
	while(p1<=n)
	{
		ss[pb++]=a[p1++];
	}
	while(p2<=y)
	{
		ss[pb++]=a[p2++];
	}
	for(int i=0;i<y-x+1;++i)
	{
		a[x+i]=ss[i];
	}
}
