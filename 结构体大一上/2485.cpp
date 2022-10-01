#include<malloc.h>
#include<string.h>
#include<stdlib.h>
#include <stdio.h>
struct student
{
	int x;
    char a[10];
    int y;
    struct student *next;
 };
struct student * creat()
{
	struct student *q,*p,*head;
	int num;
	int test;
	head=q=NULL;
	int i;
	while(scanf("%d",&i)!=EOF&&i!=0)
	{
		p=(struct student *)malloc(sizeof(struct student));
		p->x=i;
		scanf("%s",p->a);
		scanf("%d",&p->y);
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
struct student * creat2(int n)
{
	struct student *q,*p,*head;
	int num;
	int test;
	head=q=NULL;
	int i;
	for(i=0;i<n;i++)
	{
		p=(struct student *)malloc(sizeof(struct student));
		scanf("%d",&p->x);
		scanf("%s",p->a);
		scanf("%d",&p->y);
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
void fun(struct student *head1,struct student *head2)
{
		struct student *q,*p;
		for(p=head1;p!=NULL;p=p->next)
		{	
		    
			if( p->x  <  head2->x && p->next->x > head2->x)
			{
				q=p->next;
				p->next=head2;
				head2->next=q;
				break;
			}
			else if(p->x==head2->x)
				{
					printf("Record exists!\n");
					break;
				}
		}
}
main()
{
	struct student *q,*p,*head;
  struct student *a =creat();
  struct student *b =creat2(1);
  fun(a,b);
  for(p=a;p!=NULL;p=p->next)
  {
  	printf("%d %s %d\n",p->x,p->a,p->y);
  }
}
