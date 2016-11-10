#include <cstdio>
#include <cstring>
#include <utility>
#include <algorithm>
using namespace std;
int const INF = 0x3f3f3f3f;
int E,F,N;
int dp[10005];
pair<int ,int >coin[505];
int main()
{
    int T;
    scanf("%d",&T);
    while(T--){
        memset(dp,INF,sizeof(dp));
        scanf("%d%d%d",&E,&F,&N);
        int last = F-E;
        for(int i=0;i<N;i++){
            scanf("%d%d",&coin[i].first,&coin[i].second);
        }
        dp[0] = 0;
        for(int i=0;i<N;i++){
            for(int j=coin[i].second;j<=last;j++){
                    dp[j] = min(dp[j],dp[j-coin[i].second]+coin[i].first);
            }
        }
        if(dp[last]!=INF)
            printf("The minimum amount of money in the piggy-bank is %d.\n",dp[last]);
        else printf("This is impossible.\n");
    }
    return 0;
}
