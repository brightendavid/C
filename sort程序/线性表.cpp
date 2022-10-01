#include<malloc.h>
#include<string.h>
#include<stdlib.h>
#include <stdio.h>
#include <math.h>
typedef int elem;
typedef struct seqlist{
	elem *list;
	int size;
	int maxsize;
}seqlist; 
void initlist(int x,seqlist *L){
	
	if(x<=0){
		printf("�Ƿ�����<0");
		exit(1);
	}
	
	L->list=(elem*)malloc(x*sizeof(elem));
	
	if(!L->list){
		printf("ʧ�ܷ����ڴ�"); 
		exit(1);
	}
	L->maxsize=x;
	L->size=0;
	
		return ;
}
void again(seqlist *L){
	
	elem *p=(elem *)realloc(L->list,2*L->maxsize*sizeof(elem));
	if(p==NULL){
		printf("�ڴ��ٷ���ʧ��");
		exit(1); 
	}
	L->list=p;
	L->maxsize=2*L->maxsize;
}
void freelist(seqlist *L){
	if(L->list!=NULL){
	free(L->list);
	L->maxsize=L->size=0;
	}
}
void insert(seqlist *L,elem x){
	
	if(L->size==L->maxsize){
		again(L);
	}
	
	L->list[L->size]=x;
	L->size++;
	
}
void printlist(seqlist *L){
	int i=0;
	
	while(i!=L->size){
		printf("%d  ",L->list[i]);
		i++;
	}
	
}
main()
{
  elem i;
  seqlist *L;
  L=(seqlist *)malloc(sizeof(seqlist));
	initlist(10,L);
  for(i=0;i<=8;i++){
  	insert(L,i);
  }
  printlist(L);
  freelist(L);
}
