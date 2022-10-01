#include<malloc.h>
#include<string.h>
#include<stdlib.h>
#include <stdio.h>
#include<string.h>
int search(char *a,char *b);
int min(int x,int y);
main()
{
  int i,j;
  int sum=0; 
  char ss[1024];
  char a[1024],b[1024];
   while(scanf("%s%s",a,b)!=EOF)
   {
   	sum=0;
   	if(strlen(a)>strlen(b))//a一定要小与b的长度 
   	{
   		strcpy(ss,a);
   		strcpy(a,b);
   		strcpy(b,ss);
	}
	//printf("%s %s\n",a,b);
	//printf("%d %d\n",strlen(a),strlen(b));
	//max=strlen(b);
   	  sum=search(a,b);
   	 // printf("1");
   	  printf("%d\n",sum); 
   }
}
int search(char *a,char *b)
{
	int sum=0;
	char *p;
//	printf("%c %c\n",*a,*b);
	if((*a)=='\0'&&(*b)=='\0')
	{
		return sum;
	}
	if((*a)=='\0')
	{
		for(p=b;(*p)!='\0';p++)
		{
			sum++;
		}
		return sum;
	}
	if((*b)=='\0')
	{
		for(p=a;*p!='\0';p++)
		{
			sum++;
		} 
		return sum;
	}
	if((*a)!=(*b))
	{
		sum=min(search(++a,++b),min(search(++a,b),search(a,++b)))+1;
	}
    else
    {	
	//   printf("ke\n");
    	sum=search(++a,++b);
	}
	/*if(sum>max)
	{
		return ;
	}*/
	return sum;
}
int min(int x,int y)
{
	if(x<y)
	{
	//	printf("huan\n");
		return x;
	}
	else
	{
	//	printf("jia\n");
		return y;
	}
}
