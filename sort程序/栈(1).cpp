#include<malloc.h>
#include<string.h>
#include<stdlib.h>
#include <stdio.h>
#include <math.h>
typedef  int selemtype;
#define INIT_SIZE 100
#define CREMENT 10
typedef struct {
	selemtype *base;
	selemtype *top;
	int stracksize;
}SqStack; 
void Initstack(SqStack S);
void GetTop(SqStack S,selemtype *e);
void Push(SqStack S,selemtype e);
void POP(SqStack S,selemtype *e);
void Initstack(SqStack S){
	S.base=(selemtype*)malloc(INIT_SIZE*sizeof(selemtype));
	S.top=S.base;
	S.stracksize=INIT_SIZE;
}
void GetTop(SqStack S,selemtype *e)
{
	if(S.base==S.top){
		return;
	}
	*e=*(S.top-1);
}
void Push(SqStack S,selemtype e){
	if(S.top-S.base>=S.stracksize){
		S.base=(selemtype *)realloc(S.base,(S.stracksize+CREMENT)*sizeof(selemtype));
	}
	*S.top++=e;
}
void POP(SqStack S,selemtype *e){
	if(S.top=S.base)
	{
		return;
	}
	*e=*(--S.top);
}
main()
{
  
}
