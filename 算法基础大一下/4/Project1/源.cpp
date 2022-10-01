#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<opencv.hpp>
#include <iostream>
#define _CRT_SECURE_NO_WARNINGS
using namespace cv;
#define max 20
typedef struct ARCNODE{//边集
	int adj;//第一条边
	struct ARCNODE* nextarc;//下一条边
}ARC,*ARCPTR;
typedef struct vex {///点集
	char vexdata;
	int id;
	ARCPTR firstadj;
}vexnode;

typedef struct graph {
	vex ver[max];
	int vexnum, arcnum;//点数 边数
}graph;
int visit[max];
void creat_graph(graph* G) {
	ARC* p;
	int i, j, k;
	int v1, v2;
	printf("\ninput vexnum");
	scanf("%d", &G->vexnum);
	getchar();
	for (i = 1;i <= G->vexnum;i++) {
		printf("input vexdata\n");
		scanf("%c", &G->ver[i].vexdata);
		getchar();
		G->ver[i].id = 0;
		G->ver[i].firstadj = NULL;

	}
	printf("\ninput arcnum");
	scanf("%d", &G->arcnum);
	for (i = 1;i <= G->arcnum;i++) {
		printf("\ninput arc");
		scanf("%d %d", &v1, &v2);

		p = (ARC*)malloc(sizeof(ARC));
		p->adj = v2;
		p->nextarc = G->ver[v1].firstadj;
		G->ver[v1].firstadj = p;
		G->ver[v2].id++;
	}
}
void sort(graph * G) {
	int s[100];
	int top = 0;
	int i,  j;
	ARCPTR p;
	for (i = 1;i <= G->vexnum;i++) {//top=0时为空
		if (G->ver[i].id == 0) {
			top++;s[top] = i;
		}
	}
	while (top != 0) {
		i = s[top--];
		printf("%3c", G->ver[i].vexdata);
		for (p = G->ver[i].firstadj;p != NULL;p = p->nextarc) {
			j = p->adj;
			G->ver[j].id--;
			if (G->ver[j].id== 0) {
				top++;
				s[top] = j;
			}
		}
	}

}
int first(graph* g,int i) {
	int x;
	ARC* p;
	p = g->ver[i].firstadj;
	if (p == NULL) {
		return -1;
	}
	else{
		return p->adj;
	}
}
int next(graph* g, int i,int x) {
	ARC* p;
	p = g->ver[i].firstadj;
	while (p->adj!= x) {
		p = p->nextarc;
	}
	p = p->nextarc;
	if (p == NULL) {
		return -1;
	}
	else {
		return p->adj;
	}
}
void dfs(graph* g,int i) {
	ARC* p;
	int x;
	if (visit[i] == 0) {
		x = first(g, i);
		visit[i] = 1;
		printf("%d %c\n", i,g->ver[i].vexdata);	
		while (x!=-1) {
			if(!visit[x])
				dfs(g,x);
			x = next(g, i,x);
		}
	}


}
void beforedfs(graph* g) {
	int i, j;
	for (i = 1;i <= g->vexnum;i++) {
		if (visit[i] ==0)
		{
			dfs(g,i);
		}

	}
}

int main() {
	graph* G=(graph*)malloc(sizeof(graph));
	int j;
	creat_graph(G);
	printf("\n");
	int i = 0;
	for (i = 1;i <= G->vexnum;i++) {
		visit[i] = 0;
	}
	sort(G);
	printf("\n\n");
	beforedfs(G);
}