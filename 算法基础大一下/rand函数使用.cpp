#include<malloc.h>
#include<string.h>
#include<stdlib.h>
#include <stdio.h>
#include <math.h>
main()
{
	int x;int i;
	for(i=0;i<=100;i++){
		 x=rand()%5+1;//rand()%x+y
  printf("%d\n",x); 
	}
	//结论：rand的取值为 [y,x+y) 
}
