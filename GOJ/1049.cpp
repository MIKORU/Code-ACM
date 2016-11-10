#include <stdio.h>
#define N 5005
int g(int x)
{
	int sum=0,i;
	for (i=1;i<x;i++)
		if (x%i==0)
			sum++;
		return sum;
}
int main()
{
	int T,a,b,i,j,s,max,c[N];
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d%d",&a,&b);
		for (i=a,j=0;i<=b;i++,j++)
		{
			c[j]=g(i);
		}
		max=c[0];
		s = a;
		for(i=0;i<j;i++)
		{
			if (c[i]>max)
			{
				max=c[i];
				s = i+a;
			}
		}
		printf("%d\n",s);
	}
	return 0;
}
