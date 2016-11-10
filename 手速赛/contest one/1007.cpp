#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h> // È¡¾ø¶ÔÖµ //
#include <iostream>
#include <algorithm>
#include <stack>
#include <map>
#include <set>
using namespace std;
#define MAX_N 2147483647
long long f(long long n)
{
    long long  s=0;
    while(n)
    {
         s=s*10+n%10;
         n=n/10;
    }
    return s;
}
int main()
{
    long long  n,t;
    long long s;
    while(scanf("%lld",&n)!=EOF)
    {
        s=0;
        if(n>0)
        {
            s=f(n);

            if(s>2147483647)
                s=0;
        }
        else
        {
            n=-n;
            s=f(n);
//            printf("%d\n",s);
            if(s>2147483648)
                s=0;
            else s=-s;
        }
        printf("%d\n",s);
    }
return 0;
}
