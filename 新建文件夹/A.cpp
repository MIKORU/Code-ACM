#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
const int INF = 0x3f3f3f3f;
const int maxn = 100000+5;
int a[maxn];
int cmp(int a,int b)
{
    return a<b;
}
int main()
{
    int i,j,k,n,t;
    int ca=1;
    long long maxx,minx;
    scanf("%d",&t);
    while(t--)
    {scanf("%d",&n);
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);

    sort(a,a+n,cmp);
    maxx=1;
    minx=1;
    int a0=a[0],b=a[n-1];
    for(i=1;i<n;i++)
        {
            maxx*=a0*a[i];
            a0+=a[i];
        }
    for(i=n-2;i>=0;i--)
    {
        minx*=b*a[i];
        b+=a[i];
    }
    printf("Case #%d: %lld\n",ca++,maxx-minx);}
}

