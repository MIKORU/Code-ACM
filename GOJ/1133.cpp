#include <iostream>
#include <string.h>
#include <stdio.h>
#define MAX_N 1000005
using namespace std;
int dp[MAX_N+1];
int w[MAX_N];
int v[MAX_N];
int main()
{
//    ios::sync_with_stdio(0);
    int n,W;
    while(cin>>n)
    {
        memset(dp,0,sizeof(dp));
        cin>>W;
        for(int i=0;i<n;i++)
            cin>>w[i]>>v[i];
        for(int i=0;i<n;i++)
            for(int j=w[i];j<=W;j++)
                dp[j]=max(dp[j],dp[j-w[i]]+v[i]);
        cout<<dp[W]<<endl;
    }
    return 0;
}
