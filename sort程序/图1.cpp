/**
* 表头连接的表中结点定义
* */
#include<malloc.h>
#include<string.h>
#include<stdlib.h>
#include <stdio.h>
#include <math.h>
#define MAX 20
#define M 10000
int visited[MAX];
typedef char Vertextype;
typedef struct tableBody {
    int vexIndex;//邻接点在数组中的位置下标
    struct tableBody *nextarc;//指向下一个邻接点的指针
} tableBody;
/**
 * 表头结点定义
 * */
typedef struct tableHead {
    char data;//顶点的数据域
    struct tableBody *firstarc;//指向邻接点的指针
} tableHead, *tableHeadArr;//存储各链表头结点的数组
/**图-邻接表定义*/
typedef struct {
    tableHead vertices[MAX];//图中顶点及各邻接点数组
    int vexnum, arcnum;//记录图中顶点数和边或弧数
    int arc[MAX][MAX];
} LJBGraph;
struct{
	Vertextype adjvex;//char adjvex 当前的加入点的数据
	int lowcost;
}closedge[MAX];
void Prim(LJBGraph *g,int u);
void DFS(LJBGraph *g,int v);
int localIndex(LJBGraph *g,char data);
void DFS1(LJBGraph *g,int v);
void visit( LJBGraph *g,int i);
void DFS1(LJBGraph *g,int v){
	for(v=0;v<g->vexnum;v++){
		if(!visited[v]){
			DFS(g,v);
		}
	}
}
int min( LJBGraph *g);
void DFS(LJBGraph *g,int v){
	visited[v]=1;
	visit(g,v);
	   tableBody *w;
	   for(w=g->vertices[v].firstarc;w;w=w->nextarc){
	   	if(!visited[w->vexIndex])
	    	DFS(g,w->vexIndex);
	   }
}
void Prim(LJBGraph *g,char u){
	int k=localIndex(g,u);//输出编号 
	int i,j;
	for(j=0;j<g->vexnum;j++){
		if(j!=k){
			closedge[j]={g->vertices[u].data,g->arc[k][j]}; 
		}
		closedge[k].lowcost=0;//表示k点已经进入U 
	}
	for(i=1;i<g->vexnum;i++){
		k=min(g);//min函数 在   V-U  找到最小 
		 printf("%d->%d的边",closedge[k].adjvex,k); 
		 closedge[k].lowcost=0;
		 for(j=0;j<g->vexnum;j++){
		 	if(g->arc[k][j]<closedge[j].lowcost){
		 		closedge[j]={g->vertices[k].data,g->arc[k][j]};
			 }
		 }
	}
}

int min( LJBGraph *g){
	int i,j;
	int m=M;
	int t;
	for(i=0;i<g->vexnum;i++){
		if(closedge[i].lowcost==0){
			
			for(j=0;j<g->vexnum;j++){
				if(closedge[j].lowcost!=0){
					if(g->arc[i][j]<=m){
						m=g->arc[i][j];
						t=j;
					}
				}
			}
		}
	}
	return t;
}
void visit(LJBGraph *g,int i){
	printf("%d",g->vertices[i].data);
}

int localIndex(LJBGraph *g,char data)//返回顶点数组的下标值 
{
    for(int i=0;i<g->vexnum;i++){
        if(g->vertices[i].data == data){
            return i;
        }
    }
    printf("没有这个字符");
    return -1;
}
void printfL(LJBGraph *g) {
    //输出图的信息
    printf("表为 :\n");
    tableBody *p;
    printf("\n");
    //邻接表不需要表标题。
    int i;
    for (i = 0; i < g->vexnum; i++) {
        printf("%d%c\t",(i),g->vertices[i].data);//表头结点
        p = g->vertices[i].firstarc;
        while (p) {
            printf("%d\t", p->vexIndex);//外表结点
            p = p->nextarc;//外表结点下移
        }
        printf("\n");
    }

}
void createGraph(LJBGraph *g) {
    //总顶点个数，总边数
    int i, j, k;
    tableBody *tb;
    printf("输入顶点数和边数");
   g=(LJBGraph *)malloc(sizeof(LJBGraph));
    scanf("%d,%d",&g->vexnum, &g->arcnum);//获取顶点数和边数

    for (i = 0; i < g->vexnum; i++) {
        char c; 
        printf("输入%d 个顶点值\n", (i + 1));
        scanf("%d", &c);
        g->vertices[i].data = c;            //获取顶点值，
        g->vertices[i].firstarc = NULL;    //将边表置为空
    }
    for (k = 0; k < g->arcnum; k++) {
        printf("输入a,b 在图中有a-->b:");
        getchar();
        char a,b;
        scanf("%c %c", &a, &b);               //输入i,j 在图中有i-->j
        tb = (tableBody *) malloc(sizeof(tableBody));
        i=localIndex(g,a); //a顶点所在顶点数组中的下标值。
        j=localIndex(g,b); //b顶点所在数组中的下标值。
        int x;
        printf("输入a->b的权值x:");
        scanf("%d",&x);
    	g->arc[i][j]=x;
        tb->vexIndex = j;
        tb->nextarc = g->vertices[i].firstarc;   //头插法建立边表
        g->vertices[i].firstarc = tb;//把新建的结点链接在顶点后面
        /*如果为无向图，则加入以下代码
                e=(EdgeNode*)malloc(sizeof(EdgeNode));
                e->adjvex = i;
                e->next = g->adjList[j].firstedge;
                g->adjList[j].firstedge= e;*/
    }
    printfL(g);
   
}
int main(void) {
	int i,j;
	  LJBGraph *g; 
	  createGraph(g);
	for(i=0;i<=MAX-1;i++){
		visited[i]=0;
		for(j=0;j<=MAX-1;j++){
			g->arc[i][j]=M;
		}
	}
  
   
    return 0;
}


