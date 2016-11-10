#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <utility>
using namespace std;
const int MAXN = 3000;
int C,L;
typedef pair<int ,int > PA;
PA SPF[MAXN];
PA bottles[MAXN];
int main(){
	while(~scanf("%d%d",&C,&L)){
		int ans=0;
		priority_queue<int,vector<int>,greater<int> >que;
		for(int i=0;i<C;i++){
			scanf("%d%d",&SPF[i].first,&SPF[i].second);
        }
		for(int i=0;i<L;i++){
			scanf("%d%d",&bottles[i].first,&bottles[i].second);
		}
		sort(SPF,SPF+C);
		sort(bottles,bottles+L);
		int j =0;
		for(int i=0;i<L;i++){
            for(;j<C;j++){   //这里的BUG找了很久很久
                if(SPF[j].first <= bottles[i].first){
                    que.push(SPF[j].second);
                }
                else break;
            }
            while(!que.empty()&&bottles[i].second){
                int p = que.top();
                que.pop();
                if(bottles[i].first <= p){
                    ans++;
                    bottles[i].second--;
                }
            }
		}
		printf("%d\n",ans);
	}
	return 0;
}
