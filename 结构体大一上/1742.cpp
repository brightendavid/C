#include<malloc.h>
#include<string.h>
#include<stdlib.h>
#include <stdio.h>
struct student
{
	int num;
	struct student *next;
};

struct student *creat()
{
	struct student *q,*p,*head;
	int num;
	int test;
	head=q=NULL;
	int i;
	int count=0;
	
	while(scanf("%d",&i)!=EOF) 
	{
     //	printf("1");
		p=(struct student *)malloc(sizeof(struct student)); 
		p->num=i;
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
	/*	if(count==6)
		{
			break;
		}*/
	
	}
	//printf("3"); 
	q->next=NULL;
	return head;
}
struct student *fun (struct student *head)
{
	struct student *q,*p,*t;
	p=head;
	t=NULL;
	q=p->next;
	t=q->next;
    int count=0;
	while(q!=NULL)
	{
		count++;
	//	printf("%d\n",count);
		t=q->next;
		q->next=p;
		if(p==head)
		{
			p->next=NULL;
		}
		p=q;
		q=t;
	}
		if(p==head->next)
		{
			p->next=head;
			head->next=NULL;
		}

	return p;
}
main()
{
  struct student *a =creat();
  a=fun(a);
  struct student *q,*p,*head,*t;
 head=a;
  for(p=head;p!=NULL;p=p->next)
  {
  	printf("%d ",p->num);
  }
}
