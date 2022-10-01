#include<malloc.h>
#include<string.h>
#include<stdlib.h>
#include <stdio.h>
main()
{
  int i,j;
  int n; 
  char s[100];
  
  int m;
  while(scanf("%d",&n)!=EOF)
  { 
      int t=0; 
	  while(n>0)
	  {
	  	scanf("%d",&m);
	  	if(m==17)
	  	{
	  		s[t]='S';
		  }
		  else if(m==6)
		  {
		  	s[t]='D';
		  }
		  else if(m==9) 
		  {
		  	s[t]='K';
		  }
		  else if(m==8)
		  {
		  	s[t]='J';
		  }
		  else if(m==3)
		  {
		  	s[t]='A';
		   } 
		   else if(m==0)
		   {
		   	s[t]='B';
		   }
		   else if(m==1)
		   {
		   	s[t]='C';
		   }
		   else if(m==6)
		   {
		   	s[t]='D';
		   }
		   else if(m==7)
		   {
		   	s[t]='E';
		   }
		   else if(m==4)
		   {
		   	s[t]='F';
		   }
		    else if(m==5)
		   {
		   	s[t]='G';
		   }
		    else if(m==10)
		   {
		   	s[t]='H';
		   }
		    else if(m==11)
		   {
		   	s[t]='I';
		   } 
		   else if(m==8)
		   {
		   	s[t]='J';
		   } 
		   else if(m==9)
		   {
		   	s[t]='K';
		   } 
		   else if(m==14)
		   {
		   	s[t]='L';
		   }
		    else if(m==15)
		   {
		   	s[t]='M';
		   }
		    else if(m==12)
		   {
		   	s[t]='N';
		   }
		    else if(m==13)
		   {
		   	s[t]='O';
		   }
		    else if(m==18)
		   {
		   	s[t]='P';
		   }
		    else if(m==19)
		   {
		   	s[t]='Q';
		   }
		    else if(m==16)
		   {
		   	s[t]='R';
		   }
		    else if(m==17)
		   {
		   	s[t]='S';
		   } else if(m==22)
		   {
		   	s[t]='T';
		   } 
		   else if(m==23)
		   {
		   	s[t]='U';
		   }
		    else if(m==20)
		   {
		   	s[t]='V';
		   }
		    else if(m==21)
		   {
		   	s[t]='W';
		   }
		    else if(m==26)
		   {
		   	s[t]='X';
		   }
		    else if(m==27)
		   {
		   	s[t]='Y';
		   }
		    else if(m==24)
		   {
		   	s[t]='Z';
		   }
		   t++;
		 n--;
	   }
	   s[t]='\0';
	   puts(s);
	  
  }
 
 
}
