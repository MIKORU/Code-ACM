#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h> // 取绝对值
#include <iostream>
#include <algorithm>
#include <stack>
#include <map>
#include <set>
#include <utility> //pair类
#define LL long long
using namespace std;
#define LL long long
#define CAN(a,b) memset(a,b,sizeof(a));
#define MAX_N 100005
#define MIN_N 1e-8
int n,k;
struct node
{
    int v,w,d;
    double y;

}a[MAX_N];
int cmp(node a,node b)
{
    return a.y>b.y;
}
bool cmp2(node a,node b)
{
    return a.d<b.d;
}
int main()
{
    while(scanf("%d%d",&n,&k)!=EOF)
    {

        for(int i=0;i<n;i++)
        {
            scanf("%d%d",&a[i].v,&a[i].w);
            a[i].y=0;
            a[i].d=i+1;
        }
        double p = 1,s = 0;
        while(fabs(s-p)>MIN_N)
        {
            for(int i=0;i<n;i++)
                a[i].y=a[i].v-s*a[i].w;
            sort(a,a+n,cmp);
            double V=0,W=0;
            for(int i=0;i<k;i++)
            {
                V+=a[i].v;W+=a[i].w;
            }
            p = s;
            s = V/W;
        }
        sort(a,a+k,cmp2);
        for(int i=0;i<k-1;i++)
            printf("%d ",a[i].d);
        printf("%d",a[k-1].d);
        printf("\n");
    }
    return 0;
}








