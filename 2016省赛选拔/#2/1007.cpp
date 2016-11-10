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
#define MAX_N 100005
const int INF = 0x3f3f3f3f;
using namespace std;
typedef pair<double,double> P;
int N;
P A[MAX_N];
bool compare_y(P a,P b){
    return a.second<b.second;
}
double closest_pair(P *a,int n){
    if(n<=1)
        return INF;
    int m = n/2;
    double x = a[m].first;
    double d = min(closest_pair(a,m),closest_pair(a+m,n-m));
    inplace_merge(a,a+m,a+n,compare_y);
    vector<P> b;
    for(int i=0;i<n;i++){
        if(fabs(a[i].first-x)>=d)
            continue;
        for(int j=0;j<b.size();j++){
            double dx = a[i].first-b[b.size()-j-1].first;
            double dy = a[i].second - b[b.size()-j-1].second;
            if(dy>=d)
                break;
            d = min(d,sqrt(dx*dx+dy*dy));
        }
        b.push_back(a[i]);
    }
    return d;
}
void solve(){
    sort(A,A+N);
    printf("%.2f\n",closest_pair(A,N));
}
int main(){
    while(~scanf("%d",&N)){
        for(int i=0;i<N;i++){
            scanf("%lf%lf",&A[i].first,&A[i].second);
        }
        solve();
    }
    return 0;
}
