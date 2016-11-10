#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX_N = 1000005;
struct node{
 int s;
 int e;
 }a[MAX_N];
int cmp(node a, node b)
{
    if(a.s == b.s)
        return a.e < b.e;
    else
        return a.s < b.s;
}
int main()
{
    int n,T;

    while(scanf("%d",&n)!=EOF)
    {
        int ans = 0;
        scanf("%d",&T);
        for(int i=0;i<n;i++)
            scanf("%d%d",&a[i].s,&a[i].e);
        sort(a,a+n,cmp);
        int temp = 0;
        int i = 0;
        while(temp < T&& i<n)
        {
            ans++;
            int top = temp;
            if(a[i].s>temp+1)
            {
                printf("-1\n");
                return 0;
            }
            while(i<n&&a[i].s<=temp+1)
            {
                top = max(top,a[i].e);
                i++;
            }
            temp =  top;
        }
        if(temp < T )
            printf("-1\n");
        else printf("%d\n",ans);
    }
    return 0;
}
