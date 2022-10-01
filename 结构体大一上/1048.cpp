#include<malloc.h>
#include<string.h>
#include<stdlib.h>
#include <stdio.h>
main()
{
  char a[10000];
  char b[100];
  int c[10000];
  int i,j;
  i=0;
  int n;
  int m;
  char *p,*q;
  int count=0;
  int bol=0;
  scanf("%d",&n);
  while(n>0)
  {
  	n--;
  	scanf("%d",&m);
  	gets(a);
  	for(p=a;*p!='\0';p++)
  	{
  		if(p==a||bol==1)
  		{
  			b[i]=*p;
  			i++;
  			bol=0;
		}
		if(*p==' ')
		{
			bol=1;
		}
	}
  }
}
