///��Ȼˮ�������п�Orz
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
void dijkstra(int s,int V){ //s��ʾ��� V��ʾ������
	fill(d,d+V,INF);
	fill(used,used+V,false);
	//��d[i]Ҫ�г�ʼ��
	for(int i=0;i<V;i++)
		d[i] = cost[s][i];
	d[s] = 0;
	used[s] = 1;
	while(true){
		int v ,mins = INF;
		for(int i=0;i<V;i++){//d[i]��ǰ�����
			if(!used[i] && d[i] < mins)
				mins = d[i],v = i;
		}
		if(mins == INF) break;
		used[v] = true;
		for(int i=0;i<V;i++){//��ǰ�㵽��������ľ���
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
            if(X < cost[A][B])  //�رߵ�����
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
