#include<stdio.h>
int main()
{
  int T,m,n,i,a;
  scanf("%d",&T);
  while(T--)
 {
	  scanf("%d%d",&n,&m);
	  a=n%(m+1);
	  if(a!=0)
		  printf("first\n");
	  else
		  printf("second\n");
         }
   return 0;
}