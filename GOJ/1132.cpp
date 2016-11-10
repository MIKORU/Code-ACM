#include <stdio.h>
#include <iostream>
#include <math.h>
#include <string.h>
#define MAX_N 1000005
using namespace std;
const int INF = -0x3f3f3f3f;
int dp[MAX_N];
int w[MAX_N];
int v[MAX_N];
int main()
{
    int n,W;
    while(cin>>n)
    {
        cin>>W;
        for(int i=0;i<n;i++)
            cin>>w[i]>>v[i];
        memset(dp,INF,sizeof(dp));
        dp[0]=0;
        for(int i=0;i<n;i++)
            for(int j=W;j>=w[i];j--)
                dp[j]=max(dp[j],dp[j-w[i]]+v[i]);
        if(dp[W]>0)
            cout<<dp[W]<<endl;
        else
            cout<<-1<<endl;
    }
    return 0;
}
