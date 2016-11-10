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
using namespace std;
#define MAX_N 1005
int a[MAX_N];
int main()
{
    int T,N,M,i,j,sum,m;
    scanf("%d",&T);
    while(T--)
    {
        m = 0;
        scanf("%d%d",&N,&M);
        for(i=1; i<=N; i++)
        {
            scanf("%d",&a[i]);
            a[N+i] = a[i];
        }
        for(i=1;i<=N;i++)
        {
            sum = 0;
            for(j=i;j<i+M;j++)
            {
                sum+=a[j];
                m=max(sum,m);
            }
        }
        printf("%d\n",m);
    }
    return 0;
}

