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
#define CAN(a,b) memset(a,b,sizeof(a))  //大数 memset(a,0x7f,sizeof(a));
#define MAX_N 1000
const int INF = 0x3f3f3f3f;
using namespace std;
int a[MAX_N];
int dp[2000005];
int main()
{
    int k,n;
    int i;
    while(scanf("%d%d",&k,&n)!=EOF)
    {
        int v=0;
        for(i=0;i<n;i++)
        {
            cin>>a[i];
            v=max(a[i],v);
        }
        CAN(dp,-INF);
        dp[0] = 0;
        v*=k;
        for(i=1;i<=v;i++)
        {
            int t = INF;
            for(int j=0;j<n;j++)
                if(i-a[j]>=0)
                    t = min(t,dp[i-a[j]]+1);
            dp[i]=t;
            if(dp[i]<0||dp[i]>k) break;
        }
        cout<<i-1<<endl;
    }
return 0;
}
