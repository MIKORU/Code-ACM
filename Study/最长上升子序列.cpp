#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h> // 取绝对值
#include <iostream>
#include <algorithm>
#include <stack>
#include <map>
#include <set>
#include <utility> //pair类
#define LL long long
#define LL long long
#define CAN(a,b) memset(a,b,sizeof(a))
#define MAX_N 10005
const int INF = 0x3f3f3f3f;
using namespace std;
int dp[MAX_N];
int n;
int a[MAX_N];
void solve()
{
    fill(dp,dp+n,INF);
    for(int i=0;i<n;i++)
    {
        *lower_bound(dp,dp+n,a[i]) = a[i];
    }
    printf("%d\n",lower_bound(dp,dp+n,INF)-dp);
}
int main()
{
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=0;i<n;i++)
            scanf("%d",&a[i]);
        solve();
    }
return 0;
}
