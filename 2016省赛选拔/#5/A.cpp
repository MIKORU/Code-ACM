#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h> // 取绝对值
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>  //priority_queue<int>
#include <vector>
#include <map>
#include <set>
#include <utility> //pair类或者 typedef pair<int ,int>P;
#define LL long long
#define CAN(a,b) memset(a,b,sizeof(a))  //大数 memset(a,0x7f,sizeof(a));
#define MAX_N 100000100

#define lc idx<<1
#define rc idx<<1|1
#define mid (l+r)/2
#define lson lc,l,mid
#define rson rc,mid+1,r

const int INF = 0x3f3f3f3f;
using namespace std;

int pri[MAX_N];
struct Tree{
    int a[MAX_N<<2];
    void build(int idx,int l,int r){
        a[idx] = 1LL<<30;
        if(l==r) return ;
        build(lson);
        build(rson);
    }
    void update(int idx,int l,int r,int p,int v){
        if(l==r){
            a[idx] = v;
            return ;
        }
        if(p<=mid)
            update(lson,p,v);
        else update(rson,p,v);
        a[idx] = min(a[lc],a[rc]);
    }
    int query(int idx,int l,int r,int x,int y){
        if(x<=1 && r<=y)
            return a[idx];
        if(x<=mid) ans = query(lson,x,y);
        if(y>mid) ans = min(ans,query(rson,x,y));
        return ans;
    }
}T;
int a[MAX_N];
int main()
{

    while(scanf("")!=EOF)
    {

    }
return 0;
}
