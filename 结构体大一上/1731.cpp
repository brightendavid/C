#include<malloc.h>
#include<string.h>
#include<stdlib.h>
#include <stdio.h>
struct a
{
	int x;
	struct a *next;
 };
 struct a *creat()
 {
 	struct a *q,*p,*head,*t;
 	head=q=p=NULL;
 	int i;
 	while(1)
 	{
 		scanf("%d",&(p->x));
	 	p=(struct a *)malloc (sizeof(struct a));
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
	  q->next =NULL;
	 return head;
 }
struct a *fun(struct a *head)
{
	
     int t;
	struct a *p=head,*q,*pre,*r;
	p=head;
	q=head;
   
 	
}

main()
{
  int n;
  int i,j;
  struct a *p;
  int s[100];
  //scanf("%d",&n);
  i=0;
  	struct a *b =creat();
    for(p=b;p!=NULL;p=p->next)
  {
  	s[i]=p->x;
  	i++;
  }
  i--;
//	fun(b);
for(p=b;p!=NULL;p=p->next)
  {
  	p->x=s[i];
  	i--;
  }
  for(p=b;p!=NULL;p=p->next)
  {
  	printf("%d ",p->x);
  }
  
}
