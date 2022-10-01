#include<malloc.h>
#include<string.h>
#include<stdlib.h>
#include <stdio.h>
#include <math.h>
struct ss
{
	int x;
	struct ss *next;
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
void add(int x,struct ss *head,struct qnode *qu)
{
	struct ss *p,*q;
    for(q=head;q!=NULL;q=q->next);
    q=(struct ss* )malloc(sizeof(struct ss));
    q->x=x;
    q->next=NULL;
    qu->rear=q;
    if(queue->front==NULL)
    {
    	qu->front=q;
	}
    
}
struct qnode
{
	struct ss *rear,*front;
	int maxsize;
};
struct qnode * creatqueue()
{
	struct qnode *queue=(struct qnode *)malloc(sizeof(struct qnode));
	qnode->front=NULL;
	qnode->rear=NULL;
	return queue;
}
main()
{
	struct ss *a=creat();
	struct qnode *q=creatqueue();
  int i,j;
  struct ss *p;
  for(i=1;i<=10;i++)
  {
  	add(i,a,q);
  }
  for(p=q;p!=NULL;p=p->next)
  {
  	printf("%d",p->x);
  }
}
