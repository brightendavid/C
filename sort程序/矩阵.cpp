#include<malloc.h>
#include<string.h>
#include<stdlib.h>
#include <stdio.h>
#include <math.h>
typedef  int elem;
#define MAXSIZE 256*256*3
typedef struct{
	int i,j;
	elem e;
}Triple;
typedef struct{
	Triple data[MAXSIZE+1];
	int mu,nu,tu;//行数 列数 数据数 
}TS;
main()
{
	TS A,B,X;
	X.mu=MAXSIZE;
	X.nu=1;
	int i,j;
	int sum[MAXSIZE];
	for(i=0;i<=MAXSIZE-1;i++)
	{
		sum[i]=0;
	}
	char ch;
    int I=1;
	int hang,lie,shu;
	i=1;j=1; 
	A.mu=MAXSIZE;
	A.nu=MAXSIZE;  
	B.mu=MAXSIZE;
	B.nu=1;
	while(scanf("(%d,%d,%d)",&hang,&lie,&shu)!=EOF&&hang!=0)
	{
		A.data[I].i=hang;
		A.data[I].j=lie;
		A.data[I].e=shu;
		I++;
	}
	A.tu=I-1;
	I=1;
	while(scanf("(%d,%d,%d)",&hang,&lie,&shu)!=EOF&&hang!=0)
	{
		B.data[I].i=hang;
		B.data[I].j=lie;
		B.data[I].e=shu;
		I++;	
	}
	B.tu=I-1;
	I=1;
	i=1;
	while(I<=A.tu)
	{
		sum[A.data[I].i]+=A.data[I].e;
		I++;
	}
	for(i=1;i<=MAXSIZE-1;i++)
	{
		X.data[i].e=B.data[i].e/sum[i];
		X.data[i].j=1;
		X.data[i].i=i;
		printf("(%d,%d,%d)\n",X.data[i].i,X.data[i].j,X.data[i].e);
	}
	
}
