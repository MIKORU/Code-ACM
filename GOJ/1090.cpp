//#include <iostream>
//#include <math.h>
//#include <string.h>
//#include <stdio.h>
//#define MAX_N 100005
//using namespace std;
//int dp[MAX_N];
//int w[MAX_N];
//int main()
//{
//    int n,W;
//    while(cin>>n)
//    {
//        memset(dp,0,sizeof(dp));
//        int sum = 0;
//        for(int i=0;i<n;i++)
//        {
//            cin>>w[i];
//            sum+=w[i];
//        }
//        W=sum/2;
//        for(int i=0;i<n;i++)
//        for(int j=W;j>=w[i];j--)
//            dp[j]=max(dp[j],dp[j-w[i]]+w[i]);
//        cout<<sum-2*dp[W]<<endl;
//    }
//    return 0;
//}
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <map>
#include <set>

using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;

int a[110];
int dp[110][500010];
int main()
{

    int n;
    while(scanf("%d", &n) != EOF)
    {
        memset(a, 0, sizeof(a));
        memset(dp, 0, sizeof(dp));
        int sum = 0;
        int m = 0;
        for(int i = 1; i <= n; ++i)
        {
            scanf("%d", a+i);
            sum += a[i];
        }
        m = sum/2;
        for(int i = 1; i <= n; ++i)
        {
            for(int j = 0; j <= m; ++j)
            {
                if(j-a[j] >= 0)
                    dp[i+1][j] = max(dp[i-1][j-a[i]]+a[i], dp[i-1][j]);
                else

                    dp[i+1][j] = dp[i-1][j];
            }
        }
        //cout << dp[n][m] << endl;
        if((sum - 2*dp[n][m]) < 0)
            printf("%d\n", -(sum - 2*dp[n][m]));
        else
            printf("%d\n", (sum - 2*dp[n][m]));

    }

    return 0;
}
