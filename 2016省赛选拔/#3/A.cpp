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
#define MAX_N
const int INF = 0x3f3f3f3f;
using namespace std;
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
int main()
{

    while(scanf("")!=EOF)
    {

    }
return 0;
}
