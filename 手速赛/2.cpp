#include<stdio.h>
#include<string.h>
#define N 200000
int f[N],e[N];
int g(int a)
{
    if (f[a] == a) return a;
        else f[a] = g(f[a]);
    return f[a];
}

void u(int a,int b)
{
    f[g(b)] = g(a);
}
int main()
{
    int k;
    int m,n,i,b,a;
    char c;
    scanf("%d",&k);
    while (k--)
    {
        memset(e,0,sizeof(e));
        scanf("%d%d",&n,&m);
        for(i = 1;i <= n;i++)
            f[i] = i;
        for(i = 1;i <= m;i++)
        {
            getchar();
            scanf("%c%d%d",&c,&a,&b);
            if (c == 'D')
            {
                if (e[a]) u(e[a],b);
                if (e[b]) u(e[b],a);
                e[a] = b;
                e[b] = a;
            }
            else
            {
                if (g(a) == g(e[b])) printf("In different gangs.\n");
                else
                {
                    if (g(a) == g(b)) printf("In the same gang.\n");
                    else printf("Not sure yet.\n");
                }
            }
        }
    }
  return 0;
}
