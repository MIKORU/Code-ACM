#include <stdio.h>
#include <string.h>
#define N 1002
int main()
{
	int n,k,i,j,a[N],sum=0;
	
	while (scanf("%d%d",&n,&k)!=EOF)
	{
		a[0]=0;
		memset(a,0,sizeof(a));
		if (n==0)
			break;
		sum=0;
		for(i=1;i<=k;i++)
		{
			for(j=i;j<=n;j++)
			{
				if(j%i==0)
					a[j]++;
			}
		}
		for(j=1;j<=n;j++)
		{
			if(a[j]%2!=0)
				sum++;
		}
		printf("%d\n",sum);
	}
	return 0;
}

