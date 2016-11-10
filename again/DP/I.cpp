#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int INF = 0x3f3f3f3f;
const int maxn = 300005;
int dp[maxn];
int n;
int main()
{
    while(~scanf("%d",&n)){
        memset(dp,0,sizeof(dp));
        int flag;
        int x;
        int res = 0;
        for(int i=0;i<n;i++){
            scanf("%d",&x);
            flag = 1;
            for(int j=0;j<=res;j++){
                if(dp[j]>x){
                    dp[j] = x;
                    flag  = 0;
                    break;
                }
            }
            if(flag){
                res++;
                dp[res] = x;
            }
        }
        printf("%d\n",res);
    }
    return 0;
}
