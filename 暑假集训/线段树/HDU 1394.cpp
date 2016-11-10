///HDU1394
//sum[i]为0代表i未出现，为1则已经出现，
//然后查询时我们只要统计新加入的数到n-1这个范围内有多少个sum[i]为1，也就是当前
//数的逆序，然后ret累加，就是我们要求的逆序数。因为其他形式都可以由第一次求得的逆
//序数递推而来，所以只需计算一次。
#include <cstdio>
#include <iostream>
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1 
using namespace std;
const int maxn = 5555;
int sum[maxn<<2];
void PushUP(int rt){ 
    sum[rt] = sum[rt<<1]+sum[rt<<1|1]; 
}
void build(int l,int r,int rt){  
    sum[rt] = 0;  //节点为0
    if(l == r){
        return ;
    }
    int m = (l + r)>>1;
    build(lson);
    build(rson);
}
void update(int p,int l,int r,int rt){
    if(l == r){
        sum[rt]++;
        return ;
    }
    int m = (l + r)>>1;
    if(p <= m)
        update(p,lson); 
    else update(p,rson);
    PushUP(rt);
}
int query(int L,int R,int l,int r,int rt){
    if(L <= l && r <= R){
        return sum[rt];
    }
    int m = (l + r)>>1;
    int ret = 0;
    if(L <= m)
        ret += query(L,R,lson);
    if(R > m)
        ret += query(L,R,rson);
    return ret;
}
int x[maxn];
int main()
{
    int n;
    while(~scanf("%d",&n)){
        build(0,n-1,1);
        int sum = 0;
        for(int i=0;i<n;i++){
            scanf("%d",&x[i]);
            sum += query(x[i],n-1,0,n-1,1);//a[0]开始，找比a[0]大的个数，也就是询问区间(a[0],n-1)中点的个数
            update(x[i],0,n-1,1); //然后再插入a[0]，更新父节点即可。
        }
//有个结论，设逆序数为sum，x[0]后面比它小的一定是x[0]个。
//那么移到末尾后，比x[0]大的数的后面比它小的数统统加一，
//也就是加（n - a[0] - 1），然后它放到末尾了，
//他原来的后面比它小的数变为0，
//也就是sum = sum + (n - a[0] - 1) - a[0];
        int ret = sum;
        for(int i=0;i<n;i++){
            sum += n-x[i]-x[i]-1;
            ret = min(ret , sum);
        }
        printf("%d\n",ret);
    }

    return 0;
}
