#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>

#define INF 0x3f3f3f3f

int a[100005];

int main()
{
    int i,j,n,min,ok;
    while(scanf("%d",&n)==1)
    {
        min=INF;
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            if(min>a[i])
                min=a[i];
        }
        ok=1;
        for(i=0;i<n;i++)
        {
            if(a[i]%min!=0)
            {
                printf("-1\n");
                ok=0;
                break;
            }
        }
        if(ok)
            printf("%d\n",min);
    }
    return 0;
}
