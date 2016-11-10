#include <stdio.h>
int yanghuisanjiao(int a[35][35],int n)
{
	int i,j;
	for (i=0;i<n;i++)
	{
		a[i][0]=1;
		a[i][i]=1;
	}
	for(i=2;i<n;i++)
		for(j=1;j<i;j++)
			a[i][j]=a[i-1][j-1]+a[i-1][j];
		return 0;
}
int main()
{
	int n,b[35][35],i,j;
	while(scanf("%d",&n)!=EOF)
	{
		if (n==0)
			break;
		yanghuisanjiao(b,n);
		for(i=0;i<n;i++)
		{
			for(j=0;j<=i;j++)
				printf("%d ",b[i][j]);
			putchar('\n');
		}
	putchar('\n');
	}
	return 0;
}