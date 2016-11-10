#include<cstdio>
#include<cmath>
#include<cstring>
#include<queue>
using namespace std;
const int INF = 0x3f3f3f3f;
const int maxn = 1010000;
int d[maxn];
int vis[maxn*2];  //貌似数据出了点问题？C++ WA  G++就过了
int N,K;
bool can(int x){
    if(vis[x])
        return 0;
    if(x<0)
        return 0;
    if(x>maxn)  //数组不能越界
        return 0;
    return 1;

}
void bfs(int x){
    queue<int>q;
    memset(vis,0,sizeof(vis));
    memset(d,0,sizeof(d));
    d[x]=0;
    vis[x] = 1;
    q.push(x);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        if(u == K){
            return ;
        }
        for(int i=0;i<3;i++){
            int v;
            if(i==0)
                v = u-1;
            else if(i==1)
                v = u+1;
            else v = u*2;
            if(can(v)){
                d[v] = d[u]+1;
                q.push(v);
                vis[v] = 1;
//              printf("%d\n",v1);
            }
        }
    }
}
int main()
{
    while(~scanf("%d%d",&N,&K)){
        if(K <= N){
            printf("%d\n",N-K);
            continue;
        }
        bfs(N);
        printf("%d\n",d[K]);
    }
}
