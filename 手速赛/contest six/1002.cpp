#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h> // 取绝对值
#include <iostream>
#include <algorithm>
#include <stack>
#include <map>
#include <set>
#include <utility> //pair类
#define LL long long
using namespace std;
#define LL long long
#define CAN(a,b) memset(a,b,sizeof(a));
#define MAX_N 100000
int N,L[MAX_N];
int solve()
{
    int ans = 0;
    while(N>1)
    {
        int mii1=0,mii2 = 1;
        if(L[mii1]>L[mii2])
            swap(mii1,mii2);
        for(int i=2;i<N;i++)
        {
            if(L[i]<L[mii1])
            {
                mii2 = mii1;
                mii1 = i;
            }
            else if(L[i]<L[mii2])
                mii2 = i;
        }
        int t = L[mii1]+L[mii2];
        ans+=t;
        if(mii1 == N-1)
            swap(mii1,mii2);
        L[mii1] = t;
        L[mii2] = L[N-1];
        N--;
    }
    return ans;
}
int main()
{
    int S;
    while(scanf("%d",&S)!=EOF)
    {
        scanf("%d",&N);
        for(int i=0;i<N;i++)
        {
            scanf("%d",&L[i]);
            if(i>0)
                L[i]=L[i]-L[i-1];
        }
        L[N]=S-L[N-1];
        N++;
        printf("%d\n",solve());

    }
return 0;
}
