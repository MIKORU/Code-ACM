#include <stdio.h>
int main()
{
     long long i,a[60],n; 
     a[0]=0;
	 a[1]=3;
	 a[2]=a[3]=6;
     for(i=4;i<=50;i++) 
         a[i]=a[i-1]+2*a[i-2]; 
     while(scanf("%lld",&n)!=EOF)
     {
         printf("%lld\n",a[n]);
     } 
     return 0; 
}
