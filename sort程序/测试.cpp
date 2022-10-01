#include<malloc.h>
#include<string.h>
#include<stdlib.h>
#include <stdio.h>
#include <math.h>
struct gen                //定义染色体结构X
{
	int  info;        		//染色体结构 //表示length 个(0,255)的整数
	int  suitability;		//次染色体所对应的适应度函数值，在本题中为f(x)=|AX-B|的无穷范数 理想状态应该是1 选择时最大的  我们把它设置成整数就是f(x)的值
};
struct gen	new1[2]={{1,2},{2,2}};
main()
{
 
  struct gen *s;
  s=(struct gen*)malloc(sizeof(gen));
  *s=new1[0];
  new1[0]=new1[1];
  new1[1]=*s;
  free(s);
  printf("%d %d",new1[0].info,new1[1].info);
}
