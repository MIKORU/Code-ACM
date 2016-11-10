///POJ 1064
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
const int INF = 100005;
const int maxn = 10005;
int K,N;
double L[maxn];
bool can(double x)
{
    int num = 0;
    for(int i=0;i<N;i++){
        num += (int)(L[i]/x);
    }
    return num>=K;
}
int main()
{
    while(~scanf("%d%d",&N,&K)){
        for(int i=0;i<N;i++){
            scanf("%lf",&L[i]);
        }
        double lm = 0;
        double rm = INF;
        double mid;
        for(int i=0;i<1000;i++){  ///时间要求比较苛刻的时候还是别用了
            mid = (lm+rm)/2;  ///i到100精大概可以到10^-30左右，对付题目绰绰有余
            if(can(mid))
                lm = mid;
            else rm = mid;
        }
        printf("%.2f\n",floor(rm*100)/100);  ///变态的精度要求
    }
    return 0;
}
