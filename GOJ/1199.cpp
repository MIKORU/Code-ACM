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
#define CAN(a,b) memset(a,b,sizeof(a))
#define MAX_N 100000
int a[MAX_N];
int m[MAX_N];
int dp[MAX_N+1];
int main()
{
    int n,k;
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=0;i<n;i++)
            scanf("%d%d",&a[i],&m[i]);
        scanf("%d",&k);
        CAN(dp,-1);
        dp[0] = 0;
        for(int i=0;i<n;i++)
            for(int j=0;j<=k;j++)
            {
                if(dp[j]>=0)
                    dp[j] = m[i];
                else if(j<a[i]||dp[j-a[i]]<=0)
                        dp[j] = -1;
                else dp[j]=dp[j-a[i]]-1;
            }
        if(dp[k]>=0)
            printf("Yes\n");
        else printf("No\n");
    }
return 0;
}
