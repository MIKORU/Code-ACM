#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h> // 取绝对值
#include <iostream>
#include <algorithm>
#include <stack>
#include <map>
#include <vector>
#include <set>
#include <queue>  //priority_queue<int>
#include <utility> //pair类或者 typedef pair<int ,int>P;
#define LL long long
#define LL long long
#define CAN(a,b) memset(a,b,sizeof(a))
#define MAX_N 10005
const int INF = 0x3f3f3f3f;
using namespace std;
int pair[MAX_N];
int rank[MAX_N];
//初始化n个元素
void init(int n)
{
    for(int i = 0;i<n;i++)
    {
        par[i] = i;  //父亲
        rank[i]=0;  //rank表示高度
    }
}
//查询树的根
int find(int x)
{
    if(par[x] == x)   //代表根
        return x;
    else return par[x] = find[par[x]];
}
//合并x,y所在的集合
void unite(int x,int y)
{
    x = find(x);
    y = find(y);
    if(x == y) return ;
    // else par[x] = y;（这种不需要rank）
    if(rank[x]<rank[y])
        par[x] = y;
    else
    {
        par[y] = x;
        if(rank[x] == rank[y])
            rank[x]++;
    }
}
// 判断x,y是否属于一个集合
bool same(int x,int y)
{
    return find(x)==find(y);
}


//食物链那道题
int N,K;
int T[MAX_N],X[MAX_N],Y[MAX_N];
void solve()
{
    init(N*3);
    int ans = 0;
    for(int i = 0; i < K ; i++)
    {
        int t = T[i];
        int x = X[i]-1,y = Y[i]-1;
        if(x<0||N<=x||y<0||N<=y)
        {
            ans++;
            continue;
        }
    }
    if(t == 1)
    {
        if(same(x,y+N)||same(x,y+2*N))
            ans++;
        else
        {
            unite(x,y);
            unite(x+N,y+N);
            unite(x+N*2,y+N*2);
        }
    }
    else
    {
        if(same(x,y)||same(x,y+2*N))
            ans++;
        else
        {
            unite(x,y+N);
            unite(x+N,y+2*N);
            unite(x+2*N,y);
        }
    }
    printf("%d\n",ans);
}
