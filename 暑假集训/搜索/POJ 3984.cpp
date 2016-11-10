//假如只有计算最短路劲BFS这道BFS是超级超级简单题啊啊啊，但是要打印路径比较呵呵哒
//用了记录节点的方法，其实网上也有用dfs方法 或者写结构体 记录pre
//这道题输入输出略坑
#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
const int INF=10000000;
bool f[6][6];
int d[6][6];
int print[30];
int dir[4][2]={0,1,0,-1,1,0,-1,0};
int ans=0;
typedef pair<int ,int>P;
void bfs(int x,int y){
    ans = 0;
    queue<P> que;
    for(int i=0;i<5;i++)
        for(int j=0;j<5;j++)
            d[i][j]=INF;
    que.push(P(x,y));
    d[x][y]=0;
    print[0]=-1;              //起始位置设置为-1 作为输出递归的条件
    while(que.size()){
        P p= que.front();
        que.pop();
        if(p.first == 4&&p.second ==4)
            break;
        for(int i=0;i<4;i++){
            int nx = p.first+dir[i][0];
            int ny = p.second+dir[i][1];
            int fa = p.first*5+p.second;  //下一个位置是第几个数字
            if(0<=nx&&nx<5&&0<=ny&&ny<5&&f[nx][ny]==0&&d[nx][ny]==INF){
                que.push(P(nx,ny));
//                if(fa == 24) return ;
                d[nx][ny]=d[p.first][p.second]+1;
                print[nx*5+ny]=fa;   //这个点记录下一个位置的数字
            }
        }
    }
    ans = d[4][4];
}
void print_(int n)   //逆推打印
{
    if(print[n]!=-1){    //到起始状态时候
        print_(print[n]);
    }
    printf("(%d, %d)\n",n/5,n%5);
}
void read()
{
    memset(f,0,sizeof(f));
    memset(d,0,sizeof(d));
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
                scanf("%d",&f[i][j]);
        }
    }
}
int main()
{
    read();
    bfs(0,0);
    print_(24);
    return 0;
}
