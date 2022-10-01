#include<malloc.h>
#include<string.h>
#include<stdlib.h>
#include <stdio.h>
#include <math.h>
#define max 10 
#define swap(x,y,z) {z=x;x=y;y=z  ;}
int d[]={5,3,2,1};
typedef struct ff{
	int key;
}dd;

void shellsort(dd x[],int n){//从小到大排序 
	int i,j,k,span,m;
	dd s;
	int gap;
	for(gap=n/2;gap>0;gap/=2){
		for(i=gap;i<n;i++){
			for(j=i;j-gap>=0&&x[j-gap].key>x[j].key;j-=gap){
				s=x[j-gap];
				x[j-gap]=x[j];
				x[j]=s;
			}
		}
		for(int i=0;i<n;i++){
		printf("  %d  ",x[i].key);
	}
	printf("\n");
	}

}
void quicksort(dd x[],int l,int r){
	dd ss,temp;
	int p;
	if(l<r){
		int i=l,j=1+r;
		int t=0;
	int 	ss=x[l].key;
	do{
		do i++;
		while(x[i].key<ss);
		do j--;
		while(x[j].key>ss);
		if(i<j){
			swap(x[i],x[j],temp);
		}
		
	}while(i<j);
		swap(x[l],x[j],temp);
		quicksort(x,l,j-1);
		quicksort(x,j+1,r);
		
	}
	
}
void insert(dd list[],int n){
	int i,j;
	int x;
	printf("输入%d个数据\n",n);
	for(i=0;i<n;i++){
		scanf("%d",&x);
		list[i].key=x;
		printf("%d %d\n",i,list[i].key);
	}
	printf("\n");
	for(i=0;i<n;i++){
		printf("  %d  ",list[i].key);
	}
	printf("\n");
	
}
main()
{
	dd list[max];
  insert(list,max);
  //shellsort(list,max);
  quicksort(list,0,max-1);
  int i;
  	for(i=0;i<max;i++){
		printf("  %d  ",list[i].key);
	}
	printf("\n");
}
