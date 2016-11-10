#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
#include<iostream>
using namespace std;
#define N 100005
#include<set>


int main()
{
    int n,i;
    long long s;
    char a[15],b[15];
    while(~scanf("%d",&n))
    {
        scanf("%s%s",a,b);
        s=0;
        for(i=0;i<n;i++)
        {
            s+=(long long)(a[i]*b[i]);
        }
        printf("%lld\n",s);
    }
    return 0;
}
