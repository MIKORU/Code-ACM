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
    long long a,b,n,m;
    while(~scanf("%lld%lld",&n,&m))
    {
        a=1;
        for(int i=1;i<=m;i++)
        {
            a*=n;
            a%=100000000;
        }
        a%=1000;
        printf("%03lld\n",a);
    }
	return 0;
}
