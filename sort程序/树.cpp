#include<malloc.h>
#include<string.h>
#include<stdlib.h>
#include <stdio.h>
#include <math.h>
typedef int elemtype;
typedef struct bi{
	elemtype date;
	struct bi *left,*right;
}binode,*bitree;
void visit(bitree T);
bitree creat(bitree T);
bitree creat(bitree T){
	elemtype e;
	scanf("%d",&e);
	if(e==-1)
	{
		T=NULL;
		return T;
	}
	else{
		T=(binode *)malloc(sizeof(binode));
		T->date=e;
		creat(T->left);
		creat(T->right);
	}
	return T;
}
void visit(bitree T){
	printf("%d\n",T->date);
}
void TreeDestroy(bitree T);
void TreeDestroy(bitree T){
	free(T->left);
	free(T->right);
	free(T);
}
int MAX(int x,int y);
int  TreeDepth(bitree T);
int  TreeDepth(bitree T){
	int num=0;
	if(T!=NULL)
	{
		num=MAX(TreeDepth(T->left),TreeDepth(T->right))+1;
	}
	return num;
}

int MAX(int x,int y){
	if(x>y)
	{
		return x;
	}
	return y;
}
int NodeNumber(int *num,bitree T);
int NodeNumber(int *num,bitree T){
	if(T!=NULL)
	{
		*num++;
		*num+=NodeNumber(num,T->left);
		*num+=NodeNumber(num,T->left);
	}
	return *num;
}
int LeafNodeNumber(int *num,bitree T);
int LeafNodeNumber(int *num,bitree T){
	if(T->left==NULL&&T->right==NULL)
	{
		*num++;
	}
	else{
		LeafNodeNumber(num,T->left);
		LeafNodeNumber(num,T->right);
	}
	return *num;
}
void MidTraverse(bitree T);//中序遍历
void MidTraverse(bitree T){
	if(T){
		MidTraverse(T->left);
		visit(T);
		MidTraverse(T->right);
	}
}
void order(bitree T);//先序 
void order(bitree T){
	if(T){
		visit(T);
		order(T->left);
			order(T->right);
	}
}
void PostTraverse(bitree T);//后序遍历
void PostTraverse(bitree T){
		if(T){
	PostTraverse(T->left);
		PostTraverse(T->right);	
			visit(T);
	}
}
void LayerTraverse(bitree T);//层遍历
void LayerTraverse(bitree T){
	bitree ss[100];
	int in=0,out=0;
	ss[in++]=T;
	while(in>out)
	{
		if(ss[out]!=NULL)
		{
			visit(ss[out]);
			ss[in++]=ss[out]->left;
			ss[in++]=ss[out]->right;
		}
		out++;
	}
}
void PostMid2Prior(bitree T);//后序和中序遍历推导先序遍历
void PostMid2Prior(bitree T)
{
	creat(T);
	PostTraverse(T);
}
void PriorMid2Post(bitree T);//先序和中序遍历推导后序遍历
void PriorMid2Post(bitree T){
	creat(T);
	MidTraverse(T);
}
main()
{
  
}
