#include<stdio.h>
#include<malloc.h>
#include<string.h>

//����ջ 
typedef struct{
	char data[100];
	int top;
	int bottom;
}stack;

//����ջ
stack *StackCreate(){
	stack *p=(stack*)malloc(sizeof(stack));//�����¿ռ� 
	if(p==NULL)//����ʧ�� 
	return 0;
	p->bottom=p->top=0;//����ɹ� 
	return p;
}

//��ջ
void StackInput(stack *p,char str){
	p->data[p->top]=str;//����ջ�� 
	p->top++;//ջ��ָ���1 
} 

//��ջ 
char StackOutput(stack *p,char str){
	if(p->top!=p->bottom){//ջ�ǿ� 
		str=p->data[p->top-1];//ջ��������� 
		p->top--;//ջ����1 
		return str;
	}
} 

//��� 
void StackPrint(stack *p){
	while(p->top!=p->bottom){
		printf("%c",p->data[p->top-1]);
		p->top--;
	}
}

//������ 
int main()
{
	int i;
	stack *p;//����ջ�� 
	char a[10]="asdfgh";
	p=StackCreate();//����ջ 	 
	for(i=0;i<strlen(a);i++)//���ַ���a���ַ���ջ 
	StackInput(p,a[i]);
	printf("���ջ�������ַ���\n"); 
	StackPrint(p);
}
