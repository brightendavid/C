#include <stdio.h>
#include <math.h>
#include <stdlib.h>					//提供malloc、realloc、free、exit原型
#include <string.h>						//提供strcpy原型 
#define	TRUE		1			//真 
#define	FALSE		0			//假
#define YES			1			//是
#define NO          0			//否 
#define	OK			1			//通过
#define	ERROR		0			//错误
#define SUCCESS		1			//成功
#define UNSUCCESS	0			//失败 
#define	INFEASIBLE	-1			//不可行
int num=0; 
#define MAX_TREE_SIZE 100		//树的最大结点数
typedef int Status;

/* 哈夫曼树和哈夫曼编码表类型定义 */
typedef struct
{
	unsigned int weight;			//权值 
	unsigned int parent;						
	unsigned int lchild;
	unsigned int rchild;
}HTNode;
typedef HTNode* HuffmanTree;		//动态分配数组存储哈夫曼树 
typedef char* HCNode;
typedef HCNode* HuffmanCode;		//动态分配数组存储哈夫曼编码表 

//1.构造空树HT(初始化树)
void InitTree(HuffmanTree *HT)
{
	*HT = NULL;
}

//2.在哈夫曼树结点[1...end]中依次选出权值最小且未编入树的两个结点的序号order_1、order_2
Status Select(HuffmanTree HT, int end, int *order_1, int *order_2)
{
	int i, count;
	int m, n, tmp;
	
	if(end<2)	return ERROR;
	
	for(i = 1, count = 1; i <= end; i++)	//遍历找出前两个未编入树的结点 
	{
		if(HT[i].parent==0)
		{
			if(count==1)	m = i;
			if(count==2)	n = i;
			count++;
		}
		if(count>2)	break;
	}
	
	if(HT[m].weight > HT[n].weight)			//令m结点的权重小于等于n结点的权重 
	{
		tmp = n;
		n = m;
		m = tmp;
	}
	
	i = (m > n ? m : n) + 1;
	while(i<=end)		//继续遍历，寻找更小更靠前的结点
	{	
		if(HT[i].parent==0)
		{
			if(HT[i].weight < HT[m].weight)
			{
				n = m;
				m = i;
			}
			else
			{
				if(HT[i].weight >= HT[m].weight && HT[i].weight < HT[n].weight)
					n = i;
			}		
		}
		i++;
	}
	
	*order_1 = HT[m].weight <= HT[n].weight ? m : n;
	*order_2 = HT[m].weight > HT[n].weight ? m : n;
	return OK;
}

//3.建立哈夫曼树
Status CreateHuffmanTree(HuffmanTree *HT)
{
	int m, n, s1, s2;
	int w[MAX_TREE_SIZE];
	
	printf("请输入哈夫曼树叶子结点个数：");
	scanf("%d", &n); 
	printf("请依次输入各叶子结点的权值：");
	for(int i = 1; i <= n; i++)		//0号单元弃用
		scanf("%d", &w[i]);
	printf("\n");
	
	m = 2 * n - 1;			//哈夫曼树有效结点个数
		
	*HT = (HuffmanTree)malloc((m+1)*sizeof(HTNode));	//0号单元弃用
	if(!(*HT))	exit(OVERFLOW);
	
	(*HT)[0].weight = n;	//利用0号单元的权值存储哈夫曼树叶子个数
 		
	for(int i = 1; i <= m; i++)		//初始化结点[1...2*n-1]
	{	
		if(i<=n)	(*HT)[i].weight = w[i];		//[1...n]，存储叶子结点
		else	(*HT)[i].weight = 0;				//[n+1...2*n-1]，存储双亲结点

		(*HT)[i].parent = 0;
		(*HT)[i].lchild = 0;
		(*HT)[i].rchild = 0; 
	}
	
	for(int i = n + 1; i <= m; i++)				//建立哈夫曼树
	{
		//在HT[1...i-1]中选择parent为0且weight最小的两个结点，其序号分别为s1和s2
		Select(*HT, i-1, &s1, &s2);
	
		(*HT)[s1].parent = (*HT)[s2].parent = i;
		(*HT)[i].lchild = s1;
		(*HT)[i].rchild = s2;
		(*HT)[i].weight = (*HT)[s1].weight + (*HT)[s2].weight;
	}
	
	return OK;
}

// 从叶子到根逆向求每个字符的哈夫曼编码 
Status HuffmanCodeing1(HuffmanTree HT, HuffmanCode *HC)
{
	char* code;
	int start, c, f;
	
	int n = HT[0].weight;			//叶子结点个数 
	
	*HC = (HuffmanCode)malloc((n+1)*sizeof(HCNode));
	if(!(*HC))	exit(OVERFLOW);
	
	code = (char*)malloc(n*sizeof(char));	//分配求编码的工作空间
	if(!code)	exit(OVERFLOW);	
	
	code[n-1] = '\0';				//字符串结尾 
	for(int i = 1; i <= n; i++)		//逐次求每个叶子结点的哈夫曼编码 
	{
		start = n - 1;					//赋值起点 
		for(c = i, f = HT[i].parent; f != 0; c = f, f = HT[f].parent)
		{
			if(HT[f].lchild==c)
				code[--start] = '0';
			else
				code[--start] = '1';
		}
		
		(*HC)[i] = (char*)malloc((n-start)*sizeof(char));
		
		strcpy((*HC)[i], &code[start]);			//从start开始复制 
	}
	
	free(code);
}

//先序遍历计算哈夫曼编码值 
Status HuffmanCodeing2(HuffmanTree HT, HuffmanCode *HC)
{
	int mark[MAX_TREE_SIZE];
	char* code;
		 
	int n = HT[0].weight;						//哈夫曼树叶子结点个数
	int m = 2 * n - 1;			//哈夫曼树结点个数 
	
	*HC = (HuffmanCode)malloc((n+1)*sizeof(HCNode));
	if(!(*HC))	exit(OVERFLOW);	

	code = (char*)malloc(n*sizeof(char));
	if(!code)	exit(OVERFLOW);
		
	for(int i = 1; i <= m; i++)			//初始化访问标记 
		mark[i] = 0;	//0、1、2分别表示访问过0次、1次、2次
	
	int p = m;
	int cdlen = 0;
	
	while(p)
	{
		if(mark[p]==0)			//第一次访问此结点
		{
			mark[p] = 1;
			if(HT[p].lchild!=0)		//向左访问 
			{
				p = HT[p].lchild;						//p向左走一步							
				code[cdlen++] = '0';
			}
			else if(HT[p].rchild==0)						//找到叶子结点 
			{
				(*HC)[p] = (char*)malloc((cdlen+1)*sizeof(char));
				code[cdlen] = '\0';
				strcpy((*HC)[p], code);				//复制编码串 
			}
		}
		else if(mark[p]==1)			//第二次访问此结点
		{
			mark[p] = 2;
			if(HT[p].rchild!=0)
			{
				p = HT[p].rchild;
				code[cdlen++] = '1';
			}
		}
		else	//mark[p]==2	//第三次访问 
		{
			mark[p] = 0;
			p = HT[p].parent;						//退回到父结点
			cdlen--;								//编码长度减1
		}	
	}
	free(code);
}

void ShowHuffmanTree(HuffmanTree HT)
{
	printf("┏━━━┳━━━┳━━━┳━━━┳━━━┓\n");
	printf("┃*order┃weight┃parent┃lchild┃rchild┃\n");
	for(int i = 0; i <= 2*HT[0].weight-1; i++)
	{
		if(i==0)
			printf("┃  %2d  ┃ %4d ┃  ×  ┃  ×  ┃  ×  ┃\n", i, HT[i].weight);
		else
			printf("┃  %2d  ┃ %4d ┃  %2d  ┃  %2d  ┃  %2d  ┃\n", i, HT[i].weight, HT[i].parent, HT[i].lchild, HT[i].rchild);
	}
	printf("┗━━━┻━━━┻━━━┻━━━┻━━━┛\n");
}

void ShowHuffmanCode(HuffmanTree HT, HuffmanCode HC)
{	
	printf("┏━━━┳━━━┳━━━┳━━━━━━━┓\n");
	printf("┃*order┃weight┃      ┃  哈夫曼编码  ┃\n");
	for(int i = 1; i <= HT[0].weight; i++)
	{
		printf("┃  %2d  ┃ %4d ┃──→  %-14s┃\n", i, HT[i].weight, HC[i]);
		num+=strlen(HC[i]);
	}
	num/=HT[0].weight;
	printf("┗━━━┻━━━┻━━━┻━━━┻━━━┛\n");
}

int main()
{
	HuffmanTree HT;
	HuffmanCode HC;
	
	InitTree(&HT);
	CreateHuffmanTree(&HT);
	ShowHuffmanTree(HT);
	
	//HuffmanCodeing1(HT, &HC); 
	HuffmanCodeing2(HT, &HC);
	ShowHuffmanCode(HT, HC);
	printf("平均的哈夫曼编码长度为%d",num);
	return 0;
}

