#include<cstdio>
#include<cstring>
#include<algorithm>
using  namespace std;
const int INF = 0x3f3f3f3f;
const int MAXN = 1005;
int N,M;
int dis[MAXN][MAXN];
int main(){
	while(~scanf("%d%d",&N,&M)){
		for(int i=1;i<=N;i++){
			for(int j=1;j<N;j++){
				if(i==j){
					dis[i][j] = dis[j][i] = 0;
				}
				else dis[i][j] = dis[j][i] = INF;
			}
		}
		for(int i=0;i<M;i++){
			int a,b,c;
			scanf("%d%d%d",&a,&b,&c);
			if(dis[a][b] > c){
					dis[a][b] = dis[b][a] =c;
			}
		}
		for(int k=1;k<=N;k++){
			for(int i=1;i<=N;i++){
				for(int j=1;j<=N;j++){
					dis[i][j] = min(dis[i][j],dis[i][k]+dis[k][j]);
				}
			}
		}
		for(int i=1;i<=N;i++){
			for(int j=1;j<N;j++){
				printf("%d ",dis[i][j]);
			}
			printf("%d\n",dis[i][N]);
		}
	}
}
