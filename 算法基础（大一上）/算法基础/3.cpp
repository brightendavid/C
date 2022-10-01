#include<malloc.h>
#include<string.h>
#include<stdlib.h>
#include <stdio.h>
main()
{
  //char *str[10]={"dhus","inds","jbcja","andj"};//这个后面没有/0的 但是会在puts的时候停止 
   char str[10][10]={"dhus","inds","jbcja","andj"};
   puts(str[1]+1);
   //puts((str[1]+5));
  //putchar(*(*(str+2)));
  /*char s[]={"bsfua"};
  char sw[]={'w','e','s','s'}; //这个后面没有/0的 但是会在puts的时候停止 
   puts(s);
   puts(sw);*/
   //char (*p)[10];
   //char *p;
   /*char a[10]="sdfsf";
    p=a;
   puts(p);*/
}
