#include<malloc.h>
#include<string.h>
#include<stdlib.h>
#include <stdio.h>
#include <math.h>
#define max 20
typedef struct{
	int data[max];
	int top;//top是空的 是下一个push的位置 
}struck;

void  clear(struck *s){
	s->top=-1;
}
int full(struck *s){
	if(s->top>=max){
		return 1;
	}
	return 0;//未满 
}
void push(struck *s,int x){//入栈 
	if(full(s)){
		printf("数组已满" );
		return;
	}
	s->data[s->top]=x;
	s->top++;
}
int  pop(struck  *s){//出栈 
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
