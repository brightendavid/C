#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef char ElemType;
typedef struct Node
{
    ElemType data[100];
    struct Node *next;
}SqList;


void CreateList(SqList *&L)
{
    L=(SqList *)malloc(sizeof(SqList));
    L->next=NULL;
}
void zhuanhuan(SqList *&L)
{
    SqList *p=L->next,*q,*pre,*r;
    while(p!=NULL)
    {
        q=p->next;pre=p;
        while(q!=NULL)
        {
            if(strcmp(p->data,q->data)==0)
            {
                r=q;pre->next=q->next;
                q=q->next;
                free(r);
            }
            else
            {
                pre=q;
                q=q->next;
            }
        }
        p=p->next;
    }
}
void print(SqList *L)
{
    SqList *p=L->next;
    while(p!=NULL)
    {
        printf("%s ",p->data);
    p=p->next;
    }
}




int main()
{
    SqList *p;
    int n,i;
    char a[100][100];
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%s",a[i]);
     CreateList(p);
     SqList *r=p,*s;


     for(i=0;i<n;i++)
     {
         s=(SqList *)malloc(sizeof(SqList));
         strcpy(s->data,a[i]);
         r->next=s;
         r=s;
     }
    r->next=NULL;
    zhuanhuan(p);
    print(p);
}
