#include <stdio.h>
int main()
{
	int N,T,sum,m,n;
	while (scanf("%d",&T)!=EOF)
	{
		if(T==0)
			break;
		sum=n=0;
		while (T--)
		{
			scanf("%d",&m);
			if(m>n)
				sum+=6*(m-n)+5;
			else
				sum+=4*(n-m)+5;
			n=m;
		}
		printf("%d\n",sum);
	}
	return 0;
}