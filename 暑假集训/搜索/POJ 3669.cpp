//艰难的用自己的代码AC 简直是太艰难了TT  2008K	79MS
//想法大概就是把图改成何时爆炸 然后条件约束 其实不难TT
#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
int M;
int maxn ;
bool vis[512][512];
int map[512][512];
struct Meteor{
    int x,y,t;
};
typedef Meteor P;
int dir[5][2]={{-1,0},{1,0},{0,-1},{0,1},{0,0}};
int bfs()
{
    memset(vis,0,sizeof(vis));
    queue<P> que;
    P cur;
    cur.t = 0;
    cur.x = 0;
    cur.y = 0;
    que.push(cur);
    while(que.size()){
        P p = que.front();
        que.pop();
        for(int i=0;i<4;i++){
            cur = p;
            cur.x=cur.x+dir[i][0];
            cur.y=cur.y+dir[i][1];
            ++cur.t;
            if(0<=cur.x&&0<=cur.y&&map[cur.x][cur.y]>cur.t&&!vis[cur.x][cur.y]){
                vis[cur.x][cur.y] = 1;
                if(map[cur.x][cur.y]>maxn){
                    return cur.t;
                }
                que.push(cur);
            }
        }
    }
    return -1;  //return -1这里坑了很久 而且检查没出来
}
int main()
{
//    freopen("00.txt","w",stdout);

    while(~scanf("%d",&M)){
        P m[50100];
        for(int i=0;i<M;i++){
            scanf("%d%d%d",&m[i].x,&m[i].y,&m[i].t);
        }
        memset(map, 0x7F, sizeof(map));
        for(int i=0;i<M;i++){
            maxn = max(maxn,m[i].t);
            for(int j=0;j<5;j++){
                int nx = m[i].x+dir[j][0];
                int ny = m[i].y+dir[j][1];
                if(0<=nx&&ny>=0&&map[nx][ny]>=m[i].t){ //这里的time等于 or 大于都没问题
                    map[nx][ny] = m[i].t;
                }
            }
        }
//        for(int i=0;i<4;i++)
//            printf("%s\n",map[i]);
        if(map[0][0]==0){
            printf("-1\n");
        }
        else printf("%d\n",bfs());
    }
    return 0;
}
