//prim by kuangbin
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int INF = 0x3f3f3f3f;
const int MAXN = 110;
bool vis[MAXN];
int lowc[MAXN];
int prime(int cost[][MAXN],int n){
	int ans = 0;
	memset(vis,false,sizeof(vis));
	vis[0] = true;
	for(int i=1;i<n;i++)
		lowc[i] = cost[0][i];
	for(int i=1;i<n;i++){
		int minc = INF;
		int p=-1;
		for(int j=0;j<n;j++){
			if(!vis[j]&&minc>lowc[j]){
				minc = lowc[j];
				p = j;
			}
		}
		if(minc == INF)
			return -1;
		ans += minc;
		vis[p] = true;
		for(int j=0;j<n;j++)
			if(!vis[j] && lowc[j] >cost[p][j])
				lowc[j] = cost[p][j];
	}
	return ans;
}
//kruskal
const int MAXN = 110;
const int MAXM = 10000;
int F[MANX];
struct Edge{
	int u,v,w;
}edge[MAXN];
int tol;
void addedge(int u,int v,int w){
	edge[tol].u=u;
	edge[tol].v=v;
	edge[tol].w=w;
}
bool cmp(Edge a,Edge b){
	return a.w<b.w;
}
int find(int x){
	if(F[x] == -1)
		return x;
	else return F[x] = find(F[x]);
}
int kruskal(int n){
	memset(F,-1,sizeof(F));
	sort(edge,edge+tol,cmp);
	int cnt = 0;
	int ans = 0;
	for(int i=0;i<tol;i++){
		int u = edge[i].u;
		int v = edge[i].v;
		int w = edge[i].w;
		int t1 = find(u);
		int t2 = find(v);
		if(t1 != t2){
			ans += w;
			F[t1] = t2;
			cnt++;
		}
		if(cnt == n-1)
			return -1;
		else return ans;
	}
}