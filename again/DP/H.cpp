#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 2005;
int signal[maxn];
int unit[maxn];
int H,M,S;
int dp[maxn];
char t[5];
void conver(int time){
    H = (time/3600+H)%24;
    M = (time/60)%60;
    S = (time)%60;
    if(H > 12){
        strcpy(t,"pm");
    }
    H = H%12;
}
int main()
{
    int N,K;
    scanf("%d",&N);
    while(N--){
        memset(dp,0,sizeof(dp));
        H = 8;
        M = S = 0;
        strcpy(t,"am");
        scanf("%d",&K);
        for(int i=0;i<K;i++){
            scanf("%d",&signal[i]);
        }
        for(int i=1;i<K;i++){
            scanf("%d",&unit[i]);
        }
        dp[0] = signal[0];
        for(int i=1;i<K;i++){
            dp[i] = min(dp[i-1]+signal[i],dp[i-2]+unit[i]);
        }
        conver(dp[K-1]);
        printf("%02d:%02d:%02d %s\n",H,M,S,t);
    }
    return 0;
}
