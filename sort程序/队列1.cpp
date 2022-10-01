#include<malloc.h>
#include<string.h>
#include<stdlib.h>
#include <stdio.h>
#include <math.h>
#define ElementType int
#define ERROR NULL
 Queue PtrQ;
typedef struct node
{
	ElementType data;
	struct Node *next;
 }QNode,*QueuePtr;
 typedef struct QNode
 {
 	QueuePtr rear;
 	QueuePtr front;
  }LinkQueue;

ElementType DeleteQ(LinkQueue Q,ElementType *e)
{
	struct node *p ;
	ElementType FrontElem;
	if(Q->front==NULL)
	{
		printf("╤сап©у");
		return ERROR; 
	}
	p=Q->front;
	if(Q.front==Q.rear)
	{
		return 0;
	}
	Q->front->next=p->next;
	*e=p->data;
	if(Q.rear==p)
	{
		Q.rear==Q.front;
	}
	free(p);
	return *e;
}
main()
{
  
}
