#include<malloc.h>
#include<string.h>
#include<stdlib.h>
#include <stdio.h>
struct a
{
	char s[100];
	struct a *next;
 };
 struct a *creat(int n)
 {
 	struct a *q,*p,*head,*t;
 	head=q=p=NULL;
 	int i;
 	char  st[100];
 	for(i=0;i<=n-1;i++)
 	{
 		
 		p=(struct a *)malloc (sizeof(struct a));
		 scanf("%s",p->s);
	
				if(q==NULL)
		 		{
		 			head=q=p;
				 }
				 else
				 {
				 	q->next=p;
				 	q=p;
				 }
		    	 q->next =NULL;
	    

	}
 		
	 return head;
 }
struct a *fun(struct a *head)
{
	

	struct a *p=head,*q,*pre,*r;
    while(p!=NULL)
    {
        q=p->next;pre=p;
        while(q!=NULL)
        {
            if(strcmp(p->s,q->s)==0)
            {
                r=q;pre->next=q->next;
                //r=q;p->next=q->next; 
                q=q->next;
                free(r);
                //break;
            }
            else
            {
                pre=q;
                q=q->next;
            }
        }
        p=p->next;
    }
}
void zhuanhuan(struct a *head)
{
    struct a *p=head,*q,*pre,*r;
    while(p!=NULL)
    {
        q=p->next;pre=p;
        while(q!=NULL)
        {
            if(strcmp(p->s,q->s)==0)
            {
                r=q;pre->next=q->next;
                //r=q;p->next=q->next; 
                q=q->next;
                free(r);
            }
            else
            {
                pre=q;
                q=q->next;
            }
        }
        p=p->next;
    }
}
main()
{
  int n;
  int i,j;
  struct a *p;
  scanf("%d",&n);
  	struct a *b =creat(n);
//	zhuanhuan(b);
	fun(b);
  for(p=b;p!=NULL;p=p->next)
  {
  	printf("%s ",p->s);
  }
  
}
