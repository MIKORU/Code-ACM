#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
const int maxn = 100005;
int p[maxn*10],y[maxn*100];
long long x[maxn*100];
int q,n,l,r,a,c,k,t;
int lowbit(int s)
{
    return s&(-s);
}
long long sum(int i)
{
    long long s=0;
    while(i>0){
        s += x[i];
        i -= lowbit(i);
    }
    return s;
}
void change(int i,int s)
{
    while(i<=n){
        x[i] += s;
        i += lowbit(i);
    }
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--){
        memset(p,0,sizeof(p));
        memset(x,0,sizeof(x));
        memset(y,0,sizeof(y));
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d",&p[i]);
            y[p[i]] = i;
        }
        for(int i=1;i<=n;i++){
            change(i,p[p[i]]);
        }
        scanf("%d",&q);
        while(q--){
            scanf("%d%d%d",&a,&l,&r);
            switch(a){
                case 1:
                    change(l,-p[p[l]]);
                    change(r,-p[p[r]]);

                    if(l != y[l] && r!= y[l])
                        change(y[l],-p[l]);
                    if(l != y[r] && r!= y[r])
                        change(y[r],-p[r]);

                    swap(p[l],p[r]);

                    change(l,p[p[l]]);
                    change(r,p[p[r]]);

                    if(l!=y[l]&&r!=y[l])
                        change(y[l],p[l]);
                    if(l!=y[r]&&r!=y[r])
                        change(y[r],p[r]);

                    y[p[r]] = r;
                    y[p[l]] = l;

                    break;
                case 2:

                    printf("%lld\n",sum(r)-sum(l-1));
                    break;
            }
        }
    }
    return 0;
}
