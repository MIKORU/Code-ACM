//�ڶ��⣺����a+b�����������ͣ�
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
