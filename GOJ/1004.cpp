#include <stdio.h>
#include <math.h>
#define N 10000
int main()
{
	int n,i,j,c[N],s,p,sum;
	while (scanf("%d",&n)!=EOF)
	{
		sum=s=0;
		if(n==0)
			break;
		for(i=2;i<=n-2;i++)
		{
			p=0;
			for(j=2;j<=sqrt(i);j++)
			{
				if(i%j==0)
				{
					p = 1;
					break;
				}
			}
			if(p==0)
			{
				c[s++] = i;
			}
		}
		for(i=0;i<s;i++)
		{
			for(j=i+1;j<s;j++)
			{
				if(c[i]+c[j]==n)
				sum++;
			}
		}
    printf("%d\n",sum);
   }
   return 0;
}