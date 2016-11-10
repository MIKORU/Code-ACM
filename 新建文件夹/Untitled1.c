#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>

#define INF 0x3f3f3f3f

int main()
{
    long long a,b;
    while(scanf("%lld%lld",&a,&b)==2)
    {
        printf("%lld\n",a+b);
    }
    return 0;
}

