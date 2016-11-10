#include<stdio.h>
long long f(long long n,long long m)
{
    long long  i,sum=1,q=1;
    for(i=1;i<=m;i++)
        sum*=i;
    for(i=n;m>0;i--,m--)
        q*=i;
    return q/sum;
}
int main()
{
    long long i,a[25],T,n,m,sum;
    a[0]=0;
    a[1]=0;
    a[2]=1;
    for(i=3;i<=20;i++)
        a[i]=(i-1)*(a[i-1]+a[i-2]);
    scanf("%lld",&T);
    while(T--)
    {
        scanf("%lld%lld",&n,&m);
       printf("%lld\n",a[m]*f(n,m));
    }
    return 0;
}
