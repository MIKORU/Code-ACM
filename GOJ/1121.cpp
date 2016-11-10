#include <stdio.h>
#define N 3336
long long  a[N];
int main()
{
    //freopen("03.txt","w",stdout);
    long long i,n;
    a[0]=0;
    a[1]=1;
    a[2]=1;
    for(i=3;i<N;i++)
        a[i]=(a[i-1]+a[i-2])%10009;
    while(scanf("%lld",&n)!=EOF)
    {
        printf("%lld\n",a[(n-1)%3336+1]);
    }
    return 0;
}
