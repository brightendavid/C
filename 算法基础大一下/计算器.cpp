#include<malloc.h>
#include<string.h>
#include<stdlib.h>
#include <stdio.h>
#include <math.h>
#define MAX_STACK_SIZE 100
#define MAX_EXPR_SIZE 100
void postfix(char *expr, char *outstr);//中缀转后缀 
int eval(char *outstr);
typedef enum{lparen,rparen,plus,minus,times,divide,mod,eos,operand//operand 操作数 
}precedence;//计算后缀 

int stack_int[MAX_STACK_SIZE];//中缀转后缀 
precedence stack_prence[MAX_STACK_SIZE];
char expr[MAX_EXPR_SIZE];//读入记录 
int isp[]={1,19,12,12,13,13,13,0};
int icp[]={20,19,12,12,13,13,13,0};
#define INT_ITEM 1//stack_int

#define PRECE_ITEM 2 //stack_prence

void push(int *top,int a,precedence b,int flag){
	if(*top>=MAX_STACK_SIZE-1){
		printf("栈溢出\n");
		exit(0);
	}
	if(flag==INT_ITEM)
		stack_int[++*top]=a; 
	else if(flag==PRECE_ITEM ){
		stack_prece[++*top]=b;
	}
} 
void pop(int *top,int *a,precedence *b,int flag){
	if(*top<0){
		printf("栈溢出");
		exit(0); 
	}
	if(flag==INT_ITEM){//stack_int出栈 
		*a=stack_int[(*top)--];
	}
	else if(flag==PRECE_ITEM){//stack_prence出栈 
		*b=stack_prece[(*top)--];
	}
}
precedence get_token(char *symbol,int *n,char *expr){
	*symbol=expr[*(*n)++];
	switch(*symbol){
		case'(':return lparen;
		case')':return rparen;
		case'+':return plus;
		case'-':return minus;
		case'/':return divids;
		case'*':return times;
		case'%':return mod;
		case'\0':return eos;
		defaullt:return operand;
	}
}
char precedencetochar(precedence token){
	switch(token){
		case plus: return '+';
		case minus :return '-';
		case divide :return '/';
		case times:return '*';
		case mod :return '%';
		case eos :return '\0';
		default :return operand;
	}
}
void postfix(char *expr ,char *outstr){
	char symbol;
	precedence token ,precevalue;
	int  n=0;
	int intvalue;
	int i=0;
	int top=-1;
	stack_prece[0]=eos;
	for(token=get_token(&symbol,&n,expr);token!=eos;token=get_token(&symbol,&n,expr)){
		if(token ==operand)
			outstr[i++]=symbol;
		else if(token ==rparen){
			while(stack_prece[top]!=lparen){
				pop(&top,&intvalue,&precevalue,PRECE_ITEM);
				outstr[i++]=precedencetochar(precevalue);
			}			
			pop(&top,&intvalue,&precevalue,PRECE_ITEM);
		}
		else{
			if(top>=0){
				while(isp[stack_prece[top]]>=icp[token]){
					pop(&top,&intvalue,&precevalue,PRECE_ITEM);
					outstr[i++]=precedencetochar(precevalue);
				}
				push(&top,0,token,PRECE_ITEM);
			}
		}
	}
	while(top>=0){
			pop(&top,&intvalue,&precevalue,PRECE_ITEM);
			outstr[i++]=precedencetochar(precevalue);
	}
	outstr[i]='\0';
}

int eval(char *outstr){
	precedence token,orecevalue;
	char symbol;
	int op1,op2,result;
	int n;
	int top=-1;
	token=get_token (&symbol,&n,outstr);
	precedence=token;
	while(token!=eos){
		if(token ==operand){
			push(&top,symbol-'0',precevalue,INT_ITEM);
		}
		else{
			pop(&top,&top2,&precevalue,INT_ITEM);
			pop(&top,&top1,&precevalue,INT_ITEM);
			switch(token){
				case plus:push(&top,op1+op2,precevalue,,INT_ITEM);break;
				case minus:push(&top,op1-op2,precevalue,,INT_ITEM);break;
				case times:push(&top,op1*op2,precevalue,,INT_ITEM);break;
				case divide:push(&top,op1/op2,precevalue,,INT_ITEM);break;
				case mod:push(&top,op1%op2,precevalue,,INT_ITEM);break;
			}
		}
		token=get_token(&symbol,&n,outstr);
	}
	pop(&top,&result,&precevalue,INT_ITEM);
	return result;
}
main()
{
  int result;
  char expr[100],outstr[100];
  gets(expr);
  postfix(expr,outstr);
  result=eval(outstr);
  printf("the result = %d\n",result);
}
