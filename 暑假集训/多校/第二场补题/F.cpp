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
    if( num*2 >= m )  //ö�ٱߵ�һ��
    {
        for(int i=1; i<=n; i++)
            if( 2*vis[i] != d[i] )  //һ������˾���
                return 0;
            return 1;
    }
    int ans = 0;
    if( vis[s[x]]*2<d[s[x]] && vis[e[x]]*2 < d[e[x]] ) //��ѡ�Ƿ�����
    {
        vis[s[x]]++,vis[e[x]]++;
        num++; //ѡ�ı���
        ans += dfs(x+1);
        vis[s[x]]--,vis[e[x]]--;
        num--;
    }
    if( m/2-num < m-x  ) //��û�о����Ƿ�ѡ�ı������벻С�ڣ��һ��
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
        memset(d,0,sizeof(d)); //�����⣡��
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
