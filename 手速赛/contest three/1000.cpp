#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h> // È¡¾ø¶ÔÖµ //
#include <iostream>
#include <algorithm>
#include <stack>
#include <map>
#include <set>
#include <utility> //pair<int int >a[?]
using namespace std;
#define N
long long quickpow(long long m,long long n,long long k)/** m*n%k **/
{
    long long b = 0,r = m;
    while (n )
    {
        if (n & 1)
            b = (b+r)%k;
        r = (r+r)%k;
        n>>=1 ;
    }
    return b;
}
int main()
{
    long long a,b,c,m;
    long long T;
    scanf("%d",&T)
        while(T--)
        {
            scanf("%lld%lld%lld%lld",&a,&b,&c,&m);
            printf("%lld\n",(quickpow(a,b,m)-c%m+m)%m);
        }
return 0;
}
