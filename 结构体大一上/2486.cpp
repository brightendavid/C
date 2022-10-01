//2486
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

struct student * fun(struct student *head1,int t)
{
		struct student *q,*p;
		int bol=1;
		p=head1;
		if(head1->x==t)
		{
			head1=head1->next;
			free(p);
			bol=0;
		}
		else
		{
			for(p=head1;p!=NULL;p=p->next)
			{	
				
				    if(p->next->x==t)
					{
						q=p->next;
						p->next=q->next;
						free(q);
						bol=0;
						break;
					}
			}
		
		}
		if(bol==1)
		{
			printf("Not found\n");
		}
		return head1;
}
main()
{
	struct student *q,*p,*head;
  struct student *a =creat();
  int i;
  scanf("%d",&i); 
  a=fun(a,i);
  for(p=a;p!=NULL;p=p->next)
  {
  	printf("%d %s %d\n",p->x,p->a,p->y);
  }
}
