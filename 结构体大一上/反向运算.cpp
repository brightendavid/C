#include<malloc.h>
#include<string.h>
#include<stdlib.h>
#include <stdio.h>
#include <math.h>
struct ListNode
{
	int val;
	struct ListNode *next;
 } ;
 void query (struct ListNode *head)//´òÓ¡º¯Êý 
{
	struct ListNode *p;
	for(p=head;p!=NULL;p=p->next)
	{
			printf("%d ",p->val);
			
	}
}
 struct ListNode * creat()
 {
 	int x;
 	struct ListNode *p,*q,*head;
	 head=q=NULL; 
 	for(int i=0;i<=2;i++)
 	{
 		scanf("%d",&x);
 		if(head==NULL)
 		{
 			head=(struct ListNode *)malloc(sizeof(struct ListNode));
 			p=q=head;
 			head->val=x;
 			head->next=NULL;
		 }
		 else
		 {
		    q=(struct ListNode *)malloc(sizeof(struct ListNode));
		 	p->next=q;
		 	
		 	q->val=x;
		 	q->next=NULL;
		 	p=q;
		 }
	 }
	 return head;
 }
 void add(struct ListNode *head1,struct ListNode *head2)
 {
 	int y;
 		
    struct ListNode *head,*q,*p;
    struct ListNode *p1,*q1;
    head=p=q=NULL;
    p=head1,q=head2;
    int x;
    while(p!=NULL||q!=NULL)
    {
	    if(p!=NULL&&q!=NULL)
	  	{
	  		x=p->val+q->val;
	  		q=q->next;
	     	p=p->next;
		}
		else if(p==NULL)
		{
			x=q->val;
			q=q->next;
		}
	    else if(q==NULL)
	    {
	    	x=p->val;
	     	p=p->next;
		}
		
		
    	if(head==NULL)
 		{
 			head=(struct ListNode *)malloc(sizeof(struct ListNode));
 			p1=q1=head;
 			head->val=x;
 			head->next=NULL;
		 }
		 else
		 {
		    q1=(struct ListNode *)malloc(sizeof(struct ListNode));
		 	p1->next=q1;
		 	q1->val=x;
		 	q1->next=NULL;
		 	p1=q1;
		 }
	}
	
	p=head;
     while(p!=NULL)
	 {
	    y=(p->val)/10;
	 	p->val=(p->val)%10;
	 	if(p->next!=NULL)
	 	{
	 		p->next->val+=y;
		 }
	 	else if(y!=0&&p->next==NULL)
	 	{
	 		q=(struct ListNode*)malloc(sizeof(struct ListNode));
	 		p->next=q;
	 		q->next=NULL;
	 		q->val=y;
		 }
		 p=p->next;
	 }
	 p=head;
	 while(p!=NULL)
	 {
	 	printf("%d ",p->val);
	 	p=p->next;
	 }
	 printf("\n");
  }
main()
{
  struct ListNode *a,*b;
  a=creat();
  b=creat();
  struct ListNode *q,*p;
  p=a;
  q=b;
  int sum=0;
  int s=1;
  query(a);
  query(b);
  printf("\n");
  add(a,b);
  while(p!=NULL||q!=NULL)
  {
  	if(p!=NULL&&q!=NULL)
  	{
  		sum=sum+p->val*s+q->val*s;
  		q=q->next;
     	p=p->next;
	}
	else if(p==NULL)
	{
			sum=sum+q->val*s;
			q=q->next;
	}
    else if(q==NULL)
    {
    	sum=sum+p->val*s;
     	p=p->next;
	}
  	s=s*10;
  }
  printf("%d\n",sum);
}
