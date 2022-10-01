#include<malloc.h>
#include<string.h>
#include<stdlib.h>
#include <stdio.h>
#include <math.h>
typedef struct _date
{
	int a;
	int b;
 }Data;
 Data * f(int a,int b)
 {
 	Data * data=new Data;
 	data->a=a;
 	data->b=b;
 	return data;
 }
main()
{
  Data *my=f(3,4);
  printf("%d %d",my->a,my->b);
}
