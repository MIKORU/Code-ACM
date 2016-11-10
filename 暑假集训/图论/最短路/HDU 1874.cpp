///虽然水，但是有坑Orz
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int INF = 0x3f3f3f3f;
const int MAXN = 1010;
int d[MAXN],cost[MAXN][MAXN],V;
bool used[MAXN];

int N,M;

void init(int V){
	int i,j;
	for(int i=0;i<V;i++)
		for(int j=0;j<V;j++)
			cost[i][j] = INF;
}
void dijkstra(int s,int V){ //s表示起点 V表示顶点数
	fill(d,d+V,INF);
	fill(used,used+V,false);
	//对d[i]要有初始化
	for(int i=0;i<V;i++)
		d[i] = cost[s][i];
	d[s] = 0;
	used[s] = 1;
	while(true){
		int v ,mins = INF;
		for(int i=0;i<V;i++){//d[i]表当前点距离
			if(!used[i] && d[i] < mins)
				mins = d[i],v = i;
		}
		if(mins == INF) break;
		used[v] = true;
		for(int i=0;i<V;i++){//当前点到其他顶点的距离
			if(!used[i])
				d[i] = min(d[i],d[v]+cost[v][i]);
		}
	}
}
int main()
{
    while(~scanf("%d%d",&N,&M)){
        init(N);
        for(int i=1;i<=M;i++){
            int A,B,X;
            scanf("%d%d%d",&A,&B,&X);
            if(X < cost[A][B])  //重边的问题
                cost[A][B] = cost[B][A] = X;
        }
        int start,ends;
        scanf("%d%d",&start,&ends);
        if(start == ends){
            printf("0\n");
            continue;
        }
        dijkstra(start,N);
        if(d[ends] >= INF) printf("-1\n");
        else
            printf("%d\n",d[ends]);
    }
    return 0;
}
