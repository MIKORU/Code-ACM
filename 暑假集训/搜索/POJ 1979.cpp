//深搜的想法大概是八连通改成四个方向就好了 但是由于写错了边界各种WA！！TT 0ms
//#include <cstdio>
//#include <iostream>
//#include <cstring>
//using namespace std;
//int h,w;
//char f[25][25];
//int ans;
//int dir[4][2]={0,1,0,-1,1,0,-1,0};
//void dfs(int x,int y)
//{
//    f[x][y]='#';
//    for(int i=0;i<4;i++){
//        int nx=x+dir[i][0];
//        int ny=y+dir[i][1];
//        if(0<=nx&&nx<=h&&0<=ny&&ny<=w&&f[nx][ny]=='.'){
//
//            ans++;
//            dfs(nx,ny);
//        }
//    }
//}
//void read()
//{
//    ans = 0;
//    memset(f,0,sizeof(f));
//    for(int i=0;i<h;i++){
//        scanf("%s",&f[i]);
//    }
//}
//int main()
//{
//    while(~scanf("%d%d",&w,&h),w+h){
//        read();
//        for(int i=0;i<h;i++){
//            for(int j=0;j<w;j++){
//                if(f[i][j]=='@'){
//                    dfs(i,j);
//                    break;
//                }
//            }
//        }
//    printf("%d\n",ans+1);
//    }
//    return 0;
//}
//bfs来说这个算是水题 好吧 就是水题 初始状态设置问题 32ms 改了下没用vis标记 0ms
#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
int h,w;
char f[25][25];
int dir[4][2]={0,1,0,-1,1,0,-1,0};
typedef pair<int ,int>P;
int bfs(int x,int y){
    int ans=1;
    queue<P> que;
    que.push(P(x,y));
    while(que.size()){
        P p= que.front();
        que.pop();
        for(int i=0;i<4;i++){
            int nx = p.first+dir[i][0];
            int ny = p.second+dir[i][1];
            if(0<=nx&&nx<h&&0<=ny&&ny<w&&f[nx][ny]=='.'){
                f[nx][ny]='#';
                que.push(P(nx,ny));
                ans++;
            }
        }
    }
    return ans;
}
void read()
{
    memset(f,0,sizeof(f));
    for(int i=0;i<h;i++){
        scanf("%s",&f[i]);
    }
}
int main()
{
    while(~scanf("%d%d",&w,&h),w+h){
        read();
        int ans=0;
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                if(f[i][j]=='@'){
                    f[i][j]='#';
                    ans = bfs(i,j);
                    break;
                }
            }
        }
    printf("%d\n",ans);
    }
    return 0;
}

