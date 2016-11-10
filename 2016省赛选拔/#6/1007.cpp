#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
double a[60];
int b[60];
int ans,n;
int vis[60];
void dfs(double sum,int cnt,int cost)
{
	int cur=(int)sum;
	if(sum-cur==0 && cur%5==0)
		ans=max(ans,cost);
	if(cnt==3)
		return ;
	for(int i=0;i<n;i++)
	{
		if(vis[i])
			continue;
		vis[i]=1;
		dfs(sum+a[i],cnt+1,cost+b[i]);
		vis[i]=0;
	}
}
int main()
{
    while(~scanf("%d",&n)){
		ans=0;
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(vis,0,sizeof(vis));
		for(int i=0;i<n;i++){
			scanf("%lf%d",&a[i],&b[i]);
		}
		dfs(0,0,0);
		printf("%d\n", ans);
	}
}
