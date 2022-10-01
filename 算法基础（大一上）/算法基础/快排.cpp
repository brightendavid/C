#include<malloc.h>
#include<string.h>
#include<stdlib.h>
#include <stdio.h>
int a[10]={8,6,3,5,6,7,4,3,2,4}; 
void swap(int *p,int *q);
void quicksort(int a[],int s,int e);
main()
{
	int i;
	int len;
	len=sizeof(a)/sizeof(int); 
     quicksort(a,0,len-1);
     for(i=0;i<=len-1;i++)
     {
     	printf("%d,",a[i]);
	 }
}
void quicksort (int a[],int s,int e)
{
	if(s>=e) 
	{
		return;
	}
	int k=a[s];
	int i=s,j=e;
	while(i!=j)
	{
		while(j>i&&a[j]>=k)
		{
			--j;
		}
		swap(&a[i],&a[j]);
		while(i<j&&a[i]<=k)
		{
			++i;
		}
		swap(&a[i],&a[j]);
	}
	quicksort(a,s,i-1);
	quicksort(a,i+1,e);
 }
 void swap(int *p,int *q)
 {
 	int t;
 	t=*q;
 	*q=*p;
 	*p=t;
 }
