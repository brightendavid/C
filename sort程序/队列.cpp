#include<malloc.h>
#include<string.h>
#include<stdlib.h>
#include <stdio.h>
#include <math.h>
#define max 20
typedef struct{
	int data[max];
	int front;
	int rear;
}queue;
void init(queue *Q){//初始化 0-19
	Q->front=0;//头元素 
	Q->rear=0;//相表示空队列 
}
int full(queue *Q){
	if(Q->front==(Q->rear+1)%max){//full =1
		return 1;
	}
	else{
		return 0;
	}
}
void in(queue *Q,int x){
	if(full(Q)){
		printf("full%d",x);
		return;
	}
	Q->data[(Q->rear++)%max]=x;
}
int empty(queue *Q){
	if(Q->front==Q->rear){
		return 1;
	}
	return 0;
}
void  out(queue *Q,int *e){
	if(empty(Q)){
		printf("empty");
		return;
	}
	else{
		*e= Q->data[Q->front];
		Q->front=(Q->front+1)%max;
	} 
}
void destory(queue *Q){
	while(!empty(Q)){
		printf("%d ->",Q->data[Q->front]);
		Q->front++;
		if(Q->front>max-1){
			Q->front=(Q->front)%max;
		}
	}
}
main()
{
  queue *s=(queue *)malloc(sizeof(queue));
  init(s);
  for(int i=0;i<=max-2;i++){
  	in(s,i);
  }
  destory(s);
}
