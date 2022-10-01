#include<malloc.h>
#include<string.h>
#include<stdlib.h>
#include <stdio.h>
main()
{
	FILE * fp1,* fp2;
	char c;
	if(( fp1=fopen("31.txt","r"))==NULL)
	{
		printf("no1\n");
		exit(0);
	}
	if( (fp2=fopen("32.txt","w"))==NULL)
	{
		printf("no2\n");
		exit(0);
	}	
	int x=0;
	fseek(fp2,1000l,0);
	while(!feof(fp1))
	{
	    x++;
		c=fgetc(fp1);
		//fseek(fp1,-2l,1);
		fputc(c,fp2);
		fseek(fp2,-2l,1);
	//	rewind(fp2);
	
    //fseek(fp2,-1l,1);
	}
  
}
