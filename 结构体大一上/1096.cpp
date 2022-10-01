#include<malloc.h>
#include<string.h>
#include<stdlib.h>
#include <stdio.h>
main()
{
  int a[4];
  int i,j;
  int t;
  for(i=0;i<=3;i++)
  {
  	scanf("%d",&a[i]);
   } 
   for(i=0;i<=1;i++)
   {
      printf("%d %d %d\n",a[0],a[1],a[2]);
     	 printf("%d %d %d\n",a[0],a[2],a[1]);
   	  printf("%d %d %d\n",a[1],a[0],a[2]);
   	   printf("%d %d %d\n",a[1],a[2],a[0]);
   	  printf("%d %d %d\n",a[2],a[0],a[1]);
   	   printf("%d %d %d\n",a[2],a[1],a[0]);
   	   if(i==1)
   	   {
   	   	   a[0]=t;
		}
      printf("%d %d %d\n",a[0],a[1],a[3]);
    	 printf("%d %d %d\n",a[0],a[3],a[1]);
      printf("%d %d %d\n",a[1],a[0],a[3]);
   	 printf("%d %d %d\n",a[1],a[3],a[0]);
   	  printf("%d %d %d\n",a[3],a[0],a[1]);
   	 printf("%d %d %d\n",a[3],a[1],a[0]);
   	 t=a[1];
   	 a[1]=a[2];
   	 a[2]=a[3];
   }
   	 
   	 
}
