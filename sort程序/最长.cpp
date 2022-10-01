#include<malloc.h>
#include<string.h>
#include<stdlib.h>
#include <stdio.h>
#include <math.h>
int lengthOfLongestSubstring(char * s);
main()
{
  char s[10000];
  scanf("%s",s);
  int sum=0;
  sum=lengthOfLongestSubstring(s);
  printf("%d",sum);
}
int lengthOfLongestSubstring(char * s){
    char *rear,*head,*p;
    int first,fin; 
    int t=1;
    int maxsize=0;
    rear=s+1;
    head=s;
    if(*rear=='\0')
    {
        return 1;
    }
    if(*head=='\0')
    {
        return 0;
    }
    while(*head!='\0'&&*rear!='\0')
    {
   
        
        for(p=head;p<=rear-1;p++)
        {
            if(*p==*rear)//若有相同则移动到相同字符后一位 
            {
                head=p+1;
                break;
            }
        }
		if(rear-head+1>maxsize)
        {
            maxsize=rear-head+1;
             first=head-s;
            fin=rear-s;
            if(*head==*rear)
            {
            	maxsize=1;
			}
        }
        if(p==rear)//若不同则REAR移动后一位
        {
            rear++;
        }
    }
   printf("%d %d\n",first+1,fin+1);
    return maxsize;
}
