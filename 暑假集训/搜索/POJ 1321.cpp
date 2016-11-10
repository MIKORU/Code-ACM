//这个题要是乍一看很难会想深搜，确实如此，可如果知道了深搜的方法，这个题就简
//了不少，至于用深搜的时候要考虑当k==n和k<n时这咱种情况，当K==n时，当然很好想
//到深搜搜下很容易找到所有方法，，但是当k<n时就得考虑后面的情况，
//所以后面加了个dfs(row+1,num)主要是这种情况的考虑。
#include <cstdio>
#include <cstring>
using namespace std;
int N,K;
int ans;
char map[10][10];
int vis[10];
void dfs(int h,int n)   //h表示当前行，n表示目前放了几个棋子
{
    if(n == K){
        ans++;
        return ;
    }
    if(h >= N) return ;  //当前行边界超过 返回
    for(int i=0;i<N;i++){  //i表示列
        if(!vis[i]&&map[h][i]=='#'){
            vis[i] = true;
            dfs(h+1,n+1);
            vis[i]=0;   //上一层返回后 这层标记消失
        }
    }
    dfs(h+1,n);   //这层不摆棋子 到下一层再处理 这一种情况 没有这种情况WA
}
int main()
{
    while(~scanf("%d%d",&N,&K)){
        memset(vis,0,sizeof(vis));
        ans=0;
        if(N==K&&N==-1)
            break;
        for(int i=0;i<N;i++){
            scanf("%s",&map[i]);
        }
        dfs(0,0);
        printf("%d\n",ans);
    }
}
