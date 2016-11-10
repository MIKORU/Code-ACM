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
#define N 20
long long a[N];
long long solve(long long a,long long b)
{
    int j;
    long long s=1;
    for(j=0;j<b;j++)
    {
        s*=a;
        a--;
    }
    return s;
}
long long max_div(long long a,long long b)
{
    long long r;
    while((r = a%b)!=0)
    {
        a = b;
        b = r;
    }
    return b;
}
int main()
{
//    freopen("00.txt","r",stdin);
//    freopen("01.txt","w",stdout);
    long long  n,x,m;
    while(scanf("%lld%lld%lld",&n,&x,&m)!=EOF)
    {
        if(m==0)
        {
            printf("0\n");
            continue;
        }
        long long a=solve((n-x),(m-1))*x;
        long long b =solve(n,m);
        long long d = max_div(a,b);
        if(a==0||b==0) printf("0\n");
        else if((a/d) == (b/d)) printf("%d\n",b/d);
        else printf("%lld/%lld\n",a/d,b/d);
    }
return 0;
}
