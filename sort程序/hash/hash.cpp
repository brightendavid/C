#include<malloc.h>
#include<string.h>
#include<stdlib.h>
#include <stdio.h>
#include <math.h>
#define max 10
#define size 13
typedef struct {
	char key[max];
}elem;
typedef struct list *listpoint;
typedef struct list{
	elem item;
	listpoint link;
};
listpoint hashtable[size];
int hash(char *s){//使用首字母创建HASH表 
	return s[0]-'a';
}
//使用链表法处理冲突 
void chain(elem item,listpoint ht[]){
	int hashvalue =hash(item.key);
	listpoint ptr ;
	listpoint trail =NULL,lead =ht[hashvalue];
	for(;lead;trail =lead,lead=lead->link){
		if(!strcmp(lead->item.key,item.key))
		exit(1);
	}
	ptr=(listpoint)malloc(sizeof(list));
	if(!ptr)
	{
		exit(1);
	}
	
	ptr->item=item;
	ptr->link=NULL;
	if(trail){
		trail->link=ptr;
	}
	else{
		ht[hashvalue]=ptr;
	}
}
main()
{
  
}
