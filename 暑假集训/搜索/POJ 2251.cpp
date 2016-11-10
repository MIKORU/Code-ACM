#include <cstdio>
#include <cstring>
#include <queue>
#include <iostream>
using namespace std;
int dx[]={1,-1,0,0,0,0};
int dy[]={0,0,-1,1,0,0};
int dz[]={0,0,0,0,1,-1};
char map[100][100][100];
int d[100][100][100];
const int INF=100000000;
struct LOCA{
    int x,y,z;
    LOCA(){}
    LOCA(int a,int b,int c){
        x=a;
        y=b;
        z=c;
    }
};
LOCA p;
int sx,sy,sz;
int gx,gy,gz;
int L,R,C;
int bfs(){
    queue<LOCA> que;
    for(int i=0;i<L;i++)
        for(int j=0;j<R;j++)
            for(int k=0;k<C;k++)
                d[i][j][k]=INF;
    que.push(LOCA(sx,sy,sz));
    d[sx][sy][sz] = 0 ;
    while(que.size()){
        p = que.front();
        que.pop();
        if(p.x==gx&&p.y==gy&&p.z==gz) break;
        for(int i=0;i<6;i++){
            int nx = p.x+dx[i];
            int ny = p.y+dy[i];
            int nz = p.z+dz[i];
            if(0<=nx&&nx<=L&&0<=ny&&ny<=R&&0<=nz&&nz<=C&&map[nx][ny][nz]=='.'&&d[nx][ny][nz]==INF){
                que.push(LOCA(nx,ny,nz));
                d[nx][ny][nz] = d[p.x][p.y][p.z]+1;
            }
        }
    }
    return d[gx][gy][gz];
}
int main()
{
    while(~scanf("%d%d%d",&L,&R,&C)&&(L+R+C)){
        memset(d,0,sizeof(d));
        memset(map,0,sizeof(map));
        for(int i=0;i<L;i++){
            for(int j=0;j<R;j++){
                scanf("%s",&map[i][j]);
                for(int k=0;k<C;k++){
                    if(map[i][j][k]=='S'){
                            sx = i;
                            sy = j;
                            sz = k;
                    }
                    if(map[i][j][k]=='E'){
                            gx = i;
                            gy = j;
                            gz = k;
                    }
                }
            }
        }
//        for(int i=0;i<L;i++,putchar('\n'))
//            for(int j=0;j<R;j++)
//                printf("%s\n",map[i][j]);
//        printf("%d %d %d\n%d %d %d\n",sx,sy,sz,gx,gy,gz);
        printf("%d\n",bfs());
    }
    return 0;
}
