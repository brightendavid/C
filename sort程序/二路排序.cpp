#include<malloc.h>
#include<string.h>
#include<stdlib.h>
#include <stdio.h>
#include <math.h>
#define maxsize 100
typedef  int elem;
void merge(elem list[],elem sorted[],int l,int m,int r);
void merge_pass(elem list[],elem sorted[],int n,int length){
	int i,j;
	for(i=0;i<=n-2*length;i+=2*length){
		merge(list,sorted,i,i+length-1,i+2*length-1);
	}
	if(i+length<n){//剩下部分 
		merge(list,sorted,i,i+length-1,n-1);
	}
	else{
		for(j=i;j<n;j++){
			sorted[j]=list[j];
		}
	}
}
void merge(elem list[],elem sorted[],int l,int m,int r){
	int i,j,k;
	i=l,j=m+1,k=i;
	while(i<=m&&j<=r){//可以比较 
		if(list[i]<=list[j]){
			sorted[k++]=list[i++];
		}
		else{
			sorted[k++]=list[j++];
		}
	}
	if(i>m){//一方为空 
		while(j<=r){
			sorted[k++]=list[j++];
		}
	}
	else{
		while(i<=m){
			sorted[k++]=list[i++];
		}
	}
}
void merge_sort(elem list[],int n){
	int len=1;
	elem extra[maxsize];
	while(len<n){
		merge_pass(list,extra,n,len);
		len*=2;
		merge_pass(extra,list,n,len);
		len*=2;
	}
}
main()
{
  elem list[maxsize];
  for(int i=0;i<=maxsize-1;i++){
  	list[i]=i*(40-i);
  }
   for(int i=0;i<=maxsize-1;i++){
  	printf("%d  ",list[i]);
  }
  printf("\n\n");
  merge_sort(list,maxsize); 
  for(int i=0;i<=maxsize-1;i++){
  	printf("%d  ",list[i]);
  }
  printf("\n\n");
}
