#include<stdio.h>
#include<malloc.h>
#include<string.h>
struct ss
{
	int  x;
	int top;
	struct  ss *next;
};
struct ss *creat()
{
	int i,j;
	struct ss *head;
	head=NULL;
	head=(struct ss *)malloc(sizeof(struct ss));
	head->next=NULL;
	head->x=-1;
	return head;
}
struct ss *add(int x,struct ss *head)
{
	struct ss *p,*q;
	p=(struct ss* )malloc(sizeof(struct ss));
	p->next=head;
	p->x=x;
	head=p; 
	return head;
}
void print(struct ss *head)
{
	struct ss *p,*q;
	p=head;
	while(p!=NULL)
	{
		printf("%d ",p->x);
		p=p->next;
	}
}
void des(struct ss *head)
{
	struct ss *p,*q;
	p=head;
	while(p!=NULL)
	{
		q=p->next;
		free(p);
		p=q;
	}
}
main()
{
	int i;
	struct ss *a=creat();
	for(i=0;i<=10;i++)
	{
		a=add(i,a);
	}
	print(a);
	des(a);
}
