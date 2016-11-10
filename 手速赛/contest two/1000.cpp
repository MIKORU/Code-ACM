#include<cstdio>
int main()
{
    int n,i;
    while(scanf("%d",&n)!=EOF)
    {
        int m=0,s=0,k;
        for(i=1; i<=n; i++)
        {
            scanf("%d",&k);
            if(k>1) s=1;
            if(!s) m++;
        }
        if(m%2==1&&s) printf("Bob\n");
        else if(m%2==0&&s) printf("Alice\n");
        else
        {
            if(n%2==0) printf("Bob\n");
            else printf("Alice\n");
        }

    }
    return 0;
}
