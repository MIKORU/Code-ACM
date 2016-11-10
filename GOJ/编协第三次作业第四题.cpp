#include<stdio.h>
int main()
{
 int i,m,t;
 char s[1000];
 while(scanf("%s",s)&&s[0]!='0')
 {
   for(m=i=0;s[i];i++)
     m+=s[i]-'0';
   if(m%9==0)
	   t=9;
   else
	   t=m%9;
 printf("%d\n",t); 
 }
 return 0;
}
