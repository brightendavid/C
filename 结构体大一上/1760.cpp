#include<malloc.h>
#include<string.h>
#include<stdlib.h>
#include <stdio.h>
void  up(char *x,char *y)
{
	char *p,*q;
	q=y;
	for(p=x;*p!='\0';p++)
	{
		if((*p)>='a'&&(*p)<='z')
		{
			*q=*p-32;
			q++;
		}
		else
		{
			*q=*p;
			q++;
		}
	}
      *q='\0'; 
}
main()
{
  int i,j;
  int n,m;
  char *p;
  char a[100];
  char b[100];
  while(gets(a)!=NULL)
  {
       up(a,b);
       //puts(a);
  	 //	puts(b);
       if(strstr(b,"SALT")!=NULL)
       {
       	puts(a);
	   }
  }
}
