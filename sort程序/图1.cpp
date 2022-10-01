/**
* ��ͷ���ӵı��н�㶨��
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
    int vexIndex;//�ڽӵ��������е�λ���±�
    struct tableBody *nextarc;//ָ����һ���ڽӵ��ָ��
} tableBody;
/**
 * ��ͷ��㶨��
 * */
typedef struct tableHead {
    char data;//�����������
    struct tableBody *firstarc;//ָ���ڽӵ��ָ��
} tableHead, *tableHeadArr;//�洢������ͷ��������
/**ͼ-�ڽӱ���*/
typedef struct {
    tableHead vertices[MAX];//ͼ�ж��㼰���ڽӵ�����
    int vexnum, arcnum;//��¼ͼ�ж������ͱ߻���
    int arc[MAX][MAX];
} LJBGraph;
struct{
	Vertextype adjvex;//char adjvex ��ǰ�ļ���������
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
	int k=localIndex(g,u);//������ 
	int i,j;
	for(j=0;j<g->vexnum;j++){
		if(j!=k){
			closedge[j]={g->vertices[u].data,g->arc[k][j]}; 
		}
		closedge[k].lowcost=0;//��ʾk���Ѿ�����U 
	}
	for(i=1;i<g->vexnum;i++){
		k=min(g);//min���� ��   V-U  �ҵ���С 
		 printf("%d->%d�ı�",closedge[k].adjvex,k); 
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

int localIndex(LJBGraph *g,char data)//���ض���������±�ֵ 
{
    for(int i=0;i<g->vexnum;i++){
        if(g->vertices[i].data == data){
            return i;
        }
    }
    printf("û������ַ�");
    return -1;
}
void printfL(LJBGraph *g) {
    //���ͼ����Ϣ
    printf("��Ϊ :\n");
    tableBody *p;
    printf("\n");
    //�ڽӱ���Ҫ����⡣
    int i;
    for (i = 0; i < g->vexnum; i++) {
        printf("%d%c\t",(i),g->vertices[i].data);//��ͷ���
        p = g->vertices[i].firstarc;
        while (p) {
            printf("%d\t", p->vexIndex);//�����
            p = p->nextarc;//���������
        }
        printf("\n");
    }

}
void createGraph(LJBGraph *g) {
    //�ܶ���������ܱ���
    int i, j, k;
    tableBody *tb;
    printf("���붥�����ͱ���");
   g=(LJBGraph *)malloc(sizeof(LJBGraph));
    scanf("%d,%d",&g->vexnum, &g->arcnum);//��ȡ�������ͱ���

    for (i = 0; i < g->vexnum; i++) {
        char c; 
        printf("����%d ������ֵ\n", (i + 1));
        scanf("%d", &c);
        g->vertices[i].data = c;            //��ȡ����ֵ��
        g->vertices[i].firstarc = NULL;    //���߱���Ϊ��
    }
    for (k = 0; k < g->arcnum; k++) {
        printf("����a,b ��ͼ����a-->b:");
        getchar();
        char a,b;
        scanf("%c %c", &a, &b);               //����i,j ��ͼ����i-->j
        tb = (tableBody *) malloc(sizeof(tableBody));
        i=localIndex(g,a); //a�������ڶ��������е��±�ֵ��
        j=localIndex(g,b); //b�������������е��±�ֵ��
        int x;
        printf("����a->b��Ȩֵx:");
        scanf("%d",&x);
    	g->arc[i][j]=x;
        tb->vexIndex = j;
        tb->nextarc = g->vertices[i].firstarc;   //ͷ�巨�����߱�
        g->vertices[i].firstarc = tb;//���½��Ľ�������ڶ������
        /*���Ϊ����ͼ����������´���
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


