#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>
#include <iostream>
using namespace std;
const int maxn = 1000000+10;
int P;
int a[maxn];
int main()
{
    while(~scanf("%d",&P)){
        set<int> all;
        for(int i=0;i<P;i++){
            scanf("%d",&a[i]);
            all.insert(a[i]);  //去重，升序排序,支持集合的交(set_intersection),差(set_difference) 并(set_union)，对称差(set_symmetric_difference)
        }
        int n = all.size();
        int s = 0,t = 0,num = 0;
        map<int ,int > counts;
        int res = P;
        for(;;){
            while(t<P && num<n){
                if(counts[a[t++]]++ == 0){
                    num++;
                }
            }
            if(num<n) break;
            res = min(res,t-s);
            if(--counts[a[s++]] == 0){
                num--;
            }
        }
        printf("%d\n",res);
    }
    return 0;
}
