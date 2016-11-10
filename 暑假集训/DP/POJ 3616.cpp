#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 1100;
int N,M,R;
int dp[MAXN+5];

struct COW{
	int start,end,pro;
};
COW cows[MAXN];

int cmp(COW a, COW b){
	if(a.start==b.start)
        return a.end<b.end;
    else
        return a.start<b.start;
}
int main(){
	while(~scanf("%d%d%d",&N,&M,&R)){
		memset(dp,0,sizeof(dp));
		int ans = 0;
		for(int i = 0;i<M;i++){
			scanf("%d%d%d",&cows[i].start,&cows[i].end,&cows[i].pro);

			cows[i].end +=R;
		}
		sort(cows,cows+M,cmp);
		for(int i=0;i<M;i++)
			dp[i] = cows[i].pro;
		for(int i = 1;i<M;i++){
			for(int j=0;j<i;j++){
				if(cows[j].end <= cows[i].start){
                    if(dp[i]<dp[j]+cows[i].pro)
                    {
                        dp[i]=dp[j]+cows[i].pro;
                    }
				}
			}
		}
		for(int i=0;i<M;i++)
			ans = max(ans,dp[i]);
		printf("%d\n",ans);
	}
	return 0;
}
