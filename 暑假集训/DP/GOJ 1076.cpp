#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <cstdio>
#define MAXN 51
#define MAXV 2000010
const int INF = -0x3f3f3f3f;   //负最大值
using namespace std;
int d[MAXV],a[MAXN];
int main()
{
    int n,k,v,i,j;
    while(scanf("%d%d",&k,&n)==2)
    {
        v=0;
        for(i=0; i<n; i++)
        {
            scanf("%d",&a[i]);
            v = max(v,a[i]);
        }

        v = v * k;  //最大值

        memset(d,INF,sizeof(d));

        d[0]=0;

        for(i=1; i<=v; i++)
        {
            int t=-INF;
            for(j=0; j<n; j++)
            {
                if(i-a[j]>=0)
                {
                    t=min(t,d[i-a[j]]+1);
                }
            }

            d[i]=t;   //i值所需邮票最少t

            if(d[i]<0||d[i]>k) break;
        }
        printf("%d\n",i-1);

    }
    return 0;
}
