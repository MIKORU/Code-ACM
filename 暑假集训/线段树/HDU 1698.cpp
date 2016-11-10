///dota中的屠夫（英雄）有一个钩子，钩子是连续的，
///现在假设钩子编号是从1到n，每个钩子有三种状态，
///分别对应的值是1、2、3（初始值都是1）。
///现在有m组操作：x，y，change；
///表示下标从x到y的钩子的值变为change。
///当然change的值只能是1、2、3。
///最后问这n个钩子的值的和sum是多少。
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1 ///表示rt*2+1;
const int maxn = 111111;
int h,n,w;
int col[maxn<<2];  ///lazy标记
int sum[maxn<<2];
void PushUP(int rt){
    sum[rt] = sum[rt<<1]+sum[rt<<1|1];
}
void PushDown(int rt,int m){
	if(col[rt]){  ///标记
		col[rt<<1] = col[rt<<1|1] = col[rt];
		sum[rt<<1] = (m-(m>>1))*col[rt];
		sum[rt<<1|1] = (m>>1)*col[rt];
		col[rt] = 0;
	}
}
void build(int l,int r,int rt){
	col[rt] = 0;
	sum[rt] = 1;

	if(l == r) return ;

    int m = (l + r)>>1;
    build(lson);
    build(rson);
    PushUP(rt);
}
void update(int L,int R,int c,int l,int r,int rt){  ///L,R为指定位置
    if(L<=l&&r<=R){
    	col[rt] = c;
    	sum[rt] = c*(r-l+1);
    	return ;
    }
    PushDown(rt,r-l+1);

    int m = (l + r)>>1;
    if(L <= m)
        update(L,R,c,lson);
    if(R > m) update(L,R,c,rson);
    PushUP(rt);
}

int main()
{
	int T,n,m;
	scanf("%d",&T);
	for(int cas = 1;cas<=T;cas++){
		scanf("%d%d",&n,&m);
		build(1,n,1);
		for(int i=0;i<m;i++){
			int a,b,c;
			scanf("%d%d%d",&a,&b,&c);
			update(a,b,c,1,n,1);
		}
		printf("Case %d: The total value of the hook is %d.\n",cas,sum[1]); ///节点为1代表所有总和
	}
    return 0;
}
