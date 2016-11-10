#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int INF = 0x3f3f3f3f;
const int MAXN = 110;
bool vis[MAXN];
int lowc[MAXN];
int cost[MAXN][MAXN];

int N;

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
void init()
{
    for(int i=0;i<=N;i++)
        for(int j=0;j<=N;j++)
            cost[i][j] = INF;
}
int main()
{
    while(~scanf("%d",&N)){
        init();
        for(int i=0;i<N;i++) //prime模板从0开始
            for(int j=0;j<N;j++){
                scanf("%d",&cost[i][j]);
            }
        printf("%d\n",prime(cost,N));
    }
    return 0;
}
