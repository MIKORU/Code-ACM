#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX = 10010000;
int par[MAX];  //父节点
int ranks[MAX]; //树高度
int ans ;
void init(){
	for(int i=1;i<=MAX;i++){
		par[i] = i;
		ranks[i] = 1;
	}
}
int finds(int x){
	if(par[x] == x)  //树的根
		return x;
	else
		return par[x] = finds (par[x]);
}
int unite(int x,int y){
	x = finds(x);
	y = finds(y);
	if(x==y) return 0;
	if(ranks[x] < ranks [y]){  //小向大连边
		par[x] = y;
		ranks[y] +=ranks[x];
		ans = max(ranks[y],ans);
	}
	else{
		par[y] = x;
		ranks[x] += ranks[y];
		ans = max(ranks[x],ans);
		if(ranks[x] == ranks[y]){
			ranks[x]++;
		}
	}
}
int main(){
	int n;
	while(~scanf("%d",&n)){
		ans = 0;
		init();
		if(!n){
            printf("1\n");
            continue;
		}
		while(n--){
			int a,b;
			scanf("%d%d",&a,&b);
			unite(a,b);
		}
		printf("%d\n",ans);
	}
	return 0;
}
