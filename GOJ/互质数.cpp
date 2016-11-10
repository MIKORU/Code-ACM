#include <stdio.h>
int gcd(int a,int b)
{
	return b==0?a:gcd(b,a%b);
}
int main()
{
	int N,i,t,sum;
	{while (scanf("%d",&N)!=EOF)
	{
		sum=0;
		for (i=0;i<N;i++)
		{
			if(gcd(N,i)==1)
			sum+=1;
		}
		printf("%d\n",sum);
	}
	}
return 0;
}
