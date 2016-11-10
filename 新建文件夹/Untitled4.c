#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>

#define INF 0x3f3f3f3f

int dp[100][100];

int max(int a,int b)
{
    if(a>b)
        return a;
    return b;
}

int main()
{
    int i,j,k,t=1;
    int m,n;
    int a[100][100];
    while(scanf("%d%d",&m,&n)==2)
    {
        for(i=0;i<m;i++)
            for(j=0;j<n;j++)
            scanf("%d",&a[i][j]);
        memset(dp,0,sizeof(dp));
        dp[0][0]=a[0][0];
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                if(i-1<0&&j-1>=0)
                    dp[i][j]=dp[i][j-1]+a[i][j];
                else if(j-1<0&&i-1>=0)
                    dp[i][j]=dp[i-1][j]+a[i][j];
                else if(i-1>=0&&j-1>=0)
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1])+a[i][j];
            }
        }
        printf("Case %d: %d\n",t++,dp[m-1][n-1]);
    }
    return 0;
}
