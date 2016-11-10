#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int num = 100;
int vis[num];
int sticks[num];
int N,M;
int l;
int cmp(int a,int b){
    return a > b;
}
int dfs(int cnt,int len,int start){
    if(cnt==3){
        return true;
    }
    for(int i=start;i<M;i++){
        if(!vis[i]){
            vis[i] = true;
            if(len+sticks[i]<l){
                if(dfs(cnt,len+sticks[i],i))
                    return true;
            }
            else if(len+sticks[i] == l){
                if(dfs(cnt+1,0,0))
                    return true;
            }
            vis[i] = false;
        }
    }
    return false;
}
int main(){
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    scanf("%d",&N);
    while(N--){
        int sum = 0;
        memset(vis,0,sizeof(vis));
        scanf("%d",&M);
        for(int i=0;i<M;i++){
            scanf("%d",&sticks[i]);
            sum += sticks[i];
        }
        l = sum/4;
        sort(sticks,sticks+M,cmp);
        if(sum%4!=0||M<4||l < sticks[0]){
            printf("no\n");
        }
        else if(dfs(0,0,0)){
            printf("yes\n");
        }
        else printf("no\n");
    }
    return 0;
}
