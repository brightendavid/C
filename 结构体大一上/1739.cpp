//1739
#include<malloc.h>
#include<string.h>
#include<stdlib.h>
#include <stdio.h>
struct st
{
	int n;
	struct st *next;
};
struct st * creat(int num)
{
	struct st *p,*q,*head;
	int i;
//	printf("1\n");
	head=p=q=NULL;
	for(i=0;i<=num-1;i++)
	{
		p=(struct st *)malloc(sizeof(struct st));
		scanf("%d",&p->n);
	//	printf("4");
		if(q==NULL)
		{
			head=q=p;
		}
		else
		{
			q->next=p;
			q=p;
		}
	//	printf("2");
	}
	p->next=NULL;
//	printf("111\n");
	return head;
}
void search(struct st *head,int e)
{
	struct st *p,*q,*d;
	d=NULL;
	int t;
	int bol=0;
	for(p=head;p->next!=NULL;p=p->next)
	{
		if(p->n==e)
		{
			t=p->next->n;
			p->next->n=p->n;
			p->n=t;
			bol=1;
			break;
		}
		else if((p->n < e) && (p->next->n > e))
		{
			q=p->next;
			d=(struct st *)malloc(sizeof(struct st));
			d->n=e;
			p->next=d;
			d->next=q;
			bol=0;
	        break;
		}
		else if(p->n < e)
		{
			bol=0;
		//	printf("22");
		
		}
	}
//	printf("3");
	if(bol==0)
	{
		printf("no\n");
	}
}
void print(struct st *head)
{
	struct st *p,*q;
	for(p=head;p!=NULL;p=p->next)
	{
		printf("%d " ,p->n);
	}
}
main()
{
  int n;
  int ss;
  scanf("%d",&ss);
  scanf("%d",&n);
  struct st *a=creat(n);
  search(a,ss); 
  print(a);
}
