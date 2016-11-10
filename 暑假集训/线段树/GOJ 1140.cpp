///GOJ 1140
//#include <cstdio>
//#include <iostream>
//#define lson l,m,rt<<1
//#define rson m+1,r,rt<<1|1
//using namespace std;
//const int maxn = 1000010;
//int sum[maxn<<2];
//void PushUP(int rt){
//    sum[rt] = sum[rt<<1]+sum[rt<<1|1];
//}
//void build(int l,int r,int rt){
//    sum[rt] = 0;
//    if(l == r){
//        return ;
//    }
//    int m = (l + r)>>1;
//    build(lson);
//    build(rson);
//}
//void update(int p,int l,int r,int rt){
//    if(l == r){
//        sum[rt]++;
//        return ;
//    }
//    int m = (l + r)>>1;
//    if(p <= m)
//        update(p,lson);
//    else update(p,rson);
//    PushUP(rt);
//}
//int query(int L,int R,int l,int r,int rt){
//    if(L <= l && r <= R){
//        return sum[rt];
//    }
//    int m = (l + r)>>1;
//    int ret = 0;
//    if(L <= m)
//        ret += query(L,R,lson);
//    if(R > m)
//        ret += query(L,R,rson);
//    return ret;
//}
//int x[maxn];
//int main()
//{
//    int n;
//    while(~scanf("%d",&n)){
//        build(0,n-1,1);
//        long long sum = 0;
//        for(int i=0;i<n;i++){
//            scanf("%d",&x[i]);
//            sum += query(x[i],n-1,0,n-1,1);
//            update(x[i],0,n-1,1);
//        }
//        printf("%lld\n",sum);
//    }
//
//    return 0;
//}
//树状数组面对大数据要离散化 而且完全不懂为毛不离散化就不对ORZ
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;
const int MAXN = 1100000;
int n;
int bit[MAXN];
int b[MAXN];

struct node{
	int val,pos;
	bool operator <(const node &a) const{
		return val<a.val;
	}
} a[MAXN];
int Lowbit(int t){
	return t&(-t);
}
void update(int x,int m){
	while(x<=n){
		bit[x] += m;
		x += Lowbit(x);
	}
}
long long sum(int x){
	long long  sum = 0;
	while(x > 0){
		sum += bit[x];
		x -= Lowbit(x);
	}
	return sum;
}
int main(){
	while(~scanf("%d",&n)){
		for(int j=1;j<=n;j++){
			scanf("%d",&a[j].val);
			a[j].pos = j;
		}
		sort(a+1,a+n+1);
		for(int j=1;j<=n;j++)
			b[a[j].pos] = j;//数据离散化
		memset(bit,0,sizeof(bit));
		long long ans = 0;
		for(int j=1;j<=n;j++){
			update(b[j],1);
			ans += j-sum(b[j]);
		}
		printf("%lld\n",ans);
	}
	return 0;
}

