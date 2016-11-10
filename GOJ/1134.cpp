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
using namespace std;
#define LL long long
#define CAN(a,b) memset(a,b,sizeof(a));
#define MAX_N 1005
const int INF = 0x3f3f3f3f;  //无穷大
int dp[MAX_N+1][MAX_N*100+1];
int w[MAX_N];
int v[MAX_N];
int main()
{
    int n,W;
    while(scanf("%d",&n)!=EOF)
    {
        scanf("%d",&W);
        for(int i=0;i<n;i++)
            scanf("%d%d",&w[i],&v[i]);
        fill(dp[0],dp[0]+MAX_N*100+1,INF);
        dp[0][0]=0;
        for(int i=0;i<n;i++)
            for(int j=0;j<=MAX_N*100;j++)
        {
            if(j<v[i])
                dp[i+1][j]=dp[i][j];
            else dp[i+1][j] = min(dp[i][j],dp[i][j-v[i]]+w[i]);
        }
        int res = 0;
        for(int i=0;i<=MAX_N*100;i++)
            if(dp[n][i]<=W)
                res = i;
        printf("%d\n",res);
    }
return 0;
}
