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
struct student * creat2(struct student *head1,int m)//建立链表 2
{
	struct student *q,*p,*t,*head;
	head=q=NULL;
	for(t=head1;t!=NULL;t=t->next)
	{
		if((t->ran)%2==m)
		{
			p=(struct student *)malloc(sizeof(struct student));
		    p->num=t->num;
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
	}
	q->next=NULL;
	return head;
}
struct student * creat(int n)//建立链表 
{
	struct student *q,*p,*head;
	int num;
	int test;
	int w;
	head=q=NULL;
	int t=1;
	int i;
	int count=1;
	while(count<=n&&scanf("%d",&w)!=EOF)
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
		count++;
	}
	q->next=NULL;
	return head;
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
     int n;
     scanf("%d",&n);
     struct student *a=creat(n);
     struct student *b=creat2(a,1);
     struct student *c=creat2(a,0);
     query(b);
     printf("\n");
    query(c);
}

