#include<malloc.h>
#include<string.h>
#include<stdlib.h>
#include <stdio.h>
struct s
{
	int x;
	struct s *next;
};
struct s * creat(int n)
{
	struct s *head,*p,*q;
	head=p=q=NULL;
	int i,j;
	for(i=0;i<=n-1;i++)
	{
		p=(struct s *)malloc(sizeof(struct s));
		scanf("%d",&p->x);
		if(head==NULL)
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
void swap(struct s *x,struct s *y)//交换函数 
{
	int t;
	t=x->x;
	x->x=y->x;
	y->x=t;
}
void query (struct s *head)//打印函数 
{
	struct s *p;
	for(p=head;p!=NULL;p=p->next)
	{
			printf("%d ",p->x);
	}
}
void fun(struct s *head)
{

	struct s *p ;
	struct s *q;
	for(p=head;p->next != NULL;p=p->next);
	for(p=head;p->next!=NULL;p=p->next)
	{
		for(q=head;q->next!=NULL;q=q->next)
		{
			if(q->x>0&&q->next->x<0)
			{
				swap(q,q->next);
			}
		}
	}

}
main()
{
	struct s *p,*q;
	int n;
	scanf("%d",&n);
  struct s *a=creat(n);	
  fun(a);
  query(a);
  
}
