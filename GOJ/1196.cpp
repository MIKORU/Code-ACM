#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
#define A 100010
#define N 20010
using namespace std;
int C[A];
int c[A],d[A];//c[i]表示左边比a[i]小的人数目，d[i]表示右边比a[i]小的人的数目
int a[N];
int maxa;
int lowbit(int x)
{return x&-x;}
int sum(int x)
{
    int ret=0;
    while(x>0)
    {
        ret+=C[x];
        x-=lowbit(x);
    }
    return ret;
}
void add(int x,int d)
{
    while(x<=maxa)
    {
        C[x]+=d;
        x+=lowbit(x);
    }
}
void Init()
{
    memset(c,0,sizeof(c));
    memset(C,0,sizeof(C));
    memset(d,0,sizeof(d));
    memset(a,0,sizeof(a));
}
int main()
{
    int T,n;
    scanf("%d",&T);
        while(T--)
        {
            Init();
            scanf("%d",&n);
            maxa=0;
            for(int i=1;i<=n;i++)
            {
                scanf("%d",&a[i]);
                maxa=max(a[i],maxa);
            }  //左边比a[i]小的人的数目
            for(int i=1;i<=n;i++)
            {
                add(a[i],1);
                c[i]=sum(a[i]-1);
            }
            memset(C,0,sizeof(C));  //右边比a[i]小的人的数目
            for(int i=n;i>=1;i--)
            {
                add(a[i],1);
                d[i]=sum(a[i]-1);
            }
            long long ans=0;
            for(int i=1;i<=n;i++)
            {
                ans+=(long long)c[i]*(n-i-d[i])+(long long)(i-1-c[i])*d[i];
            }
            printf("%lld\n",ans);
        }

    return 0;
}
