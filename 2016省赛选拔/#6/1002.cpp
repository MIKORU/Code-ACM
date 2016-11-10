#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h> // 取绝对值
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>  //priority_queue<int>
#include <vector>
#include <map>
#include <set>
#include <utility> //pair类或者 typedef pair<int ,int>P;
#define LL long long
#define CAN(a,b) memset(a,b,sizeof(a))  //大数 memset(a,0x7f,sizeof(a));
#define M 25
const int INF = 0x3f3f3f3f;
using namespace std;
int a[M],b[M];
int mp[M][M],n,m;
int vis[M],ans;
bool judge(){
	for(int i=0;i<n;i++){
		int sum=0;
		for(int j=0;j<m;j++){
			if(vis[j])
			sum += mp[j][i];
		}
		if(sum < a[i])return false;
	}
	return true;
}
void dfs(int pos){
	if(pos == m){
		if(judge()){
			int tot=0;
			for(int i=0;i<m;i++)
				if(vis[i])tot++;
			if(ans < tot){
				ans = tot;
				for(int i=0;i<m;i++)
					b[i]=vis[i];
			}
		}
		return;
	}
	vis[pos]=1;
	dfs(pos+1);
	vis[pos]=0;
	dfs(pos+1);
}
int main()
{
	while(~scanf("%d",&n)){
		for(int i=0;i<n;i++)
			scanf("%d",&a[i]);
		scanf("%d",&m);
		for(int i=0;i<m;i++)
			for(int j=0;j<n;j++)
				scanf("%d",&mp[i][j]);
		memset(vis,0,sizeof(vis));
		memset(b,0,sizeof(b));
		ans=0;
		dfs(0);
		printf("%d",ans);
		for(int i=0;i<m;i++)
			if(b[i])printf(" %d",i+1);
		puts("");
	}
	return 0;
}
