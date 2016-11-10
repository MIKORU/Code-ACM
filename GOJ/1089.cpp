#include <stdio.h>
#include <algorithm>
#define N 100005
using namespace std;
int main()
{
	int n,i=0,a[N];
	while(scanf("%d",&n)!=EOF)
	{
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		sort(a,a+n);
		for(i=n-1;i>=0;i--)
		{
			if(a[i]<a[i-1]+a[i-2])
			{
				printf("%d\n",a[i]+a[i-1]+a[i-2]);
				break;
			}
		}
		if(i==-1)
			printf("0\n");
	}
	return 0;
}
