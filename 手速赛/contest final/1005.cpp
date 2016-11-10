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
int main()
{
//    freopen("00.txt","r",stdin);
//    freopen("01.txt","w",stdout);
    double n,m,a;
    while(scanf("%lf%lf%lf",&n,&m,&a)!=EOF)
    {
        double t,ans1,ans2;
        if((double)(44.0/100.0)*m > (double)(16.0/72.0)*n)
        {
            t =(double)(44.0/100.0)*m;
            ans1 =(double)(64.0/44.0)*t*160.0/32.0*160.0/80.0;
        }
        else
        {
            t=(double)(16.0/72.0)*n;
            ans1 = (double)(64.0/36.0)*t*160.0/32.0*160.0/80.0;
        }
        ans2 = (double)a*(double)160.0/(double)98.0;
        printf("%.2f\n",min(ans1,ans2));

    }
return 0;
}
