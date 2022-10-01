#include<malloc.h>
#include<string.h>
#include<stdlib.h>
#include <stdio.h>
#include <math.h>
#define MAX 200
typedef int Vertextype;
typedef struct Arcnode{
	int adjvex;//数组中的位置下标 
	struct Arcnode *nextarc;//下一个的地址 
}Arcnode;
typedef struct Vnode{
	Vertextype data;
	Arcnode *firstarc;
}Vnode,*AdjList;
typedef struct{
	AdjList vertices[MAX];
	int vexnum,arcnum;//顶点数 边数 
	int kind;
}ALGraph; 
main(){
	ALGraph *g;
		int a,b;	
	printf("输入顶点数和边数\n");
	scanf("%d %d",&a,&b);
	getchar();
	
/*	g->vexnum=a;
	g->arcnum=b;*/
	printf("%d%d",a,b) ;
}

