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
	//ѭ��������� �пյ�ͷ�ڵ�
	{
    	head=(node *)malloc(sizeof(node)); 
    	tail=head;
    	head->next=NULL;//û��Ԫ�� 
		while(num!=-1){           
			p=(node *)malloc(sizeof(node));
			p->data=num;
			if(head==tail){
				head->next=p;//��һ��Ԫ��P 
			}
			tail->next=p;
			tail=p;
			tail->next=head->next;
			scanf("%d",&num);
		}
	}
	//����������� �����յ�ͷ�ڵ� 
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
	//���� 
	/*while(p!=NULL){
		printf("%d",p->data);
		printf("\n");
		p=p->next;
	}*/
	//ѭ������ 
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
/*	while(q!=NULL){//����������� 
		free(p);
		p=q;
		 q=q->next;
	}*/
	while(q->next!=L->next){//ѭ��������� 
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
	while(p->next!=L->next){//ѭ��������� 
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
	//�������� 
	{
		/*
		p->next=L;
		L=p;*/
	}

	//ѭ������
	{
			while(q->next!=L->next){//ѭ��������� 
				q=q->next;//qָ�����Ԫ�� 
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
