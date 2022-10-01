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
main()
{
		struct s *p,*q;
	int n;

	scanf("%d",&n);
  struct s *a=creat(n);	
  int min=a->x;
  for(p=a;p!=NULL;p=p->next)
  {
  	if(p->x < min)
  	{
  		min=p->x;
	}
  }
  printf("%d",min);
}
