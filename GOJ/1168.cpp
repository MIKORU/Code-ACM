#include <stdio.h>
#define N 65535
int main()
{
    long long a,b,c;
    while(scanf("%lld%lld%lld",&a,&b,&c)!=EOF)
    {
        printf("%lld\n",(a+b)*N%c);
    }
    return 0;
}
