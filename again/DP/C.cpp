#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 30+5;
int n;
struct node{
    int x;
    int y;
    int z;
    //node(int _x,int _y,int _z):x(_x),y(_y),z(_z){}
};
node b[maxn*8];
int dp[maxn*1000];
int cmp(const node a,const node b){
    if(a.x==b.x)
        return a.y>b.y;
    else return a.x>b.x;
}
int main()
{
    int cases = 1;
    while(~scanf("%d",&n)){
        int k=0;
        int m[4];
        if(n==0) break;
        for(int i=0;i<n;i++){
            scanf("%d%d%d",&m[0],&m[1],&m[2]);
            //sort(m,m+3);
            //printf("%d %d %d\n",m[0],m[1],m[2]);
            b[k].x=m[1],b[k].y=m[2],b[k].z=m[0],k++;
            b[k].x=m[2],b[k].y=m[1],b[k].z=m[0],k++;
            b[k].x=m[0],b[k].y=m[2],b[k].z=m[1],k++;
            b[k].x=m[2],b[k].y=m[0],b[k].z=m[1],k++;
            b[k].x=m[0],b[k].y=m[1],b[k].z=m[2],k++;
            b[k].x=m[1],b[k].y=m[0],b[k].z=m[2],k++;
        }
        sort(b,b+k,cmp);
        int maxh = 0;
        for(int i=0;i<k;i++){
            dp[i] = b[i].z;
            for(int j=i-1;j>=0;j--){
                if(b[j].x>b[i].x&&b[j].y>b[i].y){
                    dp[i] = max(b[i].z+dp[j],dp[i]);
                }
                if(dp[i]>maxh)
                    maxh = dp[i];
            }
        }
        printf("Case %d: maximum height = %d\n",cases++,maxh);
    }
    return 0;
}
