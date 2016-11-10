#include <cstdio>
using namespace std;
const int MAXN = 1000000;
const int MOD = 1000000000;
int ans[MAXN+5];
int main(){
	int N;
	ans[1] = 1;
	ans[2] = 2;
	for(int i=3;i<=MAXN;i++){
		if(i&1)
			ans[i] = ans[i-1];
		else{
			ans[i] = (ans[i-1]+ans[i/2])%MOD;
		}
	}
	while(~scanf("%d",&N)){
		printf("%d\n",ans[N]);
	}
	return 0;
}
