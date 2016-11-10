#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 150;
const int INF = 10000000;
int L,N,C,T;
int VR,VT1,VT2;
int d[MAXN];
double dp[MAXN];
int main(){
    while(~scanf("%d",&L)){
        double lt = 0;
        scanf("%d%d%d%d%d%d",&N,&C,&T,&VR,&VT1,&VT2);
        double timer = L*1.0/VR;
        d[0] = 0;
        d[N+1] = L;
        for(int i=1;i<=N;i++){
            scanf("%d",&d[i]);
        }
        for(int i=1;i<=N+1;i++){
            double timet = INF;
            for(int j=0;j<i;j++){
                double temp;
                if(d[i] - d[j] >= C)
                    temp=dp[j]+C*1.0/VT1+(d[i]-d[j]-C)*1.0/VT2;
                else
                    temp=dp[j]+(d[i]-d[j])*1.0/VT1;
                if(j>0)
                    temp+=T;
                timet = min(timet,temp);
            }
            dp[i] = timet;
        }
        if(dp[N+1] < timer)
            printf("What a pity rabbit!\n");
        else  printf("Good job,rabbit!\n");
    }
    return 0;
}
