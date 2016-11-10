#include <stdio.h>
#include <math.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <set>
#inlcude <map>
#include <stack>
#define N 100005
using namespace std;
int a[N],b[N],c[N*N];
int f(int x)
int main()
{
    int m,n,k,i,j;
    while(scanf("%d%d%d",&n,&m,&k)!=EOF)
    {
        k=m*n-k+1;
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);
        for(i=0;i<m;i++)
            scanf("%d",&b[i]);
        sort(a,a+n);
        sort(b,b+m);
        for(i=1;i<=m*n/2;i++)




    }
}
