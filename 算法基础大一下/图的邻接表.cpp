#include<malloc.h>
#include<string.h>
#include<stdlib.h>
#include <stdio.h>
#include <math.h>
typedef char datatype;
#define max 100
typedef struct{
	int row;
	int col;
}rowcol;
typedef struct node{//边 
	int dest;//终点 
	int cost;
	struct node *next;
}edge;
typedef struct{//起点 
	datatype data;
	int score;
	edge *adj;//邻接边 
}height;
typedef struct{
	height a[max];
	int vert;
	int edge;
}graph;
void init(graph *G){
	int i;
	G->edge=0;
	G->vert=0;
	for(i=0;i<max;i++){
		G->a[i].score=i;
		G->a[i].adj=NULL;
	}
}
void destory(graph *G){
	int i;
	edge *p,*q;
	for(i=0;i<G->vert;i++){
		p=G->a[i].adj;
		while(p!=NULL){
			q=p->next;
			free(p);
			p=q;
		}
	}
}
void insertvert(graph *G,int i,datatype vertex){
	if(i>=0&&i<max){
		G->a[i].data=vertex;
		G->vert++;
	}
	else{ 
		printf("顶点越界");
	}
}
void insertedge(graph *G,int v1,int v2,int cost){
	edge *p;
	if(v1<0||v1>=G->vert||v2<0||v2>=G->vert){
		printf("参数错误edge");
		exit(0); 
	}
	p=(edge*)malloc(sizeof(edge));
	p->dest=v2;
	p->next=G->a[v1].adj;
	G->a[v1].adj=p;
	G->a[v1].adj->cost=cost;
	G->edge++;
}
void deletedge(graph *G,int v1,int v2){
	edge  *curr,*pre;
	if(v1<0||v1>=G->vert||v2<0||v2>=G->vert){
		printf("参数错误edge");
		exit(0);
	}
	else{
		pre=NULL;
		curr=G->a[v1].adj;
		
	}
	while(curr!=NULL&&curr->dest!=v2){
		pre=curr;
		curr=curr->next;
	}
	if(curr!=NULL&&curr->dest==v2&&pre==NULL){
		G->a[v1].adj=curr->next;
		free(curr);
		G->edge--;
	}
	else if(curr!=NULL&&curr->dest==v2&&pre!=NULL){
		pre->next=curr->next;
		free(curr);
			G->edge--;
	}
	else{
		printf("边不存在"); 
	}
}
int firstedge(graph *G,int v){
	edge *p;
	if(v<0||v>G->vert){
		printf("参数错误edge");exit(0);
	}
	else{
		p=G->a[v].adj;
		if(p==NULL){
			return -1;
		}
		else{
			return p->dest;
		}
	}
}
int nextvex(graph *G,int v1,int v2){//移动到v1-v2的v1下一条邻接边 
	edge *p;
	if(v1<0||v1>G->vert||v2<0||v2>G->vert){
		printf("参数错误");
		exit(0);
	}
	p=G->a[v1].adj;
	while(p!=NULL){
		if(p->dest!=v2){
			p=p->next;
			continue; 
		}
		else{
			break;
		}
	}
	p=p->next;
	if(p!=NULL){
		return p->dest; 
	}
	else{
		return -1;
	}
}
void creatgraph(graph *G,datatype v[],int n, rowcol d[],int e,int cost[]){
	int i,k;
	init(G);
	for(i=0;i<n;i++){
		insertvert(G,i,v[i]);
	}
	for(k=0;k<e;k++){
		insertedge(G,d[k].row,d[k].col,cost[k]);
	}
}

int visited[max];
void DFS(graph *G,int v,int visited[]){
	int w;
	printf("%c   ",G->a[v].data);
	visited[v]=1;
	w=firstedge(G,v);
	while(w!=-1){
		if(!visited[w]){
			DFS(G,w,visited);
		}
		w=nextvex(G,v,w);
	}
}
void DFST(graph *G){
	int i;
	for(i=0;i<G->vert;i++){
		visited[i]=0;
	}
	for(i=0;i<G->vert;i++){
		if(!visited[i]){
			DFS(G,i,visited);
		}
	}
}
int dui[1000];
int fir=0;int last=-1;
void BFS(graph *G,int v,int visited[]){//广搜 
	int w;
	visited[v]=1;
	dui[++last]=v;
	while(fir<=last){
		printf("%c   ",G->a[dui[fir]].data);
		w=firstedge(G,dui[fir]);
		while(w!=-1){
			if(!visited[w]){
				if(fir<1000)
				dui[++last]=w;
				visited[w]=1;
			//	BFS(G,w,visited)
			}
		w=nextvex(G,dui[fir],w);
		}
		fir++;
	}
}
void BFST(graph *G){
		int i;
	for(i=0;i<G->vert;i++){
		visited[i]=0;
	}
	for(i=0;i<G->vert;i++){
		if(!visited[i]){
			BFS(G,i,visited);
		}
	}
}
main()
{
	graph *g=(graph*)malloc(sizeof(graph));
	char a[]={'A','B','C','D','E','F','G','H','I','J'};
	rowcol rc[]={{0,1},{1,3},{3,2},{2,1},{0,4},{0,5},{4,5},{5,3},{6,9},{4,8},{7,2},{8,6},{1,7},{7,8},{8,9},{6,7}};
	int num=0;
	num=(sizeof(rc))/sizeof(rowcol);
	int cost[num];
	int i,j;
	for(int i=0;i<=num-1;i++){
		cost[i]=rand()%20+1;
	}
	int n,e;
	n=sizeof(a)/sizeof(char);
	e=sizeof(cost)/sizeof(rowcol);
	edge *p;
  	creatgraph(g,a,n,rc,e,cost);
  	printf("%d  %d\n" ,g->edge,g->vert);
  	DFST(g);
  	printf("\n");
  	for(i=0;i<g->vert;i++){
  		printf("%c  ",g->a[i].data);
  		
		 p=g->a[i].adj;
		 while(p!=NULL){
		 	printf("edge:%d   cost:%d  ||",p->dest,p->cost);
		 	p=p->next;
		 }
		 printf("\n");
	}
	printf("\n");
	BFST(g);
	printf("\n");
	  	for(i=0;i<g->vert;i++){
  		printf("%c  ",g->a[i].data);
		 p=g->a[i].adj;
		 while(p!=NULL){
		 	printf("%d ",p->dest);
		 	p=p->next;
		 }
		 printf("\n");
		}
	printf("\n\n");
	deletedge(g,1,3);
	printf("%d  %d\n",g->edge,g->vert);
	for(i=0;i<g->vert;i++){
		printf("%c  ",g->a[i].data  );
		p=g->a[i].adj;
		while(p!=NULL){
			printf("%d  ",p->dest);
			p=p->next;
		}
		printf("\n");
	}

	destory(g);
}
