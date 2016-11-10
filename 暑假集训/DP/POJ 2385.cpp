/**测试数据：
7 2
2
1
1
2
2
1
1

6
**/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 1100;
int apples[MAXN][2];
int dp[MAXN+10][MAXN+10];
int main()
{
	int W,T;
	while(~scanf("%d%d",&T,&W)){
        memset(dp,0,sizeof(dp));
        int ans =0,a = 0;
		for(int i=1;i<=T;i++){
            int location;
			scanf("%d",&location);
			apples[i][location-1] = 1;
		}
		for(int i=1;i<=T;i++){
            dp[i][0] = dp[i-1][0]+apples[i][0];  //前一种解法忘了这个
            for(int j=1;j<=W;j++){
//              a = j%2?(apples[i]-1) : (2 - apples[i]);  //j打成W我也是够拼的
//            	dp[i][j] = max(dp[i-1][j],dp[i-1][j-1])+a;
            	dp[i][j] = max(dp[i-1][j],dp[i-1][j-1])+apples[i][j%2];

			}
		}
		for(int i=0;i<=W;i++)
			ans = max(ans,dp[T][i]);
		printf("%d\n",ans);
	}
	return 0;
}
