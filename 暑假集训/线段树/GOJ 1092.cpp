///单点更新
#include <cstdio>
#include <iostream>
#include <algorithm>
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1 ///表示rt*2+1;
using namespace std;
const int N = 100010;
const int maxn = 2000100;
int sum[maxn<<2];
void PushUP(int rt){  ///当前节点更新到父节点
    sum[rt] = max(sum[rt<<1],sum[rt<<1|1]);  ///父节点是两节点之和
}
void build(int l,int r,int rt){  ///构建子树
    if(l == r){
        sum[rt] = 0;///读取值
        return ;
    }
    int m = (l + r)>>1;
    build(lson);
    build(rson);
    PushUP(rt);
}
void update(int p,int add,int l,int r,int rt){
    if(l == r){
        sum[rt] = add;
        return ;
    }
    int m = (l + r)>>1;
    if(p <= m)
        update(p,add,lson);  ///p表示要更新上去的点 add表示增加数目
    else update(p,add,rson);
    PushUP(rt);  ///回溯更新父节点
}
int query(int L,int R,int l,int r,int rt){  ///查询L、R之间
    if(L <= l && r <= R){  ///不在范围内
        return sum[rt];
    }
    int m = (l + r)>>1;
    int ret = 0;///针对本题
    if(L <= m)
        ret = max(ret,query(L,R,lson));
    if(R > m)
        ret = max(ret,query(L,R,rson));
    return ret;
}
int f(int a){
    int count = 1;
    while(a!=1){
        if(a&1)
            a += (a<<1)+1;
        else
            a /=2;
        count++;
    }
    return count;
}
int main()
{
    int T;
    build(1,N,1);
    for(int i=1;i<=N;i++){
        update(i,f(i),1,N,1);
    }
    while(~scanf("%d",&T)){
        while(T--){
            int a,b;
            scanf("%d%d",&a,&b);
            printf("%d\n",query(a,b,1,N,1));
        }
    }
    return 0;
}

