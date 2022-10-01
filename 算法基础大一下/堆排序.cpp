#include<malloc.h>
#include<string.h>
#include<stdlib.h>
#include <stdio.h>
#include <math.h>
#define swap(i,j,k){ k=i;i=j;j=k;}
typedef struct element {
	int key;
} element;
void adjust(element list[],int root,int n) {
	int child,rootkey;
	element temp;
	temp=list[root];
	rootkey=list[root].key;
	child =2*root;
	while(child<=n) {
		if((child <n)&&list[child].key<list[child+1].key) {
			child++;
		}
		if(rootkey>list[child].key) {
			break;
		}
		else{
			list[child/2]=list[child];
			child*=2;
		}
	}
	list[child/2]=temp;
}
void heapsort(element list[],int n){
	int i,j;
	element temp;
	for(i=n/2;i>0;i--){
		adjust(list,i,n);
	}
	for(i=n-1;i>0;i--){
		swap(list[1],list[i+1],temp);
		adjust(list,1,i);
	}
}
main() {

}
