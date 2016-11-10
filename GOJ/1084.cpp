#include <stdio.h>
#include <stdlib.h>
int x[15],N,sum;
int p(int k)
{
    int i;
    for( i=1;i<k;i++)
        if(x[i]==x[k]||abs(k-i)== abs(x[k]-x[i]))
            return 0;
     return 1;
}
void b(int k)
{
    int i;
     if(k>N)
        sum++;
     else
        for( i=1;i<=N;i++)
        {
              x[k]=i;
                if(p(k))
                    b(k+1);
        }
}
int main()
{
    int ans[15];
    for(N=1;N<=12;N++)
    {
        sum=0;
        b(1);
        ans[N]=sum;
    }
    while(scanf("%d",&N)!=EOF)
    {
        if(N==0)
            break;
        printf("%d\n",ans[N]);
    }
    return 0;
}
