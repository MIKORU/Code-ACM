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
#define MAX_N
LL a[1010];
string A[1010];
void add(char a[],char b[],char back[])
{
    int i,j,k,up,x,y,z,l;
    char *c;
    if(strlen(a) > strlen(b))
        l = strlen(a)+2;
    else
        l = strlen(b)+2;
    c = (char*)malloc(l*sizeof(char));
    i = strlen(a)-1;
    j = strlen(b)-1;
    k = 0;
    up = 0;
    while(j>=0 || i>=0)
    {
        if(i<0) x = '0';
        else
            x = a[i];
        if(j<0) y = '0';
        else
            y = b[j];
        z = x-'0'+y-'0';
        if(up)
            z++;
        if(z>9)
        {
            up = 1;
            z%=10;
        }
        else
            up = 0;
        c[k++] = z+'0';
        i--;
        j--;
    }
    if(up)
        c[k++] = '1';
    i = 0;
    c[k] = '\0';
    for(k-=1; k>=0; k--)
        back[i++] = c[k];
    back[i] = '\0';
}
int main()
{
    char c[1000],t[1000],sum[10000];
    LL n;
    int i;
    LL s;
    while(scanf("%lld",&n)!=EOF)
    {   LL ans=1;
        for(i=1;i<=n-1;i++)
        {
            ans*=2;
            s=ans;
        }
        if(n<=63) printf("%lld\n",ans);
        sprintf(c,t,"%lld",s);
        add(c,t,sum);
//        for(i=65;i<=1000;i++)
//        {
//            A[i]=add(A[i-1],A[i-1]);
//        }
//        printf("%s\n",A[n]);
    }
return 0;
}
