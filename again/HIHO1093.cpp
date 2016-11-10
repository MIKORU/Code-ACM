#include<cstdio>
#include<cstring>
#include<stack>
#include<vector>
#include<queue>
using namespace std;
const int MAXN = 10000000;
int N,M,S,T;
int num ;
int head[MAXN];
const int INF = 0x3f3f3f3f;
struct Edge{
	int v;
	int cost;
	int next;
};
Edge edge[MAXN];
void addedge(int u,int v,int w){
	edge[num].v = v;
	edge[num].cost = w;
	edge[num].next = head[u];
	head[u] = num++;
}
bool vis[MAXN];
int cnt[MAXN];
int dis[MAXN];
void SPFA(int start,int n){

	memset(vis,0,sizeof(vis));
	memset(dis,INF,sizeof(dis));
	vis[start] = true;
	dis[start] = 0;
	queue<int>S;
	while(!S.empty())S.pop();
	S.push(start);
	memset(cnt,0,sizeof(cnt));
	while(!S.empty()){
		int u = S.front();
		S.pop();
		vis[u] = 0;
		for(int i=head[u];i!=-1;i= edge[i].next){
			int v = edge[i].v;
			if(dis[v]>dis[u]+edge[i].cost){
				dis[v]=dis[u]+edge[i].cost;
				if(!vis[v]){
					vis[v] = true;
					S.push(v);
				}
			}
		}
	}
}
int main(){
	while(~scanf("%d%d%d%d",&N,&M,&S,&T)){
	memset(head,-1,sizeof(head));
		num = 0;
		for(int i=0;i<M;i++){
			int a,b,c;
			scanf("%d%d%d",&a,&b,&c);
				addedge(a,b,c);
				addedge(b,a,c);
		}
		SPFA(S,N);
			 printf("%d\n",dis[T]);
	}
	return 0;
}
