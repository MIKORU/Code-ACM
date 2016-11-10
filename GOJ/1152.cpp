#include <stdio.h>
int s(long long x)
{
    long long i;
    for(i=2;i*i<=x;i++)
        if(x%i==0)
            return 0;
        return 1;
}
int main()
{
    int f,i=1;
    long long n;
    while(scanf("%lld%d",&n,&f)!=EOF)
    {
        if(n==0&&f==0)
            break;
        if(f>0)
        {
            while(n++)
            {
                if(s(n))
                    break;

            }

        }
        if(f<0)
        {
            while(n--)
            {
                if(s(n))
                    break;
            }
        }
        printf("Case #%d: %lld\n",i,n);
        i++;
    }
    return 0;
}
