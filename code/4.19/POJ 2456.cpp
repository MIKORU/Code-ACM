#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 100010;
const int INF = 5100002;
int N,C;
int x[maxn];
bool can(int l){
    int last = 0;
    for(int i=1;i<C;i++){
        int cur = last+1;
        while(cur<N && x[cur]-x[last]<l){
            cur++;
        }
        if(cur == N) return false;
        last = cur;
    }
    return true;
}
int main()
{
    while(~scanf("%d%d",&N,&C)){
        for(int i=0;i<N;i++){
            scanf("%d",&x[i]);
        }
        sort(x,x+N);
        int lm = 0;
        int rm = INF;
        int mid;
        for(int i=0;i<50;i++){
            mid = (lm+rm)/2;
            if(can(mid))
                lm = mid;
            else rm = mid;
        }
        printf("%d\n",lm);
    }
    return 0;
}
