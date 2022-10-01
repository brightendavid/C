#include<malloc.h>
#include<string.h>
#include<stdlib.h>
#include <stdio.h>
#include <math.h>
void GetMemory(char *p);
void Test();
main()
{
  Test(); 
  printf("1");
}
void GetMemory(char *p)
{
    p = (char *)malloc(100);
    printf("2");
}
void Test(void)
{
    char *str = NULL;
    printf("3");
    GetMemory(str);
    strcpy(str, "hello world");
    printf("1");
    printf(str);
    printf("1");
    free(str);
}
