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
#define MAX_N 50005
using namespace std;
int a[MAX_N],n,m,q;
int main()
{
    int T,s=1;
    scanf("%d",&T);
    while(T--)
    {
        CAN(a,0);
        printf("Case #%d:\n",s++);
        scanf("%d%d%d",&n,&m,&q);
        for(int i=0;i<q;i++)
        {
            int t,l,j=0;
            scanf("%d%d",&t,&l);
            while(t<a[j]&&j<n)
                j++;
            if(j==n) printf("Failed!\n");
            else
            {
                a[j]=t+l+m;
                printf("%d\n",j+1);
            }
        }
    }
    return 0;
}
