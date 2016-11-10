#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
const int INF = 0x3f3f3f3f;
const int maxn = 35;
int L,R,C;
char maps[maxn][maxn][maxn];
int d[maxn][maxn][maxn];
bool vis[maxn][maxn][maxn];
int dx[]={1,0,-1,0,0,0};
int dy[]={0,1,0,-1,0,0};
int dz[]={0,0,0,0,-1,1};
int ans;
struct node{
    int x;
    int y;
    int z;
    node(int _x=0,int _y=0,int _z=0):x(_x),y(_y),z(_z){}
};
bool can(int x,int y,int z){
    if(x<0||x>=L){
        return 0;
    }
    else if(y<0||y>=R){
        return 0;
    }
    else if(z<0||z>=C){
        return 0;
    }
    else return 1;
}
int bfs(int x,int y,int z){
    queue<node>q;
    memset(d,-1,sizeof(d));
    memset(vis,0,sizeof(vis));
    node u = node(x,y,z);
    q.push(u);
    d[u.x][u.y][u.z] = 0;
    while(!q.empty()){
        u = q.front();
        q.pop();
        if(maps[u.x][u.y][u.z]=='S'){
            return d[u.x][u.y][u.z];
        }
        for(int i=0;i<6;i++){
            node a;
            a.x = u.x+dx[i];
            a.y = u.y+dy[i];
            a.z = u.z+dz[i];
            if(!vis[a.x][a.y][a.z]&&maps[a.x][a.y][a.z]!='#'&&can(a.x,a.y,a.z)){
                d[a.x][a.y][a.z] = d[u.x][u.y][u.z]+1;
                vis[a.x][a.y][a.z] = 1;
                q.push(a);
            }
        }
    }
    return -1;
}
int main()
{
    while(~scanf("%d%d%d",&L,&R,&C)){
        if(!L&&!R&&!C) break;
        for(int i=0;i<L;i++){
            for(int j=0;j<R;j++){
                scanf("%s",maps[i][j]);
            }
            getchar();
        }
        for(int i=0;i<L;i++)
            for(int j=0;j<R;j++)
                for(int k=0;k<C;k++){
                        if(maps[i][j][k]=='E'){
                                ans = bfs(i,j,k);
                        }
                }
        if(ans!=-1)
            printf("Escaped in %d minute(s).\n",ans);
        else printf("Trapped!\n");
    }
    return 0;
}
