#include <stdio.h>
#include <math.h>
#include <stdlib.h>					//�ṩmalloc��realloc��free��exitԭ��
#include <string.h>						//�ṩstrcpyԭ�� 
#define	TRUE		1			//�� 
#define	FALSE		0			//��
#define YES			1			//��
#define NO          0			//�� 
#define	OK			1			//ͨ��
#define	ERROR		0			//����
#define SUCCESS		1			//�ɹ�
#define UNSUCCESS	0			//ʧ�� 
#define	INFEASIBLE	-1			//������
int num=0; 
#define MAX_TREE_SIZE 100		//�����������
typedef int Status;

/* ���������͹�������������Ͷ��� */
typedef struct
{
	unsigned int weight;			//Ȩֵ 
	unsigned int parent;						
	unsigned int lchild;
	unsigned int rchild;
}HTNode;
typedef HTNode* HuffmanTree;		//��̬��������洢�������� 
typedef char* HCNode;
typedef HCNode* HuffmanCode;		//��̬��������洢����������� 

//1.�������HT(��ʼ����)
void InitTree(HuffmanTree *HT)
{
	*HT = NULL;
}

//2.�ڹ����������[1...end]������ѡ��Ȩֵ��С��δ�������������������order_1��order_2
Status Select(HuffmanTree HT, int end, int *order_1, int *order_2)
{
	int i, count;
	int m, n, tmp;
	
	if(end<2)	return ERROR;
	
	for(i = 1, count = 1; i <= end; i++)	//�����ҳ�ǰ����δ�������Ľ�� 
	{
		if(HT[i].parent==0)
		{
			if(count==1)	m = i;
			if(count==2)	n = i;
			count++;
		}
		if(count>2)	break;
	}
	
	if(HT[m].weight > HT[n].weight)			//��m����Ȩ��С�ڵ���n����Ȩ�� 
	{
		tmp = n;
		n = m;
		m = tmp;
	}
	
	i = (m > n ? m : n) + 1;
	while(i<=end)		//����������Ѱ�Ҹ�С����ǰ�Ľ��
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

//3.������������
Status CreateHuffmanTree(HuffmanTree *HT)
{
	int m, n, s1, s2;
	int w[MAX_TREE_SIZE];
	
	printf("�������������Ҷ�ӽ�������");
	scanf("%d", &n); 
	printf("�����������Ҷ�ӽ���Ȩֵ��");
	for(int i = 1; i <= n; i++)		//0�ŵ�Ԫ����
		scanf("%d", &w[i]);
	printf("\n");
	
	m = 2 * n - 1;			//����������Ч������
		
	*HT = (HuffmanTree)malloc((m+1)*sizeof(HTNode));	//0�ŵ�Ԫ����
	if(!(*HT))	exit(OVERFLOW);
	
	(*HT)[0].weight = n;	//����0�ŵ�Ԫ��Ȩֵ�洢��������Ҷ�Ӹ���
 		
	for(int i = 1; i <= m; i++)		//��ʼ�����[1...2*n-1]
	{	
		if(i<=n)	(*HT)[i].weight = w[i];		//[1...n]���洢Ҷ�ӽ��
		else	(*HT)[i].weight = 0;				//[n+1...2*n-1]���洢˫�׽��

		(*HT)[i].parent = 0;
		(*HT)[i].lchild = 0;
		(*HT)[i].rchild = 0; 
	}
	
	for(int i = n + 1; i <= m; i++)				//������������
	{
		//��HT[1...i-1]��ѡ��parentΪ0��weight��С��������㣬����ŷֱ�Ϊs1��s2
		Select(*HT, i-1, &s1, &s2);
	
		(*HT)[s1].parent = (*HT)[s2].parent = i;
		(*HT)[i].lchild = s1;
		(*HT)[i].rchild = s2;
		(*HT)[i].weight = (*HT)[s1].weight + (*HT)[s2].weight;
	}
	
	return OK;
}

// ��Ҷ�ӵ���������ÿ���ַ��Ĺ��������� 
Status HuffmanCodeing1(HuffmanTree HT, HuffmanCode *HC)
{
	char* code;
	int start, c, f;
	
	int n = HT[0].weight;			//Ҷ�ӽ����� 
	
	*HC = (HuffmanCode)malloc((n+1)*sizeof(HCNode));
	if(!(*HC))	exit(OVERFLOW);
	
	code = (char*)malloc(n*sizeof(char));	//���������Ĺ����ռ�
	if(!code)	exit(OVERFLOW);	
	
	code[n-1] = '\0';				//�ַ�����β 
	for(int i = 1; i <= n; i++)		//�����ÿ��Ҷ�ӽ��Ĺ��������� 
	{
		start = n - 1;					//��ֵ��� 
		for(c = i, f = HT[i].parent; f != 0; c = f, f = HT[f].parent)
		{
			if(HT[f].lchild==c)
				code[--start] = '0';
			else
				code[--start] = '1';
		}
		
		(*HC)[i] = (char*)malloc((n-start)*sizeof(char));
		
		strcpy((*HC)[i], &code[start]);			//��start��ʼ���� 
	}
	
	free(code);
}

//��������������������ֵ 
Status HuffmanCodeing2(HuffmanTree HT, HuffmanCode *HC)
{
	int mark[MAX_TREE_SIZE];
	char* code;
		 
	int n = HT[0].weight;						//��������Ҷ�ӽ�����
	int m = 2 * n - 1;			//�������������� 
	
	*HC = (HuffmanCode)malloc((n+1)*sizeof(HCNode));
	if(!(*HC))	exit(OVERFLOW);	

	code = (char*)malloc(n*sizeof(char));
	if(!code)	exit(OVERFLOW);
		
	for(int i = 1; i <= m; i++)			//��ʼ�����ʱ�� 
		mark[i] = 0;	//0��1��2�ֱ��ʾ���ʹ�0�Ρ�1�Ρ�2��
	
	int p = m;
	int cdlen = 0;
	
	while(p)
	{
		if(mark[p]==0)			//��һ�η��ʴ˽��
		{
			mark[p] = 1;
			if(HT[p].lchild!=0)		//������� 
			{
				p = HT[p].lchild;						//p������һ��							
				code[cdlen++] = '0';
			}
			else if(HT[p].rchild==0)						//�ҵ�Ҷ�ӽ�� 
			{
				(*HC)[p] = (char*)malloc((cdlen+1)*sizeof(char));
				code[cdlen] = '\0';
				strcpy((*HC)[p], code);				//���Ʊ��봮 
			}
		}
		else if(mark[p]==1)			//�ڶ��η��ʴ˽��
		{
			mark[p] = 2;
			if(HT[p].rchild!=0)
			{
				p = HT[p].rchild;
				code[cdlen++] = '1';
			}
		}
		else	//mark[p]==2	//�����η��� 
		{
			mark[p] = 0;
			p = HT[p].parent;						//�˻ص������
			cdlen--;								//���볤�ȼ�1
		}	
	}
	free(code);
}

void ShowHuffmanTree(HuffmanTree HT)
{
	printf("���������ש������ש������ש������ש�������\n");
	printf("��*order��weight��parent��lchild��rchild��\n");
	for(int i = 0; i <= 2*HT[0].weight-1; i++)
	{
		if(i==0)
			printf("��  %2d  �� %4d ��  ��  ��  ��  ��  ��  ��\n", i, HT[i].weight);
		else
			printf("��  %2d  �� %4d ��  %2d  ��  %2d  ��  %2d  ��\n", i, HT[i].weight, HT[i].parent, HT[i].lchild, HT[i].rchild);
	}
	printf("���������ߩ������ߩ������ߩ������ߩ�������\n");
}

void ShowHuffmanCode(HuffmanTree HT, HuffmanCode HC)
{	
	printf("���������ש������ש������ש���������������\n");
	printf("��*order��weight��      ��  ����������  ��\n");
	for(int i = 1; i <= HT[0].weight; i++)
	{
		printf("��  %2d  �� %4d ��������  %-14s��\n", i, HT[i].weight, HC[i]);
		num+=strlen(HC[i]);
	}
	num/=HT[0].weight;
	printf("���������ߩ������ߩ������ߩ������ߩ�������\n");
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
	printf("ƽ���Ĺ��������볤��Ϊ%d",num);
	return 0;
}

