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
bool is_prime(int n)
{
    int i;
    if(n==1) return 0;
    for(i=2;i*i<=n;i++)
        if(n%i==0)
            return 0;
    return 1;
}
int solve(int x)
{
    int s=0,i;
    if(is_prime(x)) return 2;
    for(i=1;i*i<=x;i++)
    {
//        printf("%d\n",i);
        if(i*i==x) return ++s;
        if(x%i==0) s+=2;
    }
    return s;
}
int main()
{
    int n,i=1;
    int N;
    scanf("%d",&N);
    while(N--)
    {
        scanf("%d",&n);
        printf("Case #%d:\n%d\n",i++,solve(n*n));
    }

return 0;
}
