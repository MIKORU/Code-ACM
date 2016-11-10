#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <stack>
#include <map>
#include <set>
using namespace std;
long long  a[100005];
int main()
{
    long long  N,M,sum,i,j,t,k;
    while(scanf("%lld",&N)!=EOF)
    {
//        memset(a,0,sizeof(a));
        j=0;
        while(N--)
        {

            sum=0;
            scanf("%lld",&M);
            for(i=0;i<M;i++)
            {
                scanf("%lld",&t);
                sum+=t;
            }
            a[j]=sum;
            j++;

        }
//        printf("\n");
        for(i=0;i<j-1;i++)
            printf("%lld\n\n",a[i]);
        printf("%lld\n",a[j-1]);
    }
    return 0;
}
