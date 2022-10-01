#include<malloc.h>
#include<string.h>
#include<stdlib.h>
#include <stdio.h>
main()
{
  int i,j;
  float n;
  int index;
  scanf("%f",&n);
  index=n<60?1:(n-60)/10+2;
  switch(index)
  {
  	case 1:
  		printf("E\n");
  		break;
  	case 2:
  		printf("D\n");
  		break;
  	case 3:
  		printf("C\n");
  		break;
  	case 4:
  		printf("B\n");
  		break;
  	case 5:
  		printf("A\n");
  		break;
   } 
}
