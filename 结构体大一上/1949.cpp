#include<malloc.h>
#include<string.h>
#include<stdlib.h>
#include <stdio.h>
main()
{
  int i,j;
  int a[4];
  for(i=0;i<=3;i++)
  {
  	a[i]=0;
  }
  char ss[100];
  gets(ss);
  for(i=0;i<=strlen(ss)-1;i++)
  {
    if(ss[i]>='a'&&ss[i]<='z'||ss[i]>='A'&&ss[i]<='Z')
    {
    	a[0]++;
	}
	else if(ss[i]==' ')
	{
		a[1]++;
	}
	else if(ss[i]>='0'&&ss[i]<='9')
	{
		a[2]++;
	 } 
	 else
	 {
	 	a[3]++;
	 }
  }
  for(i=0;i<=2;i++)
  {
  	printf("%d,",a[i]);
  }
  printf("%d",a[i]);;
}
