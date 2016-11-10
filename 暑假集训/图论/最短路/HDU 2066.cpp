///虽然HDU上有正确代码，但是我自己写的怎么都不过，我也是醉了
//#include <cstdio>
//#include <cstring>
//#include <algorithm>
//#include <vector>
//#include <queue>
//using namespace std;
//const int INF = 0x3f3f3f3f;
//const int MAXN = 1010;
//int T,S,D;
//struct edge{
//	int to,cost;
//	edge(){}
//	edge(int a,int b){
//	    to = a;
//	    cost = b;
//	}
//};
//typedef pair<int ,int > P;
//int V;
//vector<edge>G[MAXN];
//int d[MAXN];
//int start[MAXN],lasts[MAXN];
//void dijkstra(int s){
//	priority_queue<P,vector<P>,greater<P> >que;
//	fill(d,d+V,INF);
//	que.push(P(0,s));
//	while(!que.empty()){
//		P p = que.top();
//		que.pop();
//		int v = p.second;
//		if(d[v] < p.first)
//			continue;
//		for(int i=0;i<G[v].size();i++){
//			edge e = G[v][i];
//			if(d[e.to] > d[v] +e.cost){
//				d[e.to] = d[v] +e.cost;
//				que.push(P(d[e.to],e.to));
//			}
//		}
//	}
//}
//int main(){
//	while(~scanf("%d%d%d",&T,&S,&D)){
//		V = 0;
//		int minn = INF;
//		for(int i=0;i<MAXN;i++)
//			G[i].clear();
//		for(int i=1;i<=T;i++){
//			int a,b,time;
//			scanf("%d%d%d",&a,&b,&time);
//			G[a].push_back(edge(b,time));
//			G[b].push_back(edge(a,time));
//			V = max(V,max(a,b));
//		}
//		for(int i=1;i<=S;i++){
//			scanf("%d",&start[i]);
//		}
//		for(int i=1;i<=D;i++){
//			scanf("%d",&lasts[i]);
//		}
//		for(int i=1;i<=S;i++){
//			dijkstra(start[i]);
//			for(int j=1;j<=D;j++){
//				minn = min(minn,d[lasts[j]]);
//			}
//		}
//		printf("%d\n",minn);
//	}
//	return 0;
//}
//#include <cstdio>
//#include <cstring>
//#include <algorithm>
//#include <vector>
//#include <queue>
//using namespace std;
//const int INF = 0x3f3f3f3f;
//const int MAXN = 1020;
//int T,S,D,V;
//int cost[MAXN][MAXN];
//int d[MAXN];
//bool used[MAXN];
//int start[MAXN],last[MAXN];
//void dijkstra(int s){ //s表示起点 V表示顶点数
//	fill(d,d+V,false);
//	fill(used,used+V,false);
//	//对d[i]要有初始化
//	for(int i=1;i<=V;i++)
//		d[i] = cost[s][i];
//	d[s] = 0;
//	used[s] = 1;
//	while(true){
//		int v ,mins = INF;
//		for(int i=1;i<=V;i++){//d[i]表当前点距离
//			if(!used[i] && d[i] < mins)
//				mins = d[i],v = i;
//		}
//		if(mins == INF) break;
//		used[v] = true;
//		for(int i=1;i<=V;i++){//当前点到其他顶点的距离
//			if(!used[i])
//				d[i] = min(d[i],d[v]+cost[v][i]);
//		}
//	}
//}
//int main(){
//	while(~scanf("%d%d%d",&T,&S,&D)){
//	    memset(start,0,sizeof(start));
//        memset(last,0,sizeof(last));
//		V = 0;
//		int ans = INF,minn;
//		for(int i=0;i<MAXN;i++)
//            for(int j=0;j<MAXN;j++){
//                if(i==j) cost[i][j] = cost[j][i] = 0;
//                else cost[i][j]  = INF;
//            }
//		for(int i=0;i<T;i++){
//			int a,b,time;
//			scanf("%d%d%d",&a,&b,&time);
//			if(time < cost[a][b])
//                cost[a][b] = cost[b][a] = time;
//			V = max(V,max(a,b));
//		}
//		for(int i=1;i<=S;i++){
//			scanf("%d",&start[i]);
//		}
//		for(int i=1;i<=D;i++){
//			scanf("%d",&last[i]);
//		}
//
//		for(int i=1;i<=S;i++){
//			dijkstra(start[i]);
//			for(int j=1;j<=D;j++){
//				ans = min(ans,d[last[j]]);
//			}
//		}
//		printf("%d\n",ans);
//	}
//	return 0;
//}
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;
const int MAXN = 1020;
const int INF = 0x3f3f3f3f;

int T,S,D,V;

int start[MAXN];
int last[MAXN];

struct Edge{
	int v,cost;
	Edge(int _v=0,int _cost=0):v(_v),cost(_cost){}
};
vector<Edge> E[MAXN];
void addedge(int u,int v,int w){
	E[u].push_back(Edge(v,w));
}
bool vis[MAXN];
//int cnt[MAXN]; //the count of q.push
int d[MAXN];
void init(){
	for(int i=0;i<MAXN;i++)
		for(int j=0;j<MAXN;j++){
			if(i==j) addedge(i,j,0);
			else addedge(i,j,INF);
		}
}
int SPFA(){
	memset(vis,false,sizeof(vis));
	for(int i=1;i<=V;i++)
		d[i] = INF;
	queue<int> que;
	for(int i=1;i<=S;i++){
        d[start[i]] = 0;
        que.push(start[i]);
        vis[start[i]] = true;
	}

//	memset(cnt,0,sizeof(cnt));
//	cnt[s] = 1;
	while(!que.empty()){
		int u = que.front();
		que.pop();
		for(int i=0;i<E[u].size();i++){
			int v = E[u][i].v;
			d[v] = min(d[v],d[u]+E[u][i].cost);
			if(!vis[v]){
				vis[v] = true;
				que.push(v);
//				if( ++cnt[v] > V)
//                    return false;
			}
		}
	}
	int MIN = INF;
	for(int i=1;i<=D;i++)
        MIN = min(MIN,d[last[i]]);
    return MIN;
//	return true;
}
int main(){

	while(~scanf("%d%d%d",&T,&S,&D)){
		init();
		V = 0;
		int ans=INF;
		for(int i=1;i<=T;i++){
			int a,b,t;
			scanf("%d%d%d",&a,&b,&t);
			if(t < E[a][b].cost){
				addedge(a,b,t);
				addedge(b,a,t);
			}
			V = max(V,max(a,b));
		}
		for(int i=1;i<=S;i++){
			scanf("%d",&start[i]);
		}
		for(int i=1;i<=D;i++){
			scanf("%d",&last[i]);
		}
		printf("%d\n",SPFA());
	}
	return 0;
}
