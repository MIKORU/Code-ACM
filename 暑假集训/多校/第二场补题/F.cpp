#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXP = 50;
const int MAXN = 1000;
int e[MAXP],s[MAXP];
int d[MAXN];
int vis[MAXN];
int n,m,num;
int  dfs(int x){
    if( num*2 >= m )  //枚举边到一半
    {
        for(int i=1; i<=n; i++)
            if( 2*vis[i] != d[i] )  //一半度满了就行
                return 0;
            return 1;
    }
    int ans = 0;
    if( vis[s[x]]*2<d[s[x]] && vis[e[x]]*2 < d[e[x]] ) //可选是否已满
    {
        vis[s[x]]++,vis[e[x]]++;
        num++; //选的边数
        ans += dfs(x+1);
        vis[s[x]]--,vis[e[x]]--;
        num--;
    }
    if( m/2-num < m-x  ) //还没有决定是否选的边数必须不小于ｍ的一半
        ans += dfs(x+1);
    return ans;
}
int judge(){
    if(m&1){
        return 0;
    }
    for(int i=1;i<=n;i++){
        if(d[i]&1){
            return 0;
        }
    }
    return dfs(0);
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--){
        memset(vis,0,sizeof(vis));
        memset(d,0,sizeof(d)); //卡在这！！
        num = 0;
        scanf("%d%d",&n,&m);
        for(int i=0;i<m;i++){
            scanf("%d%d",&s[i],&e[i]);
            d[e[i]]++;
            d[s[i]]++;
        }
        printf("%d\n",judge());
    }
    return 0;
}
