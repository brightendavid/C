#include<malloc.h>
#include<string.h>
#include<stdlib.h>
#include <stdio.h>
struct student
{
	int num;
	int ran;
	struct student *next;
};
struct student * creat()//建立链表 
{
	struct student *q,*p,*head;
	int num;
	int test;
	int w;
	head=q=NULL;
	int t=1;
	int i;
	while(scanf("%d",&w)!=EOF&&w!=-1)
	{
		p=(struct student *)malloc(sizeof(struct student));
		p->num=w;
		p->ran=t;
		t++;
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
void fun(struct student *a,int n)//排序 
{
	struct student *p ,*p1,*q1;
	struct student *q;
	int count=0;
	int s=1;
	int i;
	for(p=a;p->next != NULL;p=p->next)
	{
		if(p->num < n)
		{
			count++;
		}
		s++;
	}
	for(i=0;i<=s;i++)
	for(p=a;p->next!=NULL;p=p->next)
	{
		if(p->num > n && p->ran<count)
		{
			swap(p,p->next);
		}
		if(p->next->num< n &&p->next->ran > count )
		{
			swap(p,p->next);
		}
	}
   	for(p=a;p->next->next!=NULL;p=p->next);
	for(q=a;q->next->num < n;q=q->next);
	p1=p->next;
	q1=q->next;
	p->next=NULL;
	q->next=p1;
	p1->next=q1;
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
     struct student *p;
     int s;
     int t;
   struct student *a=creat();
	for(p=a;p->next!=NULL;p=p->next);
	s=p->num;
	fun(a,s);
	query(a);
}

