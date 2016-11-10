#include <stdio.h>
#include <string.h>
#define N 50005
int main()
{
	int n,a[N],p,i,j;
	while (scanf("%d",&n)!=EOF)
	{
		memset(a,0,sizeof(a));
		if (n == 0)
			break;
		for (i=0;i<(2*n-1);i++)
		{
			scanf("%d",&p);
			a[p]++;
		}
		for (p=0;p<=N;p++)
		{
			if(a[p]==1)
			printf("%d\n",p);
		}					
	}
	return 0;
}