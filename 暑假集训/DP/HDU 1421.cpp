#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <cstdio>
#define MAXN 10500
#define MAXP 10000
const int INF = 0x3f3f3f3f;
using namespace std;
int w[MAXN];
int n,k;
int dp[MAXN][MAXP];
void solve(){
	for(int i=1;i<=k;i++){
		for(int j = 1;2*j<i;j++){
            dp[i][j] = min(dp[i-1][j],dp[i-2][j-1]+w[i-1]);
		}
	}
	printf("%d\n",dp[n][k]);
}
int main()
{
	int n,k;
	while(~scanf("%d%d",&n,&k)){
		for(int i=1;i<n;i++){
			scanf("%d",&w[i]);
		}
		sort(w,w+n);
		memset(dp,INF,sizeof(dp));
		for(int i=1;i<n;i++){
			w[i] = (w[i+1]-w[i])*(w[i+1]-w[i]);
		}
		solve();
	}
	return 0;
}
