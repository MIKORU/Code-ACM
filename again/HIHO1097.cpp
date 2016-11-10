#include<cstdio>
#include<cstring>
using namespace std;
const int INF = 0x3f3f3f3f;
const int MAXN = 1005;
int N;
int vis[MAXN];
int cost[MAXN];
int maps[MAXN][MAXN];
int prim(int n){
	int ans = 0;
	memset(vis,0,sizeof(vis));
	vis[0] = true;
	for(int i=1;i<n;i++){
		cost[i] = maps[0][i];
	}
	for(int i=1;i<n;i++){
		int minc = INF;
		int p = -1;
		for(int j=0;j<n;j++){
			if(!vis[j]&&minc>cost[j]){
				minc = cost[j];
				p = j;
			}
		}
		if(p==-1) return -1;
		ans+=minc;
		vis[p] = true;
		for(int j=0;j<n;j++){
			if(!vis[j]&&cost[j]>maps[p][j]) {
				cost[j] = maps[p][j];
			}
		}
	}
	return ans;
}
int main(){
	while(~scanf("%d",&N)){
		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++){
				scanf("%d",&maps[i][j]);
			}
		}
		printf("%d\n",prim(N));
	}
}
