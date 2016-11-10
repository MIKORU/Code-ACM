#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h> // È¡¾ø¶ÔÖµ //
#include <iostream>
#include <algorithm>
#include <stack>
#include <map>
#include <set>
#include <utility>
using namespace std;
#define N 10000000
long long  a[N],b[N],c[N];
int main()
{
    long long  n,m,i,j,x,y;
    while(scanf("%lld%lld",&n,&m)!=EOF)
    {
        int flag=0;
        for(i=0;i<n;i++)
            scanf("%lld%lld%lld",&a[i],&b[i],&c[i]);
        for(i=0;i<m;i++)
            {
                scanf("%lld%lld",&x,&y);
                for(int j=0;j<n;j++)
                    if(x*a[j]+y*b[j]+c[j]==0)
                        {flag++;break;}
            }
        if(flag == m)
            printf("duang\n");
        else printf("eat your brain\n");
    }
return 0;
}
