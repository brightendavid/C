#include<malloc.h>
#include<string.h>
#include<stdlib.h>
#include <stdio.h>
#include <math.h>
#define true 1
#define false 0
typedef  int ElemType;
typedef  int KeyType;
typedef struct BI {
	int data;
	int bf;
	struct BI *lchild ,*rchild;
}*BiTree,Bitree ; 
void  libian(BiTree T);
    BiTree SearchBST(BiTree T,KeyType key){
        //����ݹ������ T Ϊ�գ�����ҽ��������NULL�����߲��ҳɹ�������ָ��ùؼ��ֵ�ָ��
        if (!T || key==T->data) {
            return T;
        }else if(key<T->data){
            //�ݹ����������
            return SearchBST(T->lchild, key);
        }else{
            //�ݹ�������Һ���
            return SearchBST(T->rchild, key);
        }
    }
int  SearchBST(BiTree T,KeyType key,BiTree f,BiTree *p){
        //��� T ָ��Ϊ�գ�˵������ʧ�ܣ��� p ָ��ָ����ҹ��������һ��Ҷ�ӽ�㣬�����ز���ʧ�ܵ���Ϣ
        if (!T){
            *p=f;
            return false;
        }
        //�����ȣ��� p ָ��ָ��ùؼ��֣������ز��ҳɹ���Ϣ
        else if(key==T->data){
            *p=T;
            return true;
        }
        //��� key ֵ�� T ������ֵС�������������������֮��������������
        else if(key<T->data){
            return SearchBST(T->lchild,key,T,p);
        }else{
            return SearchBST(T->rchild,key,T,p);
        }
    }
    //���뺯��
int InsertBST(BiTree T,ElemType e){
        BiTree p=NULL;
        //������Ҳ��ɹ��������������
        if (!SearchBST(T, e,NULL,&p)) {
            //��ʼ��������
            BiTree s=(BiTree)malloc(sizeof(BiTree));
            s->data=e;
            s->lchild=s->rchild=NULL;
            libian(T);
            
            //��� p ΪNULL��˵���ö���������Ϊ��������ʱ����Ľ��Ϊ�������ĸ����
            if (!p) {
                T=s;
            }
            //��� p ��Ϊ NULL���� p ָ���Ϊ����ʧ�ܵ����һ��Ҷ�ӽ�㣬ֻ��Ҫͨ���Ƚ� p �� e ��ֵȷ�� s ������ p �����ӻ����Һ���
            else if(e<p->data){
                p->lchild=s;
            }else{
                p->rchild=s;
            }
            return true;
        }
        //������ҳɹ�������Ҫ���������������ʧ��
        return false;
    }
void R(Bitree *p){//���� 
	Bitree *lc;
	lc = p->lchild;
	p->lchild=lc->rchild;
	lc->rchild=p;
	p=lc;
}
void L(Bitree *p){//���� 
	Bitree *lc;
	lc=p->rchild;
	p->rchild=lc->lchild;
	lc->lchild=p;
	p=lc;
}
int  num(BiTree T){//���������� 
	if(T->lchild&&T->rchild)
	 return num(T->lchild)+num(T->rchild);
	else if (T->lchild){
		return num(T->lchild); 
	}
	else if(T->rchild)
	{
		return num(T->rchild);
	}
	else{
		return 0;
	}
}
void  libian(BiTree T){
	if(T==NULL)
	{
		return ;
	}
	T->bf= num(T->lchild)-num(T->rchild);
	libian(T->lchild);
	libian(T->rchild);
	if((T->bf>1||T->bf<-1)&&T->lchild->bf<=1&&T->lchild->bf>=1&&T->rchild->bf<=1&&T->rchild->bf<=1){//��С��ƽ�� 
		printf("%d",T->data);
	}
}

void LL(BiTree T){
	R(T);
}
void RR(BiTree T){
	L(T);
}
void RL(BiTree T){
	R(T->lchild);
	L(T);
}
void LR(BiTree T){
	L(T->lchild);
	R(T);
} 
main()
{
  
}
