#include<malloc.h>
#include<string.h>
#include<stdlib.h>
#include <stdio.h>
#include <math.h>
#define max 20
typedef struct{
	int data[max];
	int top;//top�ǿյ� ����һ��push��λ�� 
}struck;

void  clear(struck *s){
	s->top=-1;
}
int full(struck *s){
	if(s->top>=max){
		return 1;
	}
	return 0;//δ�� 
}
void push(struck *s,int x){//��ջ 
	if(full(s)){
		printf("��������" );
		return;
	}
	s->data[s->top]=x;
	s->top++;
}
int  pop(struck  *s){//��ջ 
	s->top--;
	return s->data[s->top];
}
int gettop(struck *s){
	return s->data[s->top-1];
}
void  travel(struck *s){
	while(s->top!=-1){
		printf("%d  ",pop(s));
	}
}
main()
{
	struck *s=(struck *)malloc(sizeof(struck));
  int i,j;
  
  s->top=-1;
  for(i=0;i<=9;i++){
  	push(s,i);
  }
  
  travel(s);
}
