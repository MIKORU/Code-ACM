#include<cstdio>
#include<cstring>
const int MAXN = 1005;
const int INF = 0x3f3f3f3f;
int cost[MAXN][MAXN];
int N,M,S,T;
int dis[MAXN];
bool vis[MAXN];
void dijkstra(int n,int start){
	for(int i=1;i<=n;i++){
		dis[i] = INF;
	}
	dis[start] = 0;
	for(int i=1;i<=n;i++){
		int k = -1;
		int minn = INF;
		for(int j=1;j<=n;j++){
			if(!vis[j]&&dis[j]<minn){
				minn = dis[j];
				k = j;
			}
		}
		if(k==-1) break;
		vis[k] = true;
		for(int j=1;j<=n;j++){
			if(!vis[j]&&dis[j] > dis[k]+cost[k][j]){
				dis[j] = dis[k]+cost[k][j];
			}
		}
	}
}
int main(){
	while(~scanf("%d%d%d%d",&N,&M,&S,&T)){
		memset(vis,0,sizeof(vis));
		memset(cost,INF,sizeof(cost));
		for(int i=0;i<M;i++){
			int a,b,c;
			scanf("%d%d%d",&a,&b,&c);
			if(c<cost[a][b]){
				cost[a][b] = cost[b][a] = c;
			}
		}
		dijkstra(N,S);
		printf("%d\n",dis[T]); 
	}
}
