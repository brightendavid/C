#include<malloc.h>
#include<string.h>
#include<stdlib.h>
#include <stdio.h>
main()
{
  char ch;
  FILE *fp1,*fp2;
  char srcfile[20],tarfile[20];
  printf("please"); 
  scanf("%s",srcfile);
    printf("please");
  scanf("%s",tarfile);
  if((fp1=fopen(srcfile,"r"))==NULL)
  {
  	printf("cant:%s:\n",srcfile);
  	exit(1);
  }
  if((fp2=fopen(tarfile,"w"))==NULL)
  {
  	printf("cant:%s\n",tarfile);
  	exit(1);
  }
  while((ch=fgetc(fp1))!=EOF)
  {
  		fputc(ch,fp2);
  }
  fclose(fp1);
  fclose(fp2);
}
