#include <stdio.h>
#include <malloc.h>
struct Num
{
    int n;
    struct Num *next;
}num;
struct Num *createlist(struct Num *head);
void print(struct Num *head);
void destroy(struct Num *head);
void destroy(struct Num *head)
{
 struct Num *p;
 while(head!=NULL) 
 {
  p=head->next;
  delete(head);
  head=p;
 }
}


int main()
{
    struct Num *head=NULL;
    head=createlist(head);       //����
    print(head);//���
 destroy(head);
    return 0;
}
struct Num *createlist(struct Num *head)                //ͷ�巨��������
{
    struct Num *p;
    p=head=(struct Num*)malloc(sizeof(struct Num));
    head=NULL;     
	int count=0;                                
    p=(struct Num*)malloc(sizeof(struct Num));            //p�����½��
    while(scanf("%d",&p->n)!=EOF)                      //���½��嵽��ͷ��λ��
    {
        /***************/

        p->next=head;
        head=p;
        /*****************/
           
        p=(struct Num*)malloc(sizeof(struct Num));
       /* count++;
		if(count==5)
		{
			break;
		} */        //pÿ�ν����½��
    }
    return head;
}

void print(struct Num *head)
{
    struct Num *current=head;
    while(current!=NULL)
    {
        printf("%d ",current->n);
        current=current->next;
    }
}

