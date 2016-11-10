#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
long long quickpow(long long m,long long n,long long k)
{
    long long b = 1;
    while (n > 0)
    {
          if (n & 1)
             b = (b*m)%k;
          n = n >> 1 ;
          m = (m*m)%k;
    }
    return b;
}
int main()
{
    long long  a,b,k;
    k=1000000009;
    while(scanf("%lld%lld",&a,&b)!=EOF)
    {
        printf("%lld\n",quickpow(a,b,k));
    }
    return 0;
}
