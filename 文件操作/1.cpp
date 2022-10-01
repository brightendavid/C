#include<malloc.h>
#include<string.h>
#include<stdlib.h>
#include <stdio.h>
main()
{
  char c;
  FILE *fp;
  if((fp=fopen("1.txt","r"))==NULL)
  {
  	printf("cant");
  	exit(1);
   } 
   else
   while((c=fgetc(fp))!=EOF)
   {
   	putchar(c);
   }
   fclose(fp);
   return 0;
}
