#include<stdio.h>
int  main()
 {
 long long l,r,t,w;
 while(scanf("%lld%lld",&l,&r)!=EOF)
 {  
   if(r==l)printf("0\n");
   else
   {    w=0;
       while(r!=l&&r!=0)//相等或最大值为0 结束                101011 
       {                //相等则证明 此位之前的异或不可能为1  101110 
          w++;
          l=l>>1;//从右向左移动 
          r=r>>1;
       }
        t=1;
       while(w--)t=t*2;
       printf("%lld\n",t-1); 
   }
 }
   return 0;
 }
