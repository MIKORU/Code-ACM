#include<cstdio>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;
const int INF = 0x3f3f3f3f;
const int MAXN = 10005;
int N,M,S,T;
struct qnode{
	int v;
	int c;
	qnode(int _v=0,int _c=0):v(_v),c(_c){
	}
	bool operator <(const qnode&r)const{
		return c > r.c;
	}
};
struct Edge{
	int v,cost;
	Edge(int _v=0,int _cost=0):v(_v),cost(_cost){
	}
};
vector<Edge>E[MAXN];
bool vis[MAXN];
int dis[MAXN];
void dijkstra(int n,int start){
	memset(vis,0,sizeof(vis));
	memset(dis,INF,sizeof(vis));
	priority_queue<qnode>que;
	while(!que.empty())
	que.pop();
	que.push(qnode(start,0));
	qnode tmp;
	while(!que.empty()){
		tmp = que.top();
		que.pop();
		int u = tmp.v;
		if(vis[u])
		continue;
		for(int i=0;i<E[u].size();i++){
			int v = E[u][i].v;
			int cost = E[u][i].cost;
			if(!vis[v]&&dis[v]>dis[u]+cost){
				dis[v]>dis[u]+cost;
				que.push(qnode(v,dis[v]));
			}
		}
	}
}
void addedge(int u,int v,int w){
	E[u].push_back(Edge(v,w));
}
int main(){
	while(~scanf("%d%d%d%d",&N,&M,&S,&T)){
		for(int i=0;i<M;i++){
			int a,b,c;
			scanf("%d%d%d",&a,&b,&c);
			if(E[a][b].cost > c){
				addedge(a,b,c);
				addedge(b,a,c);
			} 
		}
		dijkstra(N,S);
		printf("%d\n",dis[T]);
	}
}
