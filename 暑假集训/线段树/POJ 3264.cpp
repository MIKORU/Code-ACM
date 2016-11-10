#include <cstdio>
#include <iostream>
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1 ///表示rt*2+1;
using namespace std;
const int MAXN = 55555;
int minn[MAXN<<2];
int maxn[MAXN<<2];
void PushUP(int rt){  ///当前节点更新到父节点
    minn[rt] = min(minn[rt<<1],minn[rt<<1|1]);  ///父节点是两节点之和
    maxn[rt] = max(maxn[rt<<1],maxn[rt<<1|1]);
}
void build(int l,int r,int rt){  ///构建子树
    if(l == r){
        int s;
        scanf("%d",&s);
        minn[rt] = maxn[rt] = s;
        return ;
    }
    int m = (l + r)>>1;
    build(lson);
    build(rson);
    PushUP(rt);
}
///区间求和 最值
int query(int s,int L,int R,int l,int r,int rt){  ///查询L、R之间
    if(L <= l && r <= R){  ///不在范围内 返回父节点
        if(s==1)
            return maxn[rt];
        else return minn[rt];
    }
    int m = (l + r)>>1;
    int ret1=0;
    int ret2 = 0x3f3f3f3f;
    if(L <= m)
        if(s==1)
            ret1 = max(ret1,query(1,L,R,lson));
        else
            ret2 = min(ret2,query(0,L,R,lson));
    if(R > m)
        if(s==1)
            ret1 = max(ret1,query(1,L,R,rson));
        else
            ret2 = min(ret2,query(0,L,R,rson));
    if(s==1)
        return ret1;
    else
        return ret2;
}
int main(){
    int N,Q;
    while(~scanf("%d%d",&N,&Q)){
        build(1,N,1);
        for(int i=0;i<Q;i++){
            int a,b;
            scanf("%d%d",&a,&b);
//            printf("zuida = %d  zuixiao = %d\n",query(1,a,b,1,N,1),query(0,a,b,1,N,1));
            printf("%d\n",query(1,a,b,1,N,1)-query(0,a,b,1,N,1));
        }
    }
    return 0;
}
