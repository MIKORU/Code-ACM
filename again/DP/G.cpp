#include <cstdio>
#include <cstring>
#include <utility>
#include <algorithm>
using namespace std;
const int maxn = 100005;
int n;
int dp[maxn][15];
int maps[maxn][15];
int main()
{
    while(~scanf("%d",&n)){
        memset(dp,0,sizeof(dp));
        memset(maps,0,sizeof(maps));
        if(!n) break;
        int time = 0;
        for(int i=0;i<n;i++){
            int x,T;
            scanf("%d%d",&x,&T);
            ++maps[T][x];
            time = max(T,time);
        }
        dp[1][4] = maps[1][4];
        dp[1][5] = maps[1][5];
        dp[1][6] = maps[1][6];
        int res = 0;
        for(int i=2;i<=time;i++){
            for(int j=0;j<=10;j++){
                dp[i][j] = max(dp[i-1][j+1],max(dp[i-1][j-1],dp[i-1][j]))+maps[i][j];
            }

        }
        for(int i=0;i<=10;i++)
            res = max(dp[time][i],res);
        printf("%d\n",res);
    }
    return 0;
}
