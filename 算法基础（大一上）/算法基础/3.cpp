#include<malloc.h>
#include<string.h>
#include<stdlib.h>
#include <stdio.h>
main()
{
  //char *str[10]={"dhus","inds","jbcja","andj"};//�������û��/0�� ���ǻ���puts��ʱ��ֹͣ 
   char str[10][10]={"dhus","inds","jbcja","andj"};
   puts(str[1]+1);
   //puts((str[1]+5));
  //putchar(*(*(str+2)));
  /*char s[]={"bsfua"};
  char sw[]={'w','e','s','s'}; //�������û��/0�� ���ǻ���puts��ʱ��ֹͣ 
   puts(s);
   puts(sw);*/
   //char (*p)[10];
   //char *p;
   /*char a[10]="sdfsf";
    p=a;
   puts(p);*/
}
