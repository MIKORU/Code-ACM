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
#define MAX_N 1000005
int a[MAX_N];
bool isprime(int n)
{
    int i;
    if(n!=2&&n%2==0) return 0;
    for(i=3;i*i<=n;i+=2)
        if(n%i==0)
            return 0;
    return 1;
}
int main()
{
    int n,k;
    for(int i=2;i<=MAX_N-5;i++)
        a[i]=isprime(i);
    while(scanf("%d",&n)!=EOF)
    {
        k=1;
        for(int i=2;i<=n/2;i++)
        {
            if(a[i]&&a[n-i])
            {
                k = 0;
                printf("%d %d\n",i,n-i);
            }
        }
        if(k) printf("No\n");
    }
return 0;
}
