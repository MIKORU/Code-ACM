#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int dp[1005];
int a[1005];
int main(){
    int n;
    while(~scanf("%d",&n)){
        if(!n) break;
        for(int i=0;i<n;i++){
            scanf("%d",&a[i]);
        }
        int res = 0;
        for(int i=0;i<n;i++){
            dp[i] = a[i];
            for(int j=0;j<i;j++){
                if(a[i]>a[j]){
                    dp[i] = max(dp[i],dp[j]+a[i]);
                }
            }
            res = max(res,dp[i]);
        }
        printf("%d\n",res);
    }
    return 0;
}
