#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <math.h>
using namespace std;

int a[30][20];
int dp[30][30];

int main()
{
    int n,k;
    while(scanf("%d%d",&n,&k)==2)
    {
        for(int i=0;i<n;i++)
          for(int j=0;j<k;j++)
            scanf("%d",&a[i][j]);
        for(int j=0;j<k;j++)dp[0][j]=0;
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<k;j++)
            {
                dp[i][j]=dp[i-1][0]+abs(a[i][j]-a[i-1][0]);
                for(int x=1;x<k;x++)
                  dp[i][j]=min(dp[i][j],dp[i-1][x]+abs(a[i][j]-a[i-1][x]));
            }
        }
        int ans=dp[n-1][0];
        for(int i=1;i<k;i++)ans=min(ans,dp[n-1][i]);
        printf("%d\n",ans);
    }
    return 0;
}