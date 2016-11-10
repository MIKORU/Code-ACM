#include <stdio.h>
#include <string.h>
#define N 100
int a[N][N];
int main()
{
	int n,x,y,t=0,s=1;
	while (scanf("%d",&n)!=EOF)
	{
		memset(a,0,sizeof(a));
		t=a[x=0][y=0]=1;
		while(t<n*n)
		{
			while(y+1<n&&!a[x][y+1]) a[x][++y]=++t;
			while(x+1<n&&!a[x+1][y]) a[++x][y]=++t;
			while(y-1>=0&&!a[x][y-1]) a[x][--y]=++t;
			while(x-1>=0&&!a[x-1][y]) a[--x][y]=++t;
		}
		printf("Case #%d:\n",s);
		s++;
		for(x=0;x<n;x++)
		{
			for(y=0;y<n;y++)
			{
				if(y==n-1)
					printf("%d",a[x][y]);
				else
					printf("%d ",a[x][y]);			
			}
			putchar('\n');
		}
	}
		return 0;
}
