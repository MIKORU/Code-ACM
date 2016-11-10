#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <cstdio>
#define MAXN 105000
#define MAXP 10000050
const int INF = -0xfffffff;   //重点在这..一开始开的太小
using namespace std;
int a;
int main()
{

	int T,n,sum,l,ans;
	int pre ,end;
	scanf("%d",&T);
	int cas;
	for(cas=1;cas<=T;cas++){
		ans= sum = INF;
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			scanf("%d",&a);
			if(sum + a < a){
				sum = a;
				l = i;
			}
			else sum += a;
			if(ans < sum){  //有更新的时候把端点也更新上去
				ans = sum;
				pre = l;
				end = i;
			}
		}
		printf("Case %d:\n%d %d %d\n",cas,ans,pre+1,end+1);
		if(cas < T) putchar('\n');
	}
	return 0;
}
