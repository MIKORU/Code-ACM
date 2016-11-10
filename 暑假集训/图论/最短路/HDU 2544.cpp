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
void dijkstra(int s,int V){ //s��ʾ��� V��ʾ������
	fill(d,d+V,INF);
	fill(used,used+V,false);
	for(int i=1;i<=V;i++){ //��ʼ��d��Ϊ���1��������ľ���
        d[i] = cost[1][i];
	}
	d[s] = 0;
	while(true){
		int v = -1;
		for(int i=1;i<=V;i++){//d[i]��ǰ�����
			if(!used[i] && (v == -1||d[i]<d[v]))
				v = i;
//				printf("%d\n",v);
		}
		if(v == -1) break;
		used[v] = true;
		for(int i=1;i<=V;i++){//��ǰ�㵽��������ľ���
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
