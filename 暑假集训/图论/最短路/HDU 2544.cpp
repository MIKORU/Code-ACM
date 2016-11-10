///GOJ 1209
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int N,M;
const int MAXN = 1010;
const int INF = 0x3f3f3f3f;
int d[MAXN];
bool used[MAXN];
int cost[MAXN][MAXN];
void dijkstra(int s,int V){ //s表示起点 V表示顶点数
	fill(d,d+V,INF);
	fill(used,used+V,false);
	for(int i=1;i<=V;i++){ //初始化d作为起点1到其他点的距离
        d[i] = cost[1][i];
	}
	d[s] = 0;
	while(true){
		int v = -1;
		for(int i=1;i<=V;i++){//d[i]表当前点距离
			if(!used[i] && (v == -1||d[i]<d[v]))
				v = i;
//				printf("%d\n",v);
		}
		if(v == -1) break;
		used[v] = true;
		for(int i=1;i<=V;i++){//当前点到其他顶点的距离
			d[i] = min(d[i],d[v]+cost[v][i]);
//			printf("d[%d] = %d\n",i,d[i]);
		}
	}
	printf("%d\n",d[N]);
}
int main(){
	while(~scanf("%d%d",&N,&M)&&(N+M)){
        for(int i=1;i<=N;i++)
            for(int j=1;j<=N;j++){
                if(i==j) cost[i][j] = 0;
                else cost[i][j] = cost[j][i]=INF;
            }
		for(int i=0;i<M;i++){
			int a,b,c;
			scanf("%d%d%d",&a,&b,&c);
			cost[a][b] = cost[b][a] = c;
		}
		dijkstra(1,N);
	}
	return 0;
}
