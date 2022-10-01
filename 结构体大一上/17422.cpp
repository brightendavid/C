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
    head=createlist(head);       //建立
    print(head);//输出
 destroy(head);
    return 0;
}
struct Num *createlist(struct Num *head)                //头插法建立链表
{
    struct Num *p;
    p=head=(struct Num*)malloc(sizeof(struct Num));
    head=NULL;     
	int count=0;                                
    p=(struct Num*)malloc(sizeof(struct Num));            //p建立新结点
    while(scanf("%d",&p->n)!=EOF)                      //将新结点插到开头的位置
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
		} */        //p每次建立新结点
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

