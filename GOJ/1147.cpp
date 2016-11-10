#include <stdio.h>
#include <string.h>
#define N 100001
int s[N];
int ys(int x)
{
    int i,sum=1;
    for(i=2;i*i<=x;i++)
        if(x%i==0)
            sum+=i+x/i;
    if(sum==i)
        sum=0;
    return sum;
}
int main()
{
//    freopen("00.txt","r",stdin);
//    freopen("01.txt","w",stdout);
    int j,k,a,b,i,f;
    memset(s,0,sizeof(s));
    for(j=1;j<N;j++)
        if(j==ys(ys(j))&&j<ys(j))
            s[j]=ys(j);
    while(scanf("%d%d",&a,&b)!=EOF)
    {
        if(a>b)
        {
            a ^= b;
            b ^= a;
            a ^= b;
        }
        f=0;
        for(i=a;i<=b;i++)
            if(s[i]!=0&&s[i]<=b)
                {f=1;printf("%d %d\n",i,s[i]);}
        if(f==0) printf("NO\n");
    }
    return 0;
}
