#include<stdio.h>
#include <math.h>
long long jc(int x)
{
    int i;
    long long s=1;
    for(i=1;i<=x;i++)
        s*=i;
    return s;
}
int main()
{
    long long i,a[25],n,m,sum;
    float T;
    a[0]=0;
    a[1]=0;
    a[2]=1;
    for(i=3;i<=20;i++)
        a[i]=(i-1)*(a[i-1]+a[i-2]);
    while(scanf("%lld",&n)!=EOF)
    {
        m = n;
        T=((float)a[m]/(float)jc(n))*100;
        printf("%.2f%%\n",T);
    }
    return 0;
}
