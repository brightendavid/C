#include<malloc.h>
#include<string.h>
#include<stdlib.h>
#include <stdio.h>
main()
{
  int i,j;
  int a[100];
  int b[100];
  char dd[100];
  char ss[100];
  i=0;
  int c[100];
  int n,m;
  i=0;
  j=0; 
  gets(dd);
  for(i=0;i<=99;i++)
  {
  	a[i]=0;
  	b[i]=0;
  }
  i=0;
  j=0;
  while(dd[i]!='\0')
  {
  	if(dd[i]!=' ')
  	{
  		a[j]=dd[i]-'0'+a[j]*10;
	}
	else
	{
		j++;
	}
  	i++;
  }
  n=j-1;
    
  int t=0;
  gets(ss);
  i=0;j=0;
  while(ss[i]!='\0')
  {
  	if(ss[i]!=' ')
  	{
  		b[j]=b[j]*10+ss[i]-'0';
	}
	else
	{
		j++;
	}
  	i++;
  }
  m=j-1;
  t=0;
	  for(i=0;i<=n;i++)
	  {
	  	for(j=0;j<=m;j++)
	  	{
	  		if(a[i]==b[j])
	  		{
	  			c[t]=a[i];
	  			t++;
	  			break;
	  			
			  }
		  }
	  }
  /*for(i=0;i<=n;i++)
  {
  	printf("%d ",a[i]);
  }*/
  printf("\n");
		for(i=0;i<=t-1;i++)
		{
			printf("%d ",c[i]);
		}
}
