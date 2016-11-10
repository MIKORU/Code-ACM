#include <stdio.h>
#include <string.h>
int p[1000000];
long long i,n,r,a,b,c,d,T,t;
int main()
{
    scanf("%lld",&T);
    while(T--)
    {
        t=0;
        r=0;
        memset(p,0,sizeof(p));
        scanf("%lld%lld%lld%lld%lld",&n,&a,&b,&c,&d);
        p[d]=1;
        for(i=1;i<n;i++)
        {
            d=(a*d*d + b*d + c)%1000000;
            p[d]++;
        }
        for(i=999999;i>=0;i--)
            if(p[i]%2!=0)
            {
                if(t)
                    r=r-i;
                else
                    r=r+i;
                t = !t;
            }
        printf("%lld\n",r);
    }
return 0;
}

