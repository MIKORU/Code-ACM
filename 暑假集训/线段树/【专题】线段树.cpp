/// 线段树专题  单点更新
#include <cstdio>
#include <iostream>
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1 ///表示rt*2+1;
using namespace std;
const int maxn = 55555;
int sum[maxn<<2];
void PushUP(int rt){  ///当前节点更新到父节点
    sum[rt] = sum[rt<<1]+sum[rt<<1|1];  ///父节点是两节点之和
}
void build(int l,int r,int rt){  ///构建子树
    if(l == r){
        ///进行底层的操作 读取or直接赋值 
        return ;
    }
    int m = (l + r)>>1;
    build(lson);
    build(rson);
    PushUP(rt);
}
///单点更新 增减
void update(int p,int add,int l,int r,int rt){
    if(l == r){
        ///按题目要求
        return ;
    }
    int m = (l + r)>>1;
    if(p <= m)
        update(p,add,lson);  ///p表示要更新上去的点 add表示传入的参数
    else update(p,add,rson);
    PushUP(rt);  ///回溯更新父节点
}
///区间求和 最值
int query(int L,int R,int l,int r,int rt){  ///查询L、R之间
    if(L <= l && r <= R){  ///不在范围内 返回父节点
        return sum[rt];
    }
    int m = (l + r)>>1;
    int ret = 0;
    if(L <= m)
        ///在左子树 求和 或者求最大或最小值等等
    if(R > m)
        ///在右子树 求和 或者求最大或最小值等等
    return ret;
}
//区间更新 延迟标记

long long add[maxn<<2];  ///lazy标记
long long sum[maxn<<2];
void PushUP(int rt){ 
    sum[rt] = sum[rt<<1]+sum[rt<<1|1];
}
void PushDown(int rt,int m){
    if(add[rt]){  ///标记
        add[rt<<1] += add[rt];
        add[rt<<1|1] += add[rt];  //延迟向下标记
        sum[rt<<1] += (m-(m>>1))*add[rt];
        sum[rt<<1|1] += (m>>1)*add[rt];
        add[rt] = 0;
    }
}
void build(int l,int r,int rt){
    /*add[rt] = 0;*/
    /*标记记号*/

    if(l == r) {
        /*scanf("%lld",&sum[rt]);*/
        /*底端操作*/
        return ;
    }
    int m = (l + r)>>1;
    build(lson);
    build(rson);
    PushUP(rt);
}
void update(int L,int R,int c,int l,int r,int rt){  ///成段替换
    if(L<=l && r<=R){
        /*add[rt] += c;//父节点再次被加
        sum[rt] += (long long)c*(r-l+1);*/
        /*对叶子节点的操作*/
        return ;
    }
    PushDown(rt,r-l+1);

    int m = (l + r)>>1;
    if(L <= m)
        update(L,R,c,lson); 
    if(R > m) update(L,R,c,rson);
    PushUP(rt); 
}
long long query(int L,int R,int l,int r,int rt){  ///查询L、R之间
    if(L <= l && r <= R){  ///不在范围内 返回父节点
        return /*sum[rt];*/
    }
    PushDown(rt,r-l+1);/*延迟更新到子树*/

    int m = (l + r)>>1;
    /*long long ret = 0;*/
    if(L <= m)
        /*ret+=query(L,R,lson);*/
    if(R > m)
        /*ret+=query(L,R,rson);*/
    return ret;
}