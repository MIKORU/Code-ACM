#include<cstdio>
#include<cstring>
int n;
int vis[100];
int length[100];
int minn = 1000;
int dfs(int x,int ans){
    if(x==n)
        return 0;
    if(!vis[x]){
        vis[x] = 1;
        dfs(x+1,ans+=length[x]);
        vis[x] = 0;
    }
    dfs(x+1,ans);
}
int main(){
    while(~scanf("%d",&n)){
        minn = 1000;
        memset(vis,0,sizeof(vis));
        for(int i=0;i<n;i++){
            scanf("%d",&length[i]);
        }

    }
    return 0;
}
