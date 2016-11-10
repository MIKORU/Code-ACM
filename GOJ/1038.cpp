#include<stdio.h>
int main()
{int T,a[31],n,i;
a[0]=4;

scanf("%d",&T);
while(T--)
{
scanf("%d",&n);
for(i=0,i<n+1,i++)
a[i+1]=(a[i]-1)*2;
printf("%d\n",a[n]);
	}

return 0;
}