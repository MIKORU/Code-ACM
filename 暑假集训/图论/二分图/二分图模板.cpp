//邻接矩阵
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
const int MAXN = 510;
int uN,vN;
int g[MAXN][MAXN];
int linker[MAXN];
bool used[MAXN];
bool dfs(int u){
	for(int v=0;v<vN;v++){
		if(g[u][v] && !used[v]){
			used[v] = true;
			if(linker[v] ==-1 || dfs(linker[v])){
				linker[v] = u;
				return true;
			}
		}
	}
	return false;
}
int hungary(){//最大匹配
	int res = 0;
	memset(linker,-1,sizeof(linker));
	for(int u=0;u<uN;u++){
		memset(used,false,sizof(used));
		if(dfs(u))
			res++;
	}
}
//bfs
struct Edge{
	int from;
	int to;
	int weight;
	Edge(int f,int t,int w):from(f),to(t),weight(w){}
};
vector <int> G[_maxNodes];
vector <Edge> edges;
typedef vector<int>::iterator it;//iterator_t
int num_nodes;
int num_left;
int num_right;
int num_edges;
int matching[_maxNodes];
int check[_maxNodes];
queue <int> Q;
int prev[_maxNodes];
int Hungary(){
	int ans = 0;
	memset(matching,-1,sizeof(matching));
	memset(check,-1,sizeof(check));
	for(int i=0;i<num_left;i++){
		if(matching[i] == -1){
			while(!Q.empty())
				Q.pop();
			Q.push(i);
			prev[i] = -1;
			bool flag = false;
			while(!Q.empty()&&!flag){
				int u = Q.front();
				for(it i=G[u].begin();i!=G[u].end()&&!flag;i++){
					int v = edges[*i].to;
					if(check[v]!=i){
						check[v] = i;
						Q.push(matching[v]);
						if(matching[v]>=0){
							prev[matching[v] = u;
						}
						else{
							flag = true;
							int d = u,e = v;
							while(d!=-1){
								int t = matching[d];
								matching[d] = e;
								matching[e] = d;
								d = prev[d];
								e = t;
							}
						}
					}
				}
				Q.pop();
			}
			if(matching[i] != -1) ++ans;
		}
	}
	return ans;
}