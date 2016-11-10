//�������
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1 ///��ʾrt*2+1;
const int maxn = 111111;
long long add[maxn<<2];  ///lazy���
long long sum[maxn<<2];
void PushUP(int rt){
    sum[rt] = sum[rt<<1]+sum[rt<<1|1];
}
void PushDown(int rt,int m){
	if(add[rt]){  ///���
		add[rt<<1] += add[rt];
		add[rt<<1|1] += add[rt];  ///�ӳ����±��
		sum[rt<<1] += (m-(m>>1))*add[rt];
		sum[rt<<1|1] += (m>>1)*add[rt];
		add[rt] = 0;
	}
}
void build(int l,int r,int rt){
	add[rt] = 0;

	if(l == r) {
		scanf("%lld",&sum[rt]);
		return ;
	}
    int m = (l + r)>>1;
    build(lson);
    build(rson);
    PushUP(rt);
}
void update(int L,int R,int c,int l,int r,int rt){  ///�ɶ��滻
    if(L<=l && r<=R){
    	add[rt] += c;
    	sum[rt] += (long long)c*(r-l+1);
    	return ;
    }
    PushDown(rt,r-l+1);

    int m = (l + r)>>1;
    if(L <= m)
        update(L,R,c,lson);
    if(R > m) update(L,R,c,rson);
    PushUP(rt);
}
long long query(int L,int R,int l,int r,int rt){  ///��ѯL��R֮��
    if(L <= l && r <= R){  ///���ڷ�Χ�� ���ظ��ڵ�
        return sum[rt];
    }
    PushDown(rt,r-l+1);

    int m = (l + r)>>1;
    long long ret = 0;///��Ա���
    if(L <= m)
        ret+=query(L,R,lson);
    if(R > m)
        ret+=query(L,R,rson);
    return ret;
}
int main()
{
	long long N,Q;
	while(~scanf("%lld%lld",&N,&Q)){
		build(1,N,1);
		for(int i=0;i<Q;i++){
			char q[3];
			scanf("%s",q);
			long long a,b,c;
			if(q[0] == 'Q'){
				scanf("%lld%lld",&a,&b);
				printf("%lld\n",query(a,b,1,N,1));
			}
			if(q[0] == 'C'){
				scanf("%lld%lld%lld",&a,&b,&c);
				update(a,b,c,1,N,1);
			}
		}
	}
    return 0;
}
