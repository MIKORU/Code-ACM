#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>
#include<map>
#include<set>
#include<vector>
#include<iostream>
using namespace std;
#define N 100005

int main()
{
    long long a,ans;
    while(~scanf("%lld",&a))
    {
        ans=0;
        int t=1;
        while(a)
        {
            ans+=(a+1)/2*t;
            t*=2;
            a-=(a+1)/2;
        }
        printf("%lld\n",ans);
    }
	return 0;
}
