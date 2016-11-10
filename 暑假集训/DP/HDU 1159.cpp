#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <cstdio>
#define MAXN 10500
#define MAXP 10000
const int INF = -0xfffffff;
using namespace std;
int n,m;
int dp[MAXN+1][MAXP+1];
char s[MAXN],t[MAXP];
void solve(){
	n = strlen(s);
	m = strlen(t);
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(s[i] == t[j]){
				dp[i+1][j+1] = dp[i][j]+1;
			}
			else dp[i+1][j+1] = max(dp[i][j+1],dp[i+1][j]);
		}
	}
	printf("%d\n",dp[n][m]);
}
int main()
{
	while(~scanf("%s%s",s,t)){
		solve();
	}
	return 0;
}
