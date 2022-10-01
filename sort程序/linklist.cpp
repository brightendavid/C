#include<malloc.h>
#include<string.h>
#include<stdlib.h>
#include <stdio.h>
#include <math.h>
typedef struct node{
	int data;
	struct node *next;
}node; 
node *creat(){
	node *head ,*tail,*p;
	int num;
	head=tail=NULL;
	printf("please insert your num");
	scanf("%d",&num);
	//循环链表代码 有空的头节点
	{
    	head=(node *)malloc(sizeof(node)); 
    	tail=head;
    	head->next=NULL;//没有元素 
		while(num!=-1){           
			p=(node *)malloc(sizeof(node));
			p->data=num;
			if(head==tail){
				head->next=p;//第一个元素P 
			}
			tail->next=p;
			tail=p;
			tail->next=head->next;
			scanf("%d",&num);
		}
	}
	//单向链表代码 不带空的头节点 
/*	while(num!=-1){
		p=(node *)malloc(sizeof(node));
		p->data=num;
		p->next=NULL;
		if(head==NULL){
			head=tail=p;
		}
		else
		{
			tail->next=p;
			tail=p;
		}
		scanf("%d",&num);
	}*/ 
	
	
	return head;
}
void travel(node *L){
	node *p;
	p=L;
	//单向 
	/*while(p!=NULL){
		printf("%d",p->data);
		printf("\n");
		p=p->next;
	}*/
	//循环链表 
	p=L->next;
	while(p->next!=L->next){
		printf("%d",p->data);
		printf("\n");
		p=p->next;
	}
}
void freelist(node *L){
	node *p,*q;
	p=q=L;
	q=p->next;
/*	while(q!=NULL){//单向链表代码 
		free(p);
		p=q;
		 q=q->next;
	}*/
	while(q->next!=L->next){//循环链表代码 
		free(p);
		p=q;
		 q=q->next;
	}
}
void tailinsert(node *L,int x){
	node *p,*q;
	p=L;
	/*while(p->next!=NULL){
		p=p->next;
	}
	q=(node *)malloc(sizeof(node));
	q->data=x;
	q->next=NULL;*/ 
	while(p->next!=L->next){//循环链表代码 
		p=p->next;
	}
	q=(node *)malloc(sizeof(node));
	p->next=q;
	q->data=x;
	q->next=L->next;
}
node * headinsert(node *L,int x){
	node *p,*q;
	p=(node *)malloc(sizeof(node));
	p->data=x;
	//单向链表 
	{
		/*
		p->next=L;
		L=p;*/
	}

	//循环链表
	{
			while(q->next!=L->next){//循环链表代码 
				q=q->next;//q指向最后元素 
			}
		p->next=L->next;
		L->next=p;
		q->next=p;
	} 
	return L;
}

main()
{
  node *a;
  a=creat();
  travel(a);
  freelist(a);
}
