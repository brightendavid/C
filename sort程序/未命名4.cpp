#include<malloc.h>
#include<string.h>
#include<stdlib.h>
#include <stdio.h>
#include <math.h>
#define MAX 200
typedef int Vertextype;
typedef struct Arcnode{
	int adjvex;//�����е�λ���±� 
	struct Arcnode *nextarc;//��һ���ĵ�ַ 
}Arcnode;
typedef struct Vnode{
	Vertextype data;
	Arcnode *firstarc;
}Vnode,*AdjList;
typedef struct{
	AdjList vertices[MAX];
	int vexnum,arcnum;//������ ���� 
	int kind;
}ALGraph; 
main(){
	ALGraph *g;
		int a,b;	
	printf("���붥�����ͱ���\n");
	scanf("%d %d",&a,&b);
	getchar();
	
/*	g->vexnum=a;
	g->arcnum=b;*/
	printf("%d%d",a,b) ;
}

