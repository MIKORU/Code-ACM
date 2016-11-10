#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <utility>
using namespace std;
const int MAX_X = 100000;
int N,S[MAX_X],T[MAX_X];

pair<int, int> itv[MAX_X];

void solve(){
    for(int i= 0;i<N;i++)
    {
        itv[i].first = T[i];
        itv[i].second = S[i];
    }
    sort(itv,itv+N);
    int ans = 0,t = 0;
    for(int i=0;i<N;i++)
    {
        if(t<=itv[i].second)
        {
            ans++;
            t = itv[i].first;
        }
    }
    printf("%d\n",ans);
}
int main()
{
//    freopen("00.txt","r",stdin);
//    freopen("01.txt","w",stdout);
    while(~scanf("%d",&N)){
        for(int i=0;i<N;i++)
            scanf("%d%d",&S[i],&T[i]);
        solve();
    }
    return 0;
}
