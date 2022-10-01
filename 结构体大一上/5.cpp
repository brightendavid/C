#include<malloc.h>
#include<string.h>
#include<stdlib.h>
#include <stdio.h>
main()
{
  int i,j;
  int n,m;
  int a[1000]; 
  int b[1000];
 char c[1000][10];
  int maxi;
  scanf("%d",&n);
  
  while(n>0)
  {
  	n--;
  	//getchar();
	  scanf("%d",&m);
	maxi=0;
	for(i=0;i<m;i++)
	  {
	  	scanf("%d",&a[i]);
	  	scanf("%d",&b[i]);
	  	scanf("%s",c[i]);
	  	getchar();
	  	if(a[maxi]<a[i])
	  	{
	  		maxi=i;
		  }
		else if(a[i]==a[maxi]&&b[maxi]>b[i])
		{
			maxi=i;
		 } 
		 else if(a[i]==a[maxi]&&b[maxi]==b[i]&&strcmp(c[maxi],c[i])<0)
		 {
		 	maxi=i;
		 }
		
	   } 
	    printf("%s\n",c[maxi]);
  } 
}
