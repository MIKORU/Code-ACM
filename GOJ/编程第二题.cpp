//第二题：计算a+b（多个数字求和）
#include<stdio.h>
int main()
{int N,n,i,m,sum=0;
	scanf("%d",&N);
	while(N--)
	{
		scanf("%d",&n);
		sum=0;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&m);
			sum+=m;
		}
		printf("%d\n",sum);
	}
	return 0;
}
