#include<stdio.h>
int  main()
 {
 long long l,r,t,w;
 while(scanf("%lld%lld",&l,&r)!=EOF)
 {  
   if(r==l)printf("0\n");
   else
   {    w=0;
       while(r!=l&&r!=0)//��Ȼ����ֵΪ0 ����                101011 
       {                //�����֤�� ��λ֮ǰ����򲻿���Ϊ1  101110 
          w++;
          l=l>>1;//���������ƶ� 
          r=r>>1;
       }
        t=1;
       while(w--)t=t*2;
       printf("%lld\n",t-1); 
   }
 }
   return 0;
 }
