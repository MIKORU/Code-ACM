#include <stdio.h>
#include <math.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <stack>
#define N 10005
#define V 1005
#define max(a,b) a>b?a:b
int a[N][V];
int v[N],w[N];
using namespace std;
int main()
{
    //freopen("00.txt","r",stdin);
    //freopen("01.txt","w",stdout);
    int n,W,i,j;
    while(scanf("%d%d",&n,&W)!=EOF)
    {
        for(i=1;i<=n;i++)
            scanf("%d%d",&w[i],&v[i]);
        memset(a,0,sizeof(a));
        for(i=1;i<=n;i++)
            for(j=0;j<=W;j++)
            {
                if(j>=w[i])
                    a[i][j]=max(a[i-1][j],a[i-1][j-w[i]]+v[i]);
                else a[i][j]=a[i-1][j];
                printf("%3d ",a[i][j]);

            }
        printf("%d\n",a[n][W]);
    }
    return 0;
}
