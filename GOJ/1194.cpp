#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn=10001;
const int maxm=101;
const int inf=1e9+5;
int dp[maxn][maxm];//back maxm
int c[maxn];
int n,m;
int main(){
    //freopen("in.txt","r",stdin);
    //freopen("02.txt","w",stdout);
    while(scanf("%d%d",&n,&m)==2){
        //memset(dp,0,sizeof(dp));
        for(int i=0;i<n;i++)scanf("%d",c+i);
        for(int i=0;i<m;i++){
            for(int j=0;j<i;j++){
                dp[i][i-j]=c[i]+c[j];//g[i-j]=min(dp[i][j],g[i-j]);
            }
        }
        for(int j=1;j<n;j++){
            int minn=inf;
            for(int i=min(n,j+m)-1;i>j&&i>=m;i--){
                minn=min(dp[j][m+j-i],minn);
                dp[i][i-j]=minn+c[i];
            }
        }
        int ans=inf;
        for(int i=n-m+1;i<n;i++){
                for(int j=min(m-1,i-n+m);j>0;j--)
            ans=min(ans,dp[i][j]);
        }
        printf("%d\n",ans);
    }
    return 0;
}
