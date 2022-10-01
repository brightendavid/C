#include<malloc.h>
#include<string.h>
#include<stdlib.h>
#include <stdio.h>
struct st
{
	int num;
	struct st * next;
};
/*struct st *creat(int sum)
{
	struct st *p,*q,*head;
	head=p=q=head;
	int i;
	for(i=0;i<=sum-1;i++)
    {
    	p=(struct st *)malloc(sizeof(struct st));
    	scanf("%d",&p->num);
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
	p->next=NULL;
	return head;
}*/
struct st * creat(int n)//½¨Á¢Á´±í 
{
	struct st *q,*p,*head;
	int test;
	head=q=NULL;
	int i;
	for(i=0;i<n;i++)
	{
		p=(struct st *)malloc(sizeof(struct st));
	
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
struct st * fun(struct st *head)
{
	struct st *p,*q,*t;
	p=q=head;
	int count=0;
	q=head->next;
	t=p;
	//printf("2424");
	while(q!=NULL)
	{
		count++;
	    head=q;
	    t=q->next;
	    q->next=p;
	    if(t==NULL)
	    {
	    	break;
		}
	    if(count==1)
	    {
	    	p->next=NULL;
		}
	    p=q;
	    q=t;
	}
	return head;
}
/*struct st * fun (struct st * head)
{
	struct st *q,*p,*t;
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
}*/
main()
{
  int n;
  int count=0;
  struct st *p,*q,*head;
  scanf("%d",&n);
   // getchar();
  struct st *a=creat(n);
                          
  a=fun(a);
 
  count=0;
  for(p=a;p!=NULL;p=p->next)
  {

  	printf("%d ",p->num);
  
  }
}
