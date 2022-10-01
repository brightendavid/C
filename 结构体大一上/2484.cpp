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
void search(int s,struct student *head)
{
	struct student *q,*p;
	int bol=0;
	for(p=head;p!=NULL;p=p->next)
	{
		if(p->x==s)
		{
			printf("%d %s %d",p->x,p->a,p->y);
			bol=1;
			break;
		}
	}
	if(bol==0)
	{
		printf("Not found");
	 } 
	
}
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
main()
{
  struct student *a=creat();
  int z;
  scanf("%d",&z);
  search(z,a);
}
