#include<malloc.h>
#include<string.h>
#include<stdlib.h>
#include <stdio.h>
 
main()
{
  
 long long sum=0;
  long long max=0;
  long long i,j;
  long long p,q;
  long long n,m;
  scanf("%lld%lld",&n,&m);
  for(i=n;i<=m;i++)
   {
   	  for(j=n;j<=m;j++)
   	  {
   	  	sum=i^j;
           if(sum>max)	  
           {
           	max=sum;
		   }
	  }
	} 
	printf("%d",max);
}
