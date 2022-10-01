#include<malloc.h>
#include<string.h>
#include<stdlib.h>
#include <stdio.h>
#include <math.h>
struct ListNode {
     int val;
     struct ListNode *next;
 };
int main()
{
  struct ListNode *l1,*l2;
    l1= (struct ListNode *)malloc(sizeof(struct ListNode));
    l2= (struct ListNode *)malloc(sizeof(struct ListNode));
    l1->val=1;
    l2->val=2;
    l1->next=NULL;
    l2->next=NULL;
    struct ListNode * u=mergeTwoLists(l1,l2);
    while(u!=NULL)
    {
    	printf("%d->",u->val);
    	u=u->next;
	}
	return 0;
}

 //* Definition for singly-linked list.
 

 struct ListNode *t;
void add(int x)
{
    struct ListNode *z;
    z=(struct ListNode*)malloc(sizeof(struct ListNode));
    t->next=z;
    z->val=x;
    t=z;
    t->next=NULL;
}

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    struct ListNode *a=(struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode *p,*q;
    p=l1,q=l2;
    t=a;
    if(p==NULL&&q==NULL)
    {
        return NULL;
    }
    if(q==NULL)
    {
        return p;
    }
    if(p==NULL)
    {
        return  q;
    }
    while(q!=NULL||p!=NULL)
    {
        if(p==NULL||p->val>q->val)
        {
            add(q->val);
            q=q->next;
        }
        else if(q==NULL||p->val<=q->val)
        {
            add(p->val);
            p=p->next;
        }
    }
    return a->next;
}
