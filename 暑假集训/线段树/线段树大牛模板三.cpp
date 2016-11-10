///������� HDU1166
#include <cstdio>
#include <iostream>
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1 ///��ʾrt*2+1;
using namespace std;
const int maxn = 55555;
int sum[maxn<<2];
void PushUP(int rt){  ///��ǰ�ڵ���µ����ڵ�
    sum[rt] = sum[rt<<1]+sum[rt<<1|1];  ///���ڵ������ڵ�֮��
}
void build(int l,int r,int rt){  ///��������
    if(l == r){
        scanf("%d",&sum[rt]);  ///��ȡ��ײ��ֵ
        return ;
    }
    int m = (l + r)>>1;
    build(lson);
    build(rson);
    PushUP(rt);
}
///�������
void update(int p,int add,int l,int r,int rt){
    if(l == r){
        sum[rt] += add;
        return ;
    }
    int m = (l + r)>>1;
    if(p <= m)
        update(p,add,lson);  ///p��ʾҪ������ȥ�ĵ� add��ʾ������Ŀ
    else update(p,add,rson);
    PushUP(rt);  ///���ݸ��¸��ڵ�
}
int query(int L,int R,int l,int r,int rt){  ///��ѯL��R֮��
    if(L <= l && r <= R){  ///���ڷ�Χ��
        return sum[rt];
    }
    int m = (l + r)>>1;
    int ret = 0;///��Ա���
    if(L <= m)
        ret += query(L,R,lson);
    if(R > m)
        ret += query(L,R,rson);
    return ret;
}
int main()
{
    int n,m;
    int T;
    scanf("%d",&T);
    for(int cas=1;cas<=T;cas++){
        printf("Case %d:\n",cas);
        scanf("%d",&n);
        build(1,n,1);
        char que[10];
        while(scanf("%s",que)){
            int a,b;
            if(que[0]=='E')
                break;
            scanf("%d%d",&a,&b);
            if(que[0]=='Q'){
                printf("%d\n",query(a,b,1,n,1));
            }
            else if(que[0]=='S')
                update(a,-b,1,n,1);
            else update(a,b,1,n,1);
        }
    }
    return 0;
}

