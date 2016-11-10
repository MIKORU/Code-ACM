//最短路模板
//多源
for(int k=1;k<=n;k++)
	for(int i=1;i<=n;i++)
		for(int j = 1;j<=n;j++){
			e[i][j] = min(e[i][j],e[i][k]+e[k][j]);
		}
//单源最短路dijkstra
int d[MAXN],cost[MAXN][MAXN],V;
bool used[MAXN];
int path[MAXN];
void init(){
	int i,j;
	for(int i=1;i<=V;i++)
		for(int j=1;j<=V;j++)
			cost[i][j] = INF;
}
void dijkstra(int s){ //s表示起点 V表示顶点数
	fill(d,d+V,INF);
	fill(used,used+V,false);
	//对d[i]要有初始化
	for(int i=1;i<=V;i++){
		d[i] = cost[s][i];
		path[i] = s;
	}
	path[s] = -1;
	d[s] = 0;
	used[s] = 1;
	while(true){
		int v ,mins = INF;
		for(int i=1;i<=V;i++){//d[i]表当前点距离
			if(!used[i] && d[i] < mins)
				mins = d[i],v = i;
		}
		if(mins == INF) break;
		used[v] = true;
		for(int i=1;i<=V;i++){//当前点到其他顶点的距离
			if(!used[i]){
				d[i] = min(d[i],d[v]+cost[v][i]);
				path[i] = v;
			}
		}
	}
}
//dij by kuangbin
const int MAXN = 1010;
#define typec int
const typec INF = 0x3f3f3f3f;
bool vis[MAXN];
int pre[MAXN];
void Dijkstra(typec const[][MAXN],typec lowcost[],int n,int beg){
	for(int i=0;i<n;i++){
		lowcost[i] = INF;
		vis[i] = false;
		pre[i] = -1;
	}
	lowcost[beg] = 0;
	for(int j=0;j<n;j++){
		int k =-1;
		int Min = INF;
		for(int i=0;i<n;i++){
			if(!vis[i] && lowcost[i]<Min){
				Min = lowcost[i];
				k = i;
			}
		}
		if(k == -1) break;
		vis[k] = true;
		for(int i=0;i<n;i++){
			if(!vis[i] && lowcost[k] +cost[k][i]<lowcost[i]){
				lowcost[i] = lowcost[k] + cost[k][i];
				pre[i] = k;
			}
		}
	}
}
//优化STL
struct edge{
	int to,cost;
};
typedef pair<int ,int >P;
int V;
vector<edge>G[MAXN];
int d[MAXN];
void dijkstra(int s){
	poiority_queue<P,vector<P>,greater<P> >que;
	fill(d,d+V,INF);
	que.push(P(0,s));
	while(!que.empty()){
		P p = que.top();
		que.pop();
		int v = p.second;
		if(d[v] < p.first)
			continue;
		for(int i=0;i<G[v].size();i++){
			egde e = G[v][i];
			if(d[e.to] > d[v] +e.cost){
				d[e.to] = d[v] +e.cost;
				que.push(P(d[e.to],e.to));
			}
		}
	}
}
//bellman-ford
struct edge{
	int from,to,cost;
};
edge es[MAXN];
int d[MAXN];
int V,E;
void shortest_path(int s){
	for(int i=0;i<V;i++)
		d[i] = INF;
	d[s] = 0;
	while(true){
		bool update = false;
		for(int i=0;i<E;i++){
			egde e = es[i];
			if(d[e.from] !=INF&&d[e.to]>d[e.from]+e.cost){
				d[e.to] = d[e.from] + e.cost;
				update = true;
			}
		}
		if(!update)
			break;
	}
}
//优化Bellman
struct son{
	int v,w;
};
vector<son> g[MAXN];
bool used[MAXN];
int d[MAXN],V;
void init(){
	for(int i=1;i<=n;i++)
		g[i].clear();
}

void spaf(int u){
	int i,v,w;
	for(int i=1;i<=n;i++){
		d[i] = inf;
		used[i] = false;
	}
	queue<int>q;
	q.push(u);
	used[u] = true;
	d[u] = 0;
	while(!q.empty()){
		u = q.front();
		q.pop();
		used[u] = false;
		for(int i=0;i<g[u].size();i++){
			v = g[u][i].v;
			w = g[u][i].w;
			if(d[u]+w<d[v]){
				d[v] = d[u]+w;
				if(!used[v]){
					q.push(v);
					used[v] = true;
				}
			}
		}
	}
}
//by kuangbin
const int MAXN = 1020;
const int INF = 0x3f3f3f3f;
struct Edge{
	int v,cost;
	Edge(int _v=0,int _cost=0):v(_v),cost(_cost){}
};
vector<Edge> E[MAXN];
void addedge(int u,int v,int W){
	E[u].push_back(Edge(v,w));
}
bool vis[MAXN];
int cnt[MAXN]; //the count of q.push
int d[MAXN];
bool SPFA(int s,int V){
	memset(vis,flase,sizeof(vis));
	for(int i=1;i<=V;i++)
		d[i] = INF;
	vis[s] = true;
	d[s] = 0;
	queue<int> que;
	while(!que.empty())
		que.pop();
	queue.push(s);
	memset(cnt,0,sizeof(cnt));
	cnt[s] = 1;
	while(!que.empty()){
		int u = que.fornt();
		que.pop();
		for(int i=0;i<E[u].size();i++){
			int v = E[u][i].v;
			d[v] = min(d[v],d[u]+E[u][i].cost)
			if(!vis[v]){
				vis[v] = true;
				que.push(v);
				if(++cnt[v]>V) return false;
			}
		}
	}
	return true;
}
