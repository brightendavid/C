#include<malloc.h>
#include<string.h>
#include<stdlib.h>
#include <stdio.h>
struct club1
{
	char name[20];
	int size ;
	int year; 
}c1;
struct club2
{
	char ID;
	int size;
	int year; 
 } c2;

main()
{
   printf("%d\n",sizeof(c1));
     printf("%d\n",sizeof(struct club1));
	printf("%d\n",sizeof(c2));
     printf("%d\n",sizeof(struct club2));
     printf("%d\n",sizeof(char));
     printf("%d\n",sizeof(int));
}

