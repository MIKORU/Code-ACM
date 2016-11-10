#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int INF = 0x3f3f3f3f;
const int MAXN = 255;
int e[MAXN][MAXN];
int n,m,x;
void Floyd()
{
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j = 1;j<=n;j++){
                e[i][j] = min(e[i][j],e[i][k]+e[k][j]);
            }
}
void init()
{
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            e[i][j] = INF;
}
int main()
{
    while(~scanf("%d%d%d",&n,&m,&x)){
        init();
        for(int i=1;i<=m;i++){
            int a,b,t;
            scanf("%d%d%d",&a,&b,&t);
            e[a][b] = t;
        }
        Floyd();
        int ans=0;
        for(int i=1;i<=n;i++)
            ans = max(ans,e[x][i]+e[i][x]);
        printf("%d\n",ans);
    }
    return 0;
}
