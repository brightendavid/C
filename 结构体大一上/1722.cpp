//1722
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
void fun(struct st *head1,struct st *head2)
{
	struct st *p,*q;
	int t;
	for(p=head1;p->next!=NULL;p=p->next);
	p->next=head2;
	for(p=head1;p->next!=NULL;p=p->next)
	{
		for(q=head1;q->next!=NULL;q=q->next)
		{
			if(q->n<q->next->n)
			{
				t=q->next->n;
				q->next->n=q->n;
				q->n=t;
			}
		 } 
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
  scanf("%d",&n);
  //getchar();
  struct st *a=creat(n);

 // getchar(); 
  scanf("%d",&n);
  struct st *b=creat(n);  
   //   printf("2");
  fun(a,b);
  print(a);
}
