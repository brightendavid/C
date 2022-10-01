#include<stdio.h>
#include<malloc.h>
#include<string.h>
int top;
int youx(char x,char y)//x大就是1 x是现在   y是栈顶元素 
{
	if(x=='(')
	{
		return 0;
	}
	if(y=='*'||y=='/')
	{
		return 0;
	}
	if((x=='*'||x=='/')&&(y=='+'||y=='-'))
	{
		return 1;
	}
	if(y=='\0')
	  return 1;
	return 0; 
}
struct str
{
	char  x;
	struct  str *next;
};
struct str *creat()
{
	int i,j;
	struct str *head;
	head=NULL;
	head=(struct str *)malloc(sizeof(struct str));
	head->next=NULL;
	head->x='\0';
	return head;
}
struct str *add(char x,struct str *head)
{
	struct str *p,*q;
	p=(struct str* )malloc(sizeof(struct str));
	p->next=head;
	p->x=x;
	head=p; 
	return head;
}
struct str *pop(struct str *head)
{
	struct str *p,*q;
	p=head->next;
	free(head);
	head=p;
	return head;
}
main()
{
	struct str *a = creat();
	int i,j;
	char ss[100];
	scanf("%s",ss);
	for(i=0;i<=strlen(ss)-1;i++)
	{
		if(ss[i]>='0'&&ss[i]<='9')
		{
			while(ss[i]>='0'&&ss[i]<='9')
			{
				printf("%c",ss[i]);
				i++;
			} 
			printf(" ");
			i--;
		}	
		 else
		 {
		 	if(youx(ss[i],a->x))//现在的优先级大于栈 
		 	{
		 		a=add(ss[i],a);
			 }
			 else
			 {
			 	while(youx(ss[i],a->x)==0)
			 	{
			 		printf("%c ",a->x);
			 		a=pop(a);
				}
					a=add(ss[i],a);
			 }
		 }
	}
	while(a!=NULL)
	{
		printf("%c ",a->x);
		a=pop(a);
	}
 } 
