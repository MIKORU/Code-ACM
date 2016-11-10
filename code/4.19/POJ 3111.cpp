#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#define eps 1e-6
using namespace std;
const int maxn = 1000005;
int n,k;
int v[maxn],w[maxn];
struct P{
    double cost;
    int id;
};
P y[maxn];
int index[maxn];
int cmp(P a,P b){
    return a.cost>b.cost;
}
bool can(double x){
    for(int i=0;i<n;i++){
        y[i].cost = v[i]-x*w[i];
        y[i].id = i+1;
    }
    sort(y,y+n,cmp);
    double sum=0;
    for(int i=0;i<k;i++){
        sum += y[i].cost;
        index[i] = y[i].id;
    }
    return sum>=0;
}
int main()
{
    while(~scanf("%d%d",&n,&k)){
        for(int i=0;i<n;i++){
            scanf("%d%d",&v[i],&w[i]);
        }
        double lm = 0;
        double rm = maxn;
        double mid;
        for(int i=0;i<50;i++){
            mid = (lm+rm)/2;
            if(can(mid))
                lm = mid;
            else rm = mid;
        }
        for(int i=0;i<k;i++){
            if(i==k-1){
                printf("%d\n",index[i]);
            }
            else printf("%d ",index[i]);
        }
    }
    return 0;
}
