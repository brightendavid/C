#include<malloc.h>
#include<string.h>
#include<stdlib.h>
#include <stdio.h>
#include <math.h>
#define max 3
#define size 10
typedef struct listnode  *listpoint;
typedef struct listnode {
	int key[max];
	listpoint link;
}; 
void print(listpoint L);
listpoint radix_sort(listpoint ptr){
	listpoint front[size],rear[size];
	int i,j,digit;
	digit=0;
	for(i=max-1;i>=0;i--){//从优先级低处出发 
		for(j=0;j<size;j++){
			front[j]=rear[j]=NULL; 
		}
		while(ptr){
			digit=ptr->key[i];
			if(!front[digit]){
				front[digit]=ptr;
			}
			else{
				rear[digit]->link=ptr;
			}
			rear[digit]=ptr;
			ptr=ptr->link;
		}
		ptr=NULL;
		for(j=size-1;j>=0;j--){//每一个尾链接上一个的头 
			if(front[j]){
				rear[j]->link=ptr;
				ptr=front[j];
			}
		}
	}
	 
	return ptr;
}
listpoint insert(){
	int i,j;
	listpoint p,q,L;
	L=p=q=NULL;
	p=(listnode *)malloc(sizeof(listnode));
	if(!p){
		printf("错误");
		exit(1);
	}
	j=0;
	L=p;
		i=4*j*(10-j);
		p->key[0]=i%10;
		p->key[1]=i/10%10;
		p->key[2]=i/100;
		p->link=NULL; 
		q=p;
	for(j=1;j<=9;j++){
		p=(listnode *)malloc(sizeof(listnode));
		p->link=NULL;
		i=4*j*(10-j);
		p->key[0]=i%10;
		p->key[1]=i/10%10;
		p->key[2]=i/100;
		q->link=p;
		q=p;
	}
	return L;
}
void print(listpoint L){
	listpoint p,q;
	p=L;
	while(p!=NULL){
		printf("%d%d%d  ",p->key[0],p->key[1],p->key[2]);
		p=p->link; 
	}
 	printf("\n");
} 
main()
{
	listpoint L;
  	L= insert();
  	 printf("111\n");
  	 print(L);
  	 printf("111\n");
  	L=radix_sort(L);
 	 print(L);
}
