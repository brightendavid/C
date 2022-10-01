#include<malloc.h>
#include<string.h>
#include<stdlib.h>
#include <stdio.h>
struct student
{
	int num;
	struct student *next;
};
struct student * creat(int n)//建立链表 
{
	struct student *q,*p,*head;
	int num;
	int test;
	head=q=NULL;
	int i;
	for(i=0;i<n;i++)
	{
		p=(struct student *)malloc(sizeof(struct student));
		scanf("%d",&p->num);
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
	q->next=NULL;
	return head;
}
void swap(struct student *x,struct student *y)//交换函数 
{
	int t;
	t=x->num;
	x->num=y->num;
	y->num=t;
}
void fun(struct student *a)//排序 
{
	struct student *p ;
	struct student *q;
	for(p=a;p->next!=NULL;p=p->next)
	{
		for(q=a;q->next!=NULL;q=q->next)
		{
			if(q->num>q->next->num)
			{
				swap(q,q->next);
			}
		}
	}
}
void query (struct student *head)//打印函数 
{
	struct student *p;
	for(p=head;p!=NULL;p=p->next)
	{
			printf("%d ",p->num);
	}
}
main()
{
   int i,j;
   int n,m;
   scanf("%d",&n);
   struct student *a=creat(n);
   fun(a);
    query(a);
}

