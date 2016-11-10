#include<cstdio>
#include<cstring>
char map[10][10];
int vis[10];
int n,k;
int ans;
void dfs(int x,int s){
    if(s == k){
        ans++;
        return ;
    }
    if(x>n)
        return ;
    for(int i=0;i<n;i++){
        if(map[x][i]=='#'&&!vis[i]){
            vis[i] = true;
            dfs(x+1,s+1);
            vis[i] = false;
        }
    }
    dfs(x+1,s);
}
int main(){
    while(scanf("%d%d",&n,&k)!=EOF){
        memset(vis,0,sizeof(vis));
        ans = 0;
        if(n==-1&&k==-1)
            break;
        for(int i=0;i<n;i++){
            scanf("%s",&map[i]);
        }
        dfs(0,0);
        printf("%d\n",ans);
    }
    return 0;
}
