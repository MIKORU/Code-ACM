#include <cstdio>
#include <cstring>
#include <utility>
#include <algorithm>
using namespace std;
const int maxn = 505;
int n;
int dp[maxn][maxn];
int maps[maxn][maxn];
int main()
{
    while(~scanf("%d",&n)){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=i;j++){
                scanf("%d",&maps[i][j]);
            }
        }
        int res = 0 ;
        for(int i=2;i<=n;i++){
            dp[i][1] = dp[i-1][1]+maps[i][1];
            for(int j=2;j<i;j++){
                dp[i][j] = max(dp[i-1][j-1],dp[i-1][j])+maps[i][j];
            }
            dp[i][i] = dp[i-1][i-1]+maps[i][i];
            for(int k=1;k<=i;k++){
                res = max(res,dp[i][k]);
            }
        }
        printf("%d\n",res+maps[1][1]);
    }
    return 0;
}
