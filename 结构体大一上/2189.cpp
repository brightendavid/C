#include<malloc.h>
#include<string.h>
#include<stdlib.h>
#include <stdio.h>
struct ss
{
	char s[20];
	int  x;
	struct ss *next;
};
struct ss * creat()
{
	struct ss *p,*q;
	struct ss *head;
	char str[20];
	head=p=q=NULL;

	while(scanf("%s",str)!=EOF&&strcmp(str,"#")!=0)
	{
		p=(struct ss*)malloc(sizeof(struct ss));
		strcpy(p->s,str);
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
void add(struct ss *head1,struct ss *head2)
{
		struct ss *p,*q;
		for(p=head1;p->next!=NULL;p=p->next);
		p->next=head2;
}
void swap(struct ss *x,struct ss *y)//½»»»º¯Êý 
{
	int t;
	char str[20];
	t=x->x;
	x->x=y->x;
	y->x=t;
	
	strcpy(str,x->s);
	strcpy(x->s,y->s);
	strcpy(y->s,str);
	/*t=x->test;
	x->test=y->test;
	y->test=t;*/
}
void fun(struct ss *a)//ÅÅÐò 
{
	struct ss *p;
	struct ss *q;
	for(p=a;p->next!=NULL;p=p->next)
	{
		for(q=a;q->next!=NULL;q=q->next)
		{
			if(q->x < q->next->x)
			{
				swap(q,q->next);
			}
		}
	}
}

struct ss * delet (struct ss *head ,char str[20])
{
	struct ss *p,*q;
	for(p=head;p!=NULL;p=p->next)
	{
		if(strcmp(p->next->s,str)==0)
		{
			q=p->next->next;
			free(p->next);
			p->next=q;
			break;
		}
	
	}
	if(strcmp(head->s,str)==0)
	{
		p=head;
		q=head->next;
		free(head);
		head=q;
	}
	return head;
}
main()
{
		struct ss *p,*q;
  struct ss *a=creat();
  /*for(p=a;p!=NULL;p=p->next)
  {
  	printf("%s %d\n",p->s,p->x);
  }*/
  struct ss *b=creat();
  char sss[20];
  add(a,b);
  /*for(p=a;p!=NULL;p=p->next)
  {
  	printf("%s %d\n",p->s,p->x);
  }*/
  fun(a);
  while(scanf("%s",sss)!=EOF&&strcmp(sss,"#")!=0)
  {
  	a=delet(a,sss);
  }
  for(p=a;p!=NULL;p=p->next)
  {
  	printf("%s %d\n",p->s,p->x);
  }
}
