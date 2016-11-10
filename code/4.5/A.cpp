#include<cstdio>
#include<cstring>
using namespace std;
const int INF = 0x3f3f3f3f;
const int maxn = 15;
char maps[maxn][maxn];
int vis[maxn];
int ans;
int n,k;
void dfs(int c,int cnt){
    if(cnt == k){
        ans++;
        return ;
    }
    if(c >= n)
        return ;
    for(int i=0;i<n;i++){
        if(!vis[i]&&maps[c][i]=='#'){
            vis[i] = 1;
            dfs(c+1,cnt+1);
            vis[i] = 0;
        }
    }
    dfs(c+1,cnt);
}
int main()
{
    while(~scanf("%d%d",&n,&k))
    {
        ans = 0;
        memset(vis,0,sizeof(vis));
        if(n==-1&&k==-1)
            break;
        for(int i=0;i<n;i++){
            scanf("%s",maps[i]);
        }
        dfs(0,0);
        printf("%d\n",ans);
    }
    return 0;
}
