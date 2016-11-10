#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
const int MAXN = 1000005;
int n,S;
int a[MAXN];
int sum[MAXN];
void solve(){
	for(int i=0;i<n;i++){
		sum[i+1] = sum[i] + a[i];
	}
	if(sum[n]<S){
		printf("0\n");
		return ;
	}
	int res = n;
	for(int s=0;sum[s]+S<=sum[n];s++){
		int t = lower_bound(sum+s,sum+n,sum[s]+S)-sum;
		res = min(res,t-s);
	}
	printf("%d\n",res);
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&S);
		for(int i=0;i<n;i++){
			scanf("%d",&a[i]);
		}
		solve();
	}
	return 0;
}
