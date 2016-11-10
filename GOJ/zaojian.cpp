#include <stdio.h>

int main()
{
    int t,n,j,i,k,u,v;
    int a[50],b[50];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(i = 0;i < n;i++)
        {
            scanf("%d%d",&a[i],&b[i]);
        }
        for(i = 0;i < n-1; i++)
        {
            for(j = 0;j < n-i-1;j++)
            {
                if(a[j]>a[j+1])
                {
                    v = a[j]; a[j] = a[j+1]; a[j+1] = v;
                    u = b[j]; b[j] = b[j+1]; b[j+1] = u;
                }
            }
        }
        for(i = 0;i < n;i++)
        {
            for(j = 0; j < b[i]; j++)
            {
                printf(">+");
                for(k = 0; k < a[i]-2; k++)
                {
                    printf("-");
                }
                printf("+>\n");
            }
            printf("\n");
        }
    }
    return 0;
}