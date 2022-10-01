#include<malloc.h>
#include<string.h>
#include<stdlib.h>
#include <stdio.h>
struct student
{
	int num;
	struct student *next;
};
struct student * creat(int n)//½¨Á¢Á´±í 
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
int fun(struct student *head1,struct student *head2)
{
	struct student *p,*q,*t;int bol=1;
	for(p=head1;p!=NULL;p=p->next)
	{
		t=p;
		for(q=head2;q!=NULL;q=q->next)
		{
			
			bol=1;
			if(p->num!=q->num&&p!=NULL)
			{
				bol=0;
				break;
			}
			p=p->next;
		}
		if(bol==1)
		{
			return 1;
		}
		p=t;
	}
	return 0;
}
main()
{
   int i,j;
   int bol;
   int n,m;
   scanf("%d",&n);
   struct student *a=creat(n);
   scanf("%d",&m); 
   struct student *b=creat(m); 
   
   bol=fun(a,b);
   printf("%d",bol);
    
}

