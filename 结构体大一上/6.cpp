#include<string.h>
#include <stdio.h>
main()
{
  int n;
  int bol=0;
  int i,j;
  while(scanf("%d",&n)!=EOF)
   {

  	bol=0;
  	for(i=1;i<=n;i++)
  	{
  		if(n%i==0)
  		{
  			bol=1-bol;
  			//	printf("1");
		}
	//	printf("1");
	}
//	printf("\n");
	  printf("%d\n",bol);
    }
}
