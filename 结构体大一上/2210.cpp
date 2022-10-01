//2210
#include<malloc.h>
#include<string.h>
#include<stdlib.h>
#include <stdio.h>
int sum=0;
struct st
{
	char s[10];
	int n;
	struct st *next;
};
struct st * creat(int num)
{
	struct st *p,*q,*head;
	int i;
	head=p=q=NULL;
	for(i=0;i<=num-1;i++)
	{
		p=(struct st *)malloc(sizeof(struct st));
		scanf("%s",p->s);
		scanf("%d",&p->n);
		if(q==NULL)
		{
			head=q=p;
		}
		else
		{
			q->next=p;
			q=p;
		}
	}
	p->next=NULL;
	return head;
}
void print(struct st *head,int ss)
{
	sum++;
	struct st *p,*q;
	int max=0;
	char maxi[10];
	float ave=0;
	for(p=head;p!=NULL;p=p->next)
	{
		ave=ave+ p->n;
		if(p->n > max)
		{
			max=p->n;
			strcpy(maxi,p->s);
		}
	}
	ave=ave/ss;
	printf("%d ",sum);
	printf("%.2f %s %d\n",ave,maxi,max);
}
main()
{
  int n;
  int m;
  int count;
  scanf("%d",&count);
  while(count>0)
  {
  	  count--;
	  scanf("%d",&n);
      struct st *a=creat(n);
      print(a,n);
  }
}
