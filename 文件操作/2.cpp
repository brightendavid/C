#include<malloc.h>
#include<string.h>
#include<stdlib.h>
#include <stdio.h>
main(int argc,char *argv[])
{
  int i;
  FILE *fp;
  char c;
  if(argc==1)
  {
  	printf("no");
  	exit(1);
  }
  for(i=1;i<argc;i++)
  {
  	if((fp=fopen(argv[i],"r"))==NULL)
  	{
  		printf("no:%s\n",argv[i]);
  		exit(1);
	  }
	  while((c=fgetc(fp))!=EOF)
	  {
	  	putchar(c);
	   } 
	   fclose(fp);
  }
  
}
